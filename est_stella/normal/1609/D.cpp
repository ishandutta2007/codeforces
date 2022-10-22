#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define pb push_back
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define pre(x) cout<<fixed; cout.precision(x);

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 998244353;

int n, d;
int p[1010];
int sz[1010];

int Find(int x) {
    return p[x] = p[x] == x ? x : Find(p[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    sz[a] += sz[b];
    p[b] = a;
}

int main() {
    fast;

    cin >> n >> d;

    for(int i=1; i<=n; i++) p[i] = i, sz[i] = 1;

    int cnt = 1;
    for(int i=1; i<=d; i++) {
        int u, v;
        cin >> u >> v;

        if(Find(u) != Find(v)) Union(u, v);
        else cnt++;

        vector<int> a;
        for(int i=1; i<=n; i++) {
            if(Find(i) == i) a.eb(sz[i]);
        }
        sort(all(a));
        reverse(all(a));
        int ans = -1;
        for(int i=0; i<cnt && i < a.size(); i++) ans += a[i];
        cout << ans << "\n";
    }
}