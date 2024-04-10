#include <ctime>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
using namespace std;
const int N = 1e5;
int n;
vector<int>g[2];
bool vis[N][2], is_win[N][2];
int deg[N][2];
queue<pair<int, bool> >q;
int main() {
    scanf("%d", &n);
    int k;
    scanf("%d", &k);
    while (k -- ){
        int x;
        scanf("%d", &x);
        g[0].push_back(x);
    }
    scanf("%d", &k);
    while (k -- ){
        int x;
        scanf("%d", &x);
        g[1].push_back(x);
    }
    for (int i = 1; i < n; i ++)
        deg[i][0] = g[0].size(), deg[i][1] = g[1].size();
    q.push(make_pair(n, 0));
    q.push(make_pair(n, 1));
    while (!q.empty()) {
        pair<int, bool> u = q.front();
        q.pop();
        for (auto v: g[!u.second])
        {
            int x = (u.first - v + n) % n;
            if (!x) continue;
            if (!is_win[u.first][u.second] && !vis[x][!u.second]) {
                is_win[x][!u.second] = 1;
                q.push(make_pair(x, !u.second));
                vis[x][!u.second] = 1;
            }  else
                if (!(--deg[x][!u.second]) && !vis[x][!u.second])
                    q.push(make_pair(x, !u.second)),vis[x][!u.second] = 1;
        }
    }
    for (int sig = 0; sig < 2; sig ++) {
        for (int i = 1; i <n; i++)
        {
            if (is_win[i][sig])
                printf("Win ");
            else
                if (vis[i][sig])
                    printf("Lose ");
                else
                    printf("Loop ");
        }
        printf("\n");
    }
    return 0;
}