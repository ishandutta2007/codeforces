#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)
#define REPN(i, a, b) for(int i = a; i >= b; i--)
typedef long long int ll;

const int maxn = 500100;
const int dod = 500010;

int n;
string s;

bool z;
bool dz;

int kol [2 * maxn];

int rj = 0;

int main()
{
    cin >> n;
    REP(i, 0, n)
    {
        cin >> s;
        z = 0;
        dz = 0;
        int suma = 0;
        REP(j, 0, (int)s.size())
        {
            if(s[j] == '(')
            {
                suma += 1;
            }
            else
            {
                suma -= 1;
            }
            if(suma < 0)
            {
                z = 1;
            }
        }
        suma = 0;
        REPN(j, s.size() - 1, 0)
        {
            if(s[j] == '(')
            {
                suma += 1;
            }
            else
            {
                suma -= 1;
            }
            if(suma > 0)
            {
                dz = 1;
            }
        }
        if(z && dz) continue;
        kol[suma + dod] = kol[suma + dod] + 1;
    }
    REP(i, 0, 2 * maxn)
    {
        while(kol[i])
        {
            int tr = i - dod;
            kol[i]--;
            tr = tr * -1;
            tr += dod;
            if(kol[tr])
            {
                rj++;
                kol[tr]--;
            }
        }
    }
    cout << rj << endl;
    return 0;
}