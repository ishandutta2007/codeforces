#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <map>


using namespace std;


int n, m;
vector<int> v[3001];
int d[3001][3001];
vector<pair<int, int> > s[3001];
vector<pair<int, int> > s1[3001];
queue<int> q;


void bfs(int u) {
    for (int i = 0; i < n; i++) {
        d[u][i] = 1000000000;
    }
    q.push(u);
    d[u][u] = 0;
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (int i = 0; i < (int)v[a].size(); i++) {
            int b = v[a][i];
            if (d[u][b] == 1000000000) {
                d[u][b] = d[u][a] + 1;
                q.push(b);
            }
        }
    }
}



int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        v[a].push_back(b);
    }
    for (int i = 0; i < n; i++) {
        bfs(i);
    }
    for (int i = 0; i < n; i++) {
         vector<pair<int, int> > g;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (d[i][j] != 1000000000) {
                    g.push_back(make_pair(-d[i][j], j));
                }
            }
        }
        if ((int)g.size() > 4) {
            nth_element(g.begin(), g.begin() + 3, g.end());
            g.resize(4);
        }
        s[i] = g;
    }
    for (int i = 0; i < n; i++) {
        vector<pair<int, int> > g;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (d[j][i] != 1000000000) {
                    g.push_back(make_pair(-d[j][i], j));
                }
            }
        }
        if ((int)g.size() > 4) {
            nth_element(g.begin(), g.begin() + 3, g.end());
            g.resize(4);
        }
        s1[i] = g;
    }
    int al = 0, bl = 1, cl = 2, dl = 3;
    int ans = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && d[i][j] != 1000000000) {
                for (int t = 0; t < (int)s1[i].size(); t++) {
                    for (int t1 = 0; t1 < (int)s[j].size(); t1++) {
                        int a = s1[i][t].second;
                        int b = s[j][t1].second;
                        if (a != j && a != b && b != i) {
                            ans = max(ans, d[a][i] + d[i][j] + d[j][b]);
                            if (ans == d[a][i] + d[i][j] + d[j][b]) {
                                al = a + 1;
                                bl = i + 1;
                                cl = j + 1;
                                dl = b + 1;
                            }
                        }
                    }
                }
            }
        }
    }
   // cout << ans << endl;
    cout << al << ' ' << bl << ' ' << cl << ' ' << dl << endl;
    return 0;
}