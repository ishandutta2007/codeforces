#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

int n, cnt;
int was[100105];
ll s[100105];
vector<int> g[100105];
ll sum = 0;

void fail() { cout << "-1" << endl; exit(0); }

void dfs(int v, ll prv = 0, int h = 1) {
    if (was[v]++) fail();
    ++cnt;
    if (s[v] != -1)
        sum += s[v];
    if (h % 2 == 0 && s[v] != -1) fail();
    if (h % 2 != 0 && s[v] < prv) fail();
    if (h % 2 != 0) {
        for (int to : g[v])
            dfs(to, s[v], h + 1);
    } else {
        vector<ll> vec;
        for (int to : g[v]) {
            dfs(to, prv, h + 1);
            vec.push_back(s[to]);
        }
        sort(vec.begin(), vec.end());
        if (vec.size())
            sum -= vec[0] * (vec.size() - 1) + prv;
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        g[x].push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }

    dfs(1);
    if (cnt != n)
        fail();

    cout << sum << endl;
}