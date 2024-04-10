#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,m,q,xa,ya,xb,yb;
int cnt[505][505];
char s[505][505];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i)
        scanf("%s", s[i+1]+1);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int cur = 0;
            cur += (s[i][j] == '.' && s[i][j+1] == '.');
            cur += (s[i][j] == '.' && s[i][j-1] == '.');
            cur += (s[i][j] == '.' && s[i+1][j] == '.');
            cur += (s[i][j] == '.' && s[i-1][j] == '.');
            cnt[i][j] = cnt[i][j-1] + cnt[i-1][j] - cnt[i-1][j-1] + cur;
        }
    }

    scanf("%d",&q);
    while (q--) {
        scanf("%d%d%d%d",&ya,&xa,&yb,&xb);
        int ans = cnt[yb][xb] - cnt[yb][xa - 1] - cnt[ya - 1][xb] + cnt[ya - 1][xa - 1];
        for (int i = xa; i <= xb; ++i) {
            if (s[ya][i] == '.' && s[ya-1][i] == '.') --ans;
            if (s[yb][i] == '.' && s[yb+1][i] == '.') --ans;
        }
        for (int i = ya; i <= yb; ++i) {
            if (s[i][xa] == '.' && s[i][xa-1] == '.') --ans;
            if (s[i][xb] == '.' && s[i][xb+1] == '.') --ans;
        }
        printf("%d\n",ans / 2);
    }

    return 0;
}