#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long double ld;
typedef long long ll;

int n,m,d[55][55];
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
char s[55][55];

void yes() { puts("Yes"); exit(0); }

void dfs(int x, int y, int c) {
    if (d[y][x]) {
        if (c - d[y][x] >= 4) yes();
        return;
    }
    d[y][x] = c++;
    for (int i = 0; i < 4; ++i)
        if (s[y+dy[i]][x+dx[i]] == s[y][x])
            dfs(x+dx[i], y+dy[i], c);
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i)
        scanf("%s",s[i+1]+1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int y = 0; y < n; ++y)
                for (int x = 0; x < m; ++x)
                    d[y+1][x+1] = 0;
            dfs(j+1, i+1, 1);
        }
    }
    puts("No");

    return 0;
}