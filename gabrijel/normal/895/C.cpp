#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int mod = 1e9 + 7;
long long int lo;
int n, x, mas;
int br [100];
int es [100];
int pf [100];
int pot [100100];
//int bio [1100000] [75];
int dp [1100000] [3];
vector <int> prosti;

void rek (int tr, int koji)
{
    if (es [tr] == tr) pf [koji] ^= 1<<(lower_bound(prosti.begin(), prosti.end(), tr) - prosti.begin());
    else
    {
        pf [koji] ^= 1<<(lower_bound(prosti.begin(), prosti.end(), es [tr]) - prosti.begin());
        rek (tr / es [tr], koji);
    }
}

/*int rij (int broj, int mask)
{
    if (bio [mask] [broj] != -1) return bio [mask] [broj];
    if (broj == 71)
    {
        if (mask == 0) return 1;
        else return 0;
    }
    if (br [broj] == 0) return rij (broj + 1, mask);
    long long int ret = 0;
    //if (mask == 0 && broj != 1) ret = 1;
    ret += (long long) rij (broj + 1, mask ^ pf [broj]) * pot [br [broj] - 1];
    ret %= mod;
    ret += (long long) rij (broj + 1, mask) * pot [br [broj] - 1];
    ret %= mod;
    bio [mask] [broj] = ret;
    return ret;
}*/

int main()
{
    pot [0] = 1;
    for (int p = 1; p < 1e5 + 5; p++)
    {
        pot [p] = ((long long) pot [p - 1] * 2) % mod;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        br [x]++;
    }
    memset (es, -1, sizeof es);
    //memset (bio, -1, sizeof bio);
    for (int j = 2; j < 100; j++)
    {
        if (es [j] == -1)
        {
            for (int k = j; k < 100; k += j)
            {
                es [k] = j;
            }
        }
    }
    for (int pro = 2; pro < 75; pro++)
    {
        if (es [pro] == pro) prosti.push_back(pro);
    }
    for (int l = 2; l < 75; l++)
    {
        rek (l, l);
    }
    //printf ("%d", rij (1, 0) - 1);
    dp [0] [0] = 1;
    for (int broj = 1; broj < 71; broj++)
    {
        if (br [broj] == 0) continue;
        for (int mask = 0; mask < (1<<19); mask++)
        {
            lo = (long long) dp [mask] [0] * pot [br [broj] - 1];
            if (lo > mod) lo %= mod;
            dp [mask] [1] = lo;
            dp [mask ^ (pf [broj])] [2] = lo;
        }
        for (int dodaj = 0; dodaj < (1<<19); dodaj++)
        {
            lo = dp [dodaj] [1] + dp [dodaj] [2];
            if (lo > mod) lo %= mod;
            dp [dodaj] [0] = lo;
        }
    }
    printf("%d", dp [0] [0] - 1);
    return 0;
}