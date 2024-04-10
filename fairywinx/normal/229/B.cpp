#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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

    //srand(time(NULL));
}

const int N = 1e5 + 228;
const int inf = 2e9;

vector<pair<int, int>> g[N];
vector<int> ban[N];
int d[N];

signed main() {
    setup();
    fill_n(d, N, inf);
    
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    for(int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for(int j = 0; j < k; ++j) {
            int a;
            cin >> a;
            ban[i].push_back(a);
        }
    }
    for(int i = 0; i < N; ++i) 
        sort(all(ban[i]));

    set<pair<int, int>> q;
    int s = 0;
    //for(auto i: ban[0]) 
    //    if (i == s) ++s;
            
    q.insert(mp(s, 0)); 
    d[0] = s;
    for(int i = 1; i < n; ++i) 
        q.insert(mp(inf, i));
    //cout << s << '\n';            
    vector<int> used(n);

    while(!q.empty()) {
        auto z = *q.begin();
        int now = z.second, price = z.first;
        used[now] = 1;
        q.erase(*q.begin());
        for(auto i: ban[now])             
            if (price == i)
                ++price;
        for(auto i: g[now]) {            
            int cur = i.first, price_cur = i.second;
            if (used[cur])
                continue;
            price_cur += price;
            if (price_cur < d[cur]) {
                q.erase(mp(d[cur], cur));
                q.insert(mp(price_cur, cur));
                d[cur] = price_cur;
            }        
        }
    }
    if (d[n - 1] == inf)
        cout << -1;
    else
        cout << d[n - 1];
}