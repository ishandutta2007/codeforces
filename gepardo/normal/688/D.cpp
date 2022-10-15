/*-------------------( alex256 )--------------------\
|    Contest: Codeforces Round 360 (Div. 2)         |
|       Task: B                                     |
|       Date: 29. 06. 2016                          |
\--------------------------------------------------*/
#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back

using namespace std;

vector <int> divisors(int n)
{
    vector <int> v;
    int i = 2;
    while (i * i <= n)
        if (n % i == 0)
        {
            n /= i;
            v.pb(i);
        }
        else i++;
    if (n != 1) v.pb(n);
    return v;
}

const int maxN = (int)2e6;
int divs[maxN] = {};
int pDiv[maxN] = {};
int wDiv[maxN] = {};

main()
{
    int n, k; scanf("%d%d", &n, &k);
    vector <int> v(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    vector <int> d = divisors(k);
    vector <int> q;
    for (int i = 0; i < d.size(); i++)
    {
        if (i == 0 || d[i] != d[i-1]) q.pb(d[i]);
        divs[d[i]]++;
    }
    int qSz = q.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < qSz; j++) pDiv[q[j]] = 0;
        int num = v[i];
        for (int j = 0; j < qSz; j++)
            while (num % q[j] == 0)
                num /= q[j],
                pDiv[q[j]]++;
        for (int j = 0; j < qSz; j++) wDiv[q[j]] = max(wDiv[q[j]], pDiv[q[j]]);
    }
    for (int i = 0; i < qSz; i++)
        if (wDiv[q[i]] < divs[q[i]])
        {
            printf("No");
            return 0;
        }
    printf("Yes");
    return 0;
}