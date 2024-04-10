#include <bits/stdc++.h>
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N = 1e6 + 5;
vector<int> v[N];
int vis[N], T, vis2[N], T2;
int pre[N], pre2[N];
queue<int> q;
vector<int> ans1, ans2;
int ansT;
int SS;
int over = 0;
void bfs() {
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int to : v[x]) {
            if (vis[to] != T) {
                pre[to] = x;
                q.push(to);
                vis[to] = T;
            }
        }
    }
}
void bfs2() {
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int to : v[x]) {
            if (vis[to] == T) {
                if (!over and to != SS) {
                    over = 1;
                    ansT = to;
                    int cur = to;
                    while (cur != SS) {
                        ans1.push_back(cur);
                        cur = pre[cur];
                    }
                    ans1.push_back(SS);
                    cur = x;
                    ans2.push_back(to);
                    while (cur != SS) {
                        ans2.push_back(cur);
                        cur = pre2[cur];
                    }
                    ans2.push_back(SS);
                    int no = 0;
                    if (ans1.size() < 2 or ans2.size() < 2) {
                        no = 1;
                    }
                    map<int, int> mp;
                    for (int x : ans1) mp[x] = 1;
                    for (int i = 1; i < (int)ans2.size() - 1; i += 1) {
                        if (mp[ans2[i]]) no = 1;
                    }
                    if (ans1[0] != ans2[0]) no = 1;
                    if (ans1.back() != ans2.back()) no = 1;
                    if (no) {
                        over = 0;
                        ans1.clear();
                        ans2.clear();
                    }

                    // ok
                }
            }
            else {
                if (vis2[to] != T2) {
                    pre2[to] = x;
                    q.push(to);
                    vis2[to] = T2;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n, m, s;
    cin >> n >> m >> s;
    SS = s;
    for (int i = 1; i <= m; i += 1) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
    }
    for (int i = 0; i < 20; i += 1) {
        for (int j = 0; j < 2; j += 1) {
            T += 1;
            T2 += 1;
            for (int to : v[s]) {
                if (((to >> i) & 1) == j) {
                    q.push(to);
                    pre[to] = s;
                    vis[to] = T;
                }
            }
            vis[s] = T;
            bfs();
            for (int to : v[s]) {
                if (((to >> i) & 1) != j) {
                    q.push(to);
                    pre2[to] = s;
                    vis2[to] = T2;
                }
            }
            vis2[s] = T2;
            bfs2();
            if (over) {
                cout << "Possible\n";
                reverse(ans1.begin(), ans1.end());
                cout << ans1.size() << '\n';
                for (auto x : ans1) {
                    cout << x << ' ';
                }
                cout << '\n';

                reverse(ans2.begin(), ans2.end());
                cout << ans2.size() << '\n';
                for (auto x : ans2) {
                    cout << x << ' ';
                }
                cout << '\n';
                return 0;
            }
        }

    }
    cout << "Impossible\n";
}
/*


*/