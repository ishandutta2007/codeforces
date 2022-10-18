#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m,k,x,y,ans[1005][1005];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
char s[1005][1005],u[1005][1005];
queue< pii > q;
vector< pii > component;

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 0; i < n; ++i) {
        scanf("%s",s[i+1]+1);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '*' || u[i][j]) continue;
            q.push(make_pair(j, i));
            int cur = 0;
            while (q.size()) {
                int curx = q.front().first;
                int cury = q.front().second;
                q.pop();
                if (curx <= 0 || cury <= 0 || curx > m || cury > n) continue;
                if (u[cury][curx]) continue;
                if (s[cury][curx] == '*') continue;
                u[cury][curx] = 1;
                component.push_back(make_pair(curx, cury));
                for (int z = 0; z < 4; ++z) {
                    cur += s[cury + dy[z]][curx + dx[z]] == '*';
                    q.push(make_pair(curx + dx[z], cury + dy[z]));
                }
            }
            for (int z = 0; z < component.size(); ++z)
                ans[component[z].second][component[z].first] = cur;
            component.clear();
        }
    }

    while (k--) {
        scanf("%d%d",&x,&y);
        printf("%d\n",ans[x][y]);
    }

    return 0;
}