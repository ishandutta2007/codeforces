#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int M = 1e9 + 7;
const int N = 1000 + 13;

int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, 1};

int n, m;
li k;

bool isin(int i, int j) {
    return (0 <= i && i < n && 0 <= j && j < m);
}

pii p[N][N];
int sz[N][N];

pii getp(pii x) {
    return (x == p[x.f][x.s] ? x : p[x.f][x.s] = getp(p[x.f][x.s]));
}

pii getp(int x, int y) {
    return (make_pair(x, y) == p[x][y] ? p[x][y] : p[x][y] = getp(p[x][y]));
}

void unit(pii x, pii y) {
    x = getp(x);
    y = getp(y);

    if(x == y)
        return;

    if(sz[x.f][x.s] < sz[y.f][y.s])
        swap(x, y);

    p[y.f][y.s] = x;
    sz[x.f][x.s] += sz[y.f][y.s];
}

int a[N][N];
int res[N][N];

bool used[N][N];
int cnt = 0;

void dfs(int i, int j, int x) {
    used[i][j] = true;
    cnt++;

    for(int l = 0; l < 4; l++) {
        int i1 = i + di[l];
        int j1 = j + dj[l];

        if(!isin(i1, j1) || a[i1][j1] < x || used[i1][j1] || cnt >= k / x) {
            continue;
        }

        dfs(i1, j1, x);
    }
}

int main() {

    cin >> n >> m >> k;

    map<int, vector<pii>> mp;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            mp[-a[i][j]].emplace_back(i, j);
        }
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            sz[i][j] = 1;
            p[i][j] = {i, j};
        }

    for(auto pp : mp) {
        for(auto x : pp.s) {
            int i = x.f, j = x.s;
            for(int l = 0; l < 4; l++) {
                int i1 = i + di[l];
                int j1 = j + dj[l];

                if(!isin(i1, j1) || a[i1][j1] < a[i][j])
                    continue;

                unit(x, {i1, j1});
            }
        }

        for(auto x : pp.s) {
            res[x.f][x.s] = sz[getp(x).f][getp(x).s];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
//            cout << i << ' ' << j << ' ' << res[i][j] << endl;
            if(k % a[i][j] == 0 && k / a[i][j] <= res[i][j]) {
                dfs(i, j, a[i][j]);
                cout << "YES" << endl;
                for(int i1 = 0; i1 < n; i1++) {
                    for(int j1 = 0; j1 < m; j1++) {
                        cout << (used[i1][j1] ? a[i][j] : 0) << ' ';
                    }
                    cout << endl;
                }
                return 0;
            }
        }
    }

    cout << "NO" << endl;
}