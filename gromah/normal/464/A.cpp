#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000 + 5

int n, p, A[N];
char s[N];

inline void dfs(int z, int last)
{
    if (!z)
    {
        A[0] = 1;
        return ;
    }   
    if (z > n)
    {
        A[0] = -1;
        return ;
    }
    for (int i = last + 1; i < p; i ++)
        if (z == 1 || (i != A[z - 1] && (z == 2 || i != A[z - 2])))
        {
            A[z] = i;
            dfs(z + 1, -1);
            if (A[0] != 0) return ;
        }
    dfs(z - 1, A[z - 1]);
}

int main()
{
    scanf("%d%d", &n, &p);
    scanf("%s", s);
    for (int i = 1; i <= n; i ++)
        A[i] = s[i - 1] - 'a';
    dfs(n, A[n]);
    if (A[0] == 1) puts("NO");
    else for (int i = 1; i <= n; i ++)
        printf("%c", A[i] + 'a');
    return 0;
}