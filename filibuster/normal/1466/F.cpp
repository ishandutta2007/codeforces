#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 14;
const int M = 1e9 + 7;
const int N = 5e5 + 13;

int sum(int a, int b) {
    int res = a + b;
    if(res >= M)
        res -= M;
    return res;
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

/*
1
5
5 1 1 1 1
1 2
1 3
1 4
1 5
*/
int p[N], sz[N];
bool fl[N];

int getp(int x) {
    return (x == p[x] ? x : p[x] = getp(p[x]));
}

void unite(int x, int y) {
    x = getp(x);
    y = getp(y);

    if(x == y)
        return;

    if(sz[x] < sz[y])
        swap(x, y);

    sz[x] += sz[y];
    p[y] = x;
    if(fl[y])
        fl[x] = true;
}

vector<int> g[N];
vector<int> a[N];
int is[N];
bool used[N];
int pw[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        p[i] = i;
        sz[i] = 1;
        is[i] = -1;
    }

    pw[0] = 1;
    for(int i = 1; i < N; i++) {
        pw[i] = mul(pw[i - 1], 2);
    }


    vector<int> ans;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;

        a[i].resize(k);
        for(int j = 0; j < k; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
        sort(a[i].begin(), a[i].end());

        if(k == 2) {
            int v = a[i][0];
            int u = a[i][1];
            if((is[v] == -1 || is[u] == -1) && getp(v) != getp(u) && (!fl[getp(v)] || !fl[getp(u)])) {
                unite(v, u);
                ans.push_back(i);
                g[v].push_back(u);
                g[u].push_back(v);
            }
        } else {
            is[a[i][0]] = i;
            if(!fl[getp(a[i][0])]) {
                fl[getp(a[i][0])] = true;
                ans.push_back(i);
            }
        }
    }

    int res = 1;

    for(int i = 0; i < m; i++) {
        if(p[i] == i) {
            res = mul(res, pw[sz[i] - !fl[i]]);
        }
    }

    sort(ans.begin(), ans.end());

    cout << res << ' ' << ans.size() << endl;
    for(auto x : ans)
        cout << x + 1 << ' ';
    cout << endl;
}