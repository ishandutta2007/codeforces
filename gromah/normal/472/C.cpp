#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int n, A[N];
char s[N][2][99];

inline bool Small(char *S, char *T)
{
    int lens = strlen(S), lent = strlen(T);
    int minl = min(lens, lent);
    for (int i = 0; i < minl; i ++)
    {
        if (S[i] < T[i])
            return 1;
        else if (S[i] > T[i])
            return 0;
    }
    return lens < lent;
}

inline void Swap(char *S, char *T)
{
    int lens = strlen(S), lent = strlen(T);
    for (int i = 0; i < lens || i < lent; i ++)
        swap(S[i], T[i]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%s%s", s[i][0], s[i][1]);
        if (Small(s[i][1], s[i][0]))
            Swap(s[i][0], s[i][1]);
    }
    for (int i = 1; i <= n; i ++)
        scanf("%d", A + i);
    
    int u = 0;
    bool ok = 1;
    for (int i = 1; i <= n && ok; i ++)
    {
        if (i == 1)
            u = 0;
        else
        {
            if (Small(s[A[i - 1]][u], s[A[i]][0]))
                u = 0;
            else if (Small(s[A[i - 1]][u], s[A[i]][1]))
                u = 1;
            else ok = 0;
        }
    }
    
    puts(ok ? "YES" : "NO");
    
    return 0;
}