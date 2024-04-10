#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int w[4][2] = {{1, 0},{0, 1}, {-1, 0}, {0, -1}};
struct Pnode{
    int x, y;
} st, ed;
char s[1005][1005];
int n, cnt, m, f[1005][1005];

void bfs(Pnode st){
    queue <Pnode> q;
    q.push(st);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        f[i][j] = 1e9;
    f[st.x][st.y] = 0;
    while (!q.empty()){
        Pnode now = q.front(); q.pop();
        for (int k = 0; k < 4; k++){
            Pnode t;
            t.x = now.x + w[k][0];
            t.y = now.y + w[k][1];
            if (t.x <= 0 || t.x > n || t.y <= 0 || t.y > m || s[t.x][t.y] == 'T') continue;
            if (f[t.x][t.y]  == 1e9){
                f[t.x][t.y] = f[now.x][now.y] + 1;
                q.push(t);
            }
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    if (s[i][j] == 'S'){
        st.x = i; st.y = j;
    }else if (s[i][j] == 'E'){
        ed.x = i; ed.y = j;
    }
    bfs(ed);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    if (s[i][j] > '0' && s[i][j] <= '9' && f[i][j] <= f[st.x][st.y]) ans+=s[i][j] -'0';
    printf("%d\n", ans);
}