// Codeforces Beta Round #5
// Problem E -- Bindian Signalizing
#include <cstdio>
#include <cstring>

#define maxN 1000000

using namespace std;

int n, h[maxN], hh[maxN], s[maxN], c[maxN];
bool v[maxN];

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++ i)
        scanf("%d", hh + i);
    int m = 0;
    for(int i = 1; i < n; ++ i)
        if(hh[i] > hh[m])
            m = i;
    for(int i = 0; i < n; ++ i)
        h[i] = hh[(m + i) % n];
    int t = 0; long long a = 0;
    for(int i = 1; i < n; ++ i)
    {
        while(t > 0 && s[t - 1] < h[i])
            a += c[-- t];
        if(t > 0)
        {
            if(s[t - 1] == h[i])
            {
                a += c[t - 1], c[t - 1] ++;
                if(t > 1)
                    a ++;
            }
            else
                a ++, s[t] = h[i], c[t] = 1, t ++;
        }
        else
            s[t] = h[i], c[t] = 1, t ++;
    }
    memset(v, 0, sizeof(v));
    m = 0;
    for(int i = 1; i < n; ++ i)
        v[i] |= (m <= h[i]), m = (m < h[i])? h[i]: m;
    m = 0;
    for(int i = n - 1; i > 0; -- i)
        v[i] |= (m <= h[i]), m = (m < h[i])? h[i]: m;
    for(int i = 1; i < n; ++ i)
        if(v[i])
            a ++;
    printf("%I64d\n", a);
    return 0;
}