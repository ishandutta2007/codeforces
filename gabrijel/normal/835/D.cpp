#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
int baza1 [5100];
int baza2 [5100];
int h1 [5100];
int h2 [5100];
string s;
bool pali [5100] [5100];
int dp [5100] [5100];
int rj [5100];
int rje = 0;
vector <int> isp;

inline int add (int a, int b, int mod)
{
    a += b;
    if (a > mod) a -= mod;
    if (a < 0) a += mod;
    return a;
}

inline int mult (int a, int b, int mod)
{
    return (long long) a * b % mod;
}

inline int f1 (int x, int y)
{
    if (x == 0) return h1 [x + y];
    return add(h1 [x + y], -mult(h1 [x - 1], baza1 [y + 1], mod1), mod1);
}

inline int f2 (int x, int y)
{
    if (x == 0) return h2 [x + y];
    return add(h2 [x + y], -mult(h2 [x - 1], baza2 [y + 1], mod2), mod2);
}

int main()
{
    baza1 [0] = 1;
    baza2 [0] = 1;
    for (int pos = 1; pos < 5010; pos++)
    {
        baza1 [pos] = (long long) baza1 [pos - 1] * 1337 % mod1;
        baza2 [pos] = (long long) baza2 [pos - 1] * 10007 % mod2;
    }
    cin >> s;



    for (int poc1 = 0; poc1 < s.size(); poc1++) pali [poc1] [poc1] = 1;
    for (int poc2 = 0; poc2 < s.size() - 1; poc2++) if (s [poc2] == s [poc2 + 1]) pali [poc2] [poc2 + 1] = 1;
    for (int pali1 = 2; pali1 < s.size(); pali1++)
    {
        for (int pali2 = 0; pali2 < s.size() - pali1; pali2++)
        {
            if (s [pali2] == s [pali2 + pali1] && pali [pali2 + 1] [pali2 + pali1 - 1]) pali [pali2] [pali2 + pali1] = 1;
        }
    }


    h1 [0] = s [0];
    h2 [0] = s [0];
    for (int ha = 1; ha < s.size(); ha++)
    {
        h1 [ha] = add(mult(h1 [ha - 1], baza1 [1], mod1), s [ha], mod1);
        h2 [ha] = add(mult(h2 [ha - 1], baza2 [1], mod2), s [ha], mod2);
    }

    for (int poc = 0; poc < s.size(); poc++) {dp [poc] [poc] = 1; rj [1]++;}

    for (int i = 1; i < s.size(); i++)
    {
        for (int j = 0; j < s.size() - i; j++)
        {
            int mid = (i - 1) / 2;
            if (dp [j] [j + mid] && dp [j + i - mid] [j + i] && f1 (j, mid) == f1 (j + i - mid, mid) && f2 (j, mid) == f2 (j + i - mid, mid))
            {
                dp [j] [j + i] = dp [j] [j + mid] + 1;
                rj [dp [j] [j + i]]++;
            }
            else if (pali [j] [j + i])  {dp [j] [j + i] = 1; rj [1]++;}
        }
    }

    for (int k = s.size(); k > 0; k--)
    {
        rj [k] += rje;
        isp.push_back(rj [k]);
        rje = rj [k];
    }

    reverse(isp.begin(), isp.end());
    for (int l = 0; l < isp.size(); l++) printf("%d ", isp [l]);

    return 0;
}