#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

#define int long long
#define all(x) x.begin(), x.end()
#define pb emplace_back
#define mp make_pair

using namespace std;

void setup() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
    ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    #endif

    srand(time(NULL));
}

const int N = 100;

vector<int> g[N];

void dfs(int v, vector<int> &used) {
    used[v] = 1;
    for(auto u: g[v]) {
        if (!used[u])
            dfs(u, used);
    }
}

signed main() {
    setup();

    int n;
    cin >> n;
    unordered_map<int, int> x;
    unordered_map<int, int> y;
    map<pair<int, int>, int> z; 
    for(int i = 0 ; i < n; ++i) {
        int b, c;
        cin >> b >> c;
        if (!x.count(b))
            x[b] = 0;
        if (!y.count(c)) 
            y[c] = 0;
        if (!z.count(mp(b, c))) 
            z[mp(b, c)] = 0;
        ++z[mp(b, c)];
        ++x[b], ++y[c];
    }
    int ans = 0;
    for(auto i: x) {
        ans += i.second * (i.second - 1) / 2;
    }
    for(auto i: y) {
        ans += i.second * (i.second - 1) / 2;
    }
    for(auto i: z) {
        ans -= i.second * (i.second - 1) / 2;
    }
    cout << ans;
}