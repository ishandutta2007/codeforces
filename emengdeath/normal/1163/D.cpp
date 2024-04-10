#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
#include <cstring>
using namespace std;

const int N = 60;
struct KMP
{
    char s[N];
    int Next[N], n;
    void getNext(){
        n = strlen(s);
        Next[0] = 0;
        for (int i=1, j = 0 ;i<n;i++){
            while (j && s[i] != s[j]) j = Next[j - 1];
            if (s[i] == s[j]) j ++;
            Next[i] = j;
        }
    }
    int match(int x, char c)
    {
        while (x && s[x] != c) x = Next[x - 1];
        if (!x && s[x] == c) return x + 1;
        if (s[x] == c) return x + 1;
        return 0;
    }
}s, t;
char c[N * N];
int f[N*N][N][N];
int main()
{
    scanf("%s", c + 1);
    scanf("%s", s.s);
    scanf("%s", t.s);
    s.getNext();
    t.getNext();
    int n = strlen(c + 1);
    for (int i = 0; i <= n ; i++ )
        for (int j = 0; j <= s.n; j ++)
            for (int k = 0; k <= t.n; k ++)
                f[i][j][k] = -1e9;
    f[0][0][0] = 0;
    for (int i = 0; i < n ; i++ )
        for (int j = 0; j <= s.n; j ++)
            for (int k = 0; k <= t.n; k++)
            if (f[i][j][k] != -1e9)
            {
                int l = 'a';
                int r = 'z';
                if (c[i + 1] != '*') l = r = c[i + 1];
                while (l <= r)
                {
                    int jj = s.match(j, l);
                    int kk = t.match(k, l);
                    int v  =f[i][j][k];
                    if (jj == s.n) v++;
                    if (kk == t.n) v--;
                    f[i + 1][jj][kk] = max(f[i + 1][jj][kk], v);
                    l ++;
                }
            }
    int ans = -1e9;
    for (int i = 0; i <= s.n; i ++)
        for (int j = 0; j <= t.n; j ++)
            ans = max(f[n][i][j], ans);
    printf("%d", ans);
}