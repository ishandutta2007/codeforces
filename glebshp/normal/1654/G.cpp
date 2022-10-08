#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int maxn = 200 * 1000 + 100;
const int magic = 350;
const int inf = 1000 * 1000 * 1000;

int n;
int best;
int l[maxn];

vector <int> vertex[maxn];
int h[maxn];
int ans[maxn][magic + 1];
bool cool[maxn];
int runsto[maxn];
int tmp[maxn];
int tmpg[maxn];
vector <int> large[maxn];
int largelst[maxn];

void bfs() {
    for (int i = 0; i < n; i++) {
        h[i] = -1;
    }
    queue <int> q;
    for (int i = 0; i < n; i++) {
        if (l[i] == 1) {
            h[i] = 0;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : vertex[v]) {
            if (h[u] == -1) {
                h[u] = h[v] + 1;
                q.push(u);
            }
        }
    }
}

void precalcSmall() {
    vector <pair <int, int> > vh;
    for (int i = 0; i < n; i++) {
        vh.pb(mp(h[i], i));
    }
    sort(vh.begin(), vh.end());
    int i = 0;
    int j = 0;
    while (i < n) {
        while (j < n && vh[j].fs == vh[i].fs) {
            j++;
        }
        for (int b = 0; b < magic - vh[i].fs; b++) {
            for (int k = i; k < j; k++) {
                int v = vh[k].sc;
                for (auto u : vertex[v]) {
                    if (h[u] < h[v]) {
                        ans[v][b] = max(ans[v][b], ans[u][b + 1] + 1);
                    }
                    if (h[u] == h[v] && b > 0) {
                        ans[v][b] = max(ans[v][b], ans[u][b - 1] + 1);
                    }
                }
            }
        }
        i = j;
    }
}

void go(int v, int from, int b, int minb, int d) {
    best = max(best, -minb);
    tmp[-minb] = max(tmp[-minb], d);
    if (cool[v]) {
        tmpg[-minb] = max(tmpg[-minb], d + b - minb + h[v]);
    }

    for (auto u : vertex[v]) {
        if (u == from) {
            continue;
        }
        if (h[u] < h[v]) {
            go(u, v, b + 1, minb, d + 1);
        }
        if (h[u] == h[v]) {
            go(u, v, b - 1, min(minb, b - 1), d + 1);
        }
    }
}

void precalcOne(int v) {
    for (int i = 0; i < n; i++) {
        tmp[i] = 0;
        tmpg[i] = -inf;
    }
    best = 0;
    go(v, -1, 0, 0, 0);

    for (int i = 1; i <= best; i++) {
        tmp[i] = max(tmp[i - 1], tmp[i]);
    }
    for (int i = 1; i <= best; i++) {
        tmpg[i] = max(tmpg[i - 1] + 1, tmpg[i]);
    }
    large[v].reserve(best + 1);
    for (int i = 0; i <= best; i++) {
        large[v].pb(max(tmp[i], tmpg[i]));
    }
    largelst[v] = tmpg[best];
}

void precalcLarge() {
    vector <pair <int, int> > vh;
    for (int i = 0; i < n; i++) {
        vh.pb(mp(h[i], i));
    }
    sort(vh.begin(), vh.end());

    for (int i = 0; i < n; i++) {
        int v = vh[i].sc;
        runsto[v] = -1;
        int cnt = 0;
        if (h[v] > 0 && !cool[v]) {
            for (auto u : vertex[v]) {
                if (h[u] + 1 == h[v]) {
                    if (runsto[u] == -1) {
                        runsto[v] = u;
                    } else {
                        runsto[v] = runsto[u];
                    }
                    cnt++;
                }
            } 
        }
        if (cnt > 1) {
            runsto[v] = -1;
        }
    }        

    set <int> tpc;
    for (int i = 0; i < n; i++) {
        if (h[i] >= magic) {
            if (cool[i] || runsto[i] == -1) {
                tpc.insert(i);
            }
            if (!cool[i] && runsto[i] != -1) {
                tpc.insert(runsto[i]);
            }   
        } 
    }

//    assert(tpc.size() <= 500);
    for (auto v : tpc) {
//    for (int v = 0; v < n; v++) {
        precalcOne(v);
    }
}


int main() {
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        
        vertex[u].pb(v);
        vertex[v].pb(u);
    }

    bfs();

    for (int i = 0; i < n; i++) {
        cool[i] = false;
        for (auto u : vertex[i]) {
            if (h[u] == h[i]) {
                cool[i] = true;
            }
        }
    }

    precalcSmall();
    precalcLarge();

  //  for (int i = 0; i < n; i++) {
  //      cerr << i << ' ' << runsto[i] << endl;
  //  }

    for (int i = 0; i < n; i++) {
        if (h[i] < magic) {
            printf("%d ", ans[i][0]);
        }
        if (h[i] >= magic) {
            if (cool[i] || runsto[i] == -1) {
                printf("%d ", large[i][0]);
            } else {
                if (h[i] - h[runsto[i]] <= (int) large[runsto[i]].size() - 1) {
                    printf("%d ", large[runsto[i]][h[i] - h[runsto[i]]] + h[i] - h[runsto[i]]);
                } else {
                    printf("%d ", max(large[runsto[i]].back(), largelst[runsto[i]] + h[i] - h[runsto[i]] - (int) large[runsto[i]].size() + 1) + h[i] - h[runsto[i]]);
                }
            }
        }
    }
    printf("\n");

    return 0;
}