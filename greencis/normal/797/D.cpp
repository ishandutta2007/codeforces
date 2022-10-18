#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, ans, a[100105], l[100105], r[100105], u[100105];
set<int> s;

void dfs(int v, int L, int R) {
    if (v > 0) {
        if (L <= a[v] && a[v] <= R)
            s.insert(a[v]);
        dfs(l[v], L, min(R, a[v] - 1));
        dfs(r[v], max(L, a[v] + 1), R);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> l[i] >> r[i];
        u[l[i] + 1] = u[r[i] + 1] = 1;
    }
    int root = 2;
    while (u[root]) ++root;
    dfs(root - 1, 0, 1e9);
    for (int i = 1; i <= n; ++i)
        if (s.find(a[i]) == s.end())
            ++ans;
    cout << ans;

    return 0;
}