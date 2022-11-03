#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);

    if(k & 1)
        return pw * 1ll * pw % M * n % M;
    else
        return pw * 1ll * pw % M;
}

/*

*/

int g[N];
int used[N];
int d[N];
//int s[N];
vector<int> c;

void dfs(int v, int deep) {
    used[v] = 1;
    d[v] = deep;

//    cout << v << ' ' << d[v] << endl;

    if(used[g[v]] == 0) {
        dfs(g[v], deep + 1);
    } else if(used[g[v]] == 1) {
        c.push_back(d[v] - d[g[v]] + 1);
//        cout << "sajg " << d[v] << ' ' << d[g[v]] << endl;
    }

    used[v] = 2;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> g[i];
        g[i]--;
    }

    for(int i = 0; i < n; i++) {
        if(used[i] == 0) {
            dfs(i, 0);
        }
    }

    int m = n;
    int ans = 1;
    for(auto x : c) {
//        cout << x << endl;
        m -= x;
        ans = ans * 1ll * (pow2(2, x) - 2 + M) % M;
    }

    ans = ans * 1ll * pow2(2, m) % M;

    cout << ans << endl;
}