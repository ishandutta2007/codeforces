#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = (1<<22)+5, K = 23;
int a[N];
bool v[N][K], p[N];
vector<int> stk;

void dfs(int i, int k) {
    v[i][k] = 1;
    if (k == 22) {
        if (p[i]) stk.pb(i);
        return;
    }
    if (!v[i^(1<<k)][k+1])
        dfs(i^(1<<k), k+1);
    if ((i&(1<<k)) == 0 && !v[i][k+1])
        dfs(i, k+1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> a[i], p[a[i]] = 1;
    int r = 0;
    for (int i = 0; i < m; i++) {
        if (!v[a[i]][22]) {
            r++;
            stk.pb(a[i]);
            while (!stk.empty()) {
                int j = stk.back(); stk.pop_back();
                dfs(j, 0);
            }
        }
    }
    cout << r << "\n";
}