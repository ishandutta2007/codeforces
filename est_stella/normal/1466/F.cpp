#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define em emplace
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1e9 + 7;

int n, m;
int p[500010];
int po[500010];
vector<int> ans;

int Find(int a) {
    return p[a] = p[a] == a ? a : Find(p[a]);
}

void Union(int a, int b) {
    if(Find(b) == Find(a)) return;
    p[Find(b)] = Find(a);
}

int main() {
    fast;

    cin >> n >> m;

    for(int i=0; i<=m; i++) p[i] = i;

    po[0] = 1;
    for(int i=1; i<=m; i++) {
        po[i] = po[i-1] * 2 % mod;
    }

    for(int i=1; i<=n; i++) {
        int k;
        cin >> k;
        int a[2] = {};
        for(int j=0; j<k; j++) {
            cin >> a[j];
        }

        if(Find(a[0]) != Find(a[1])) {
            Union(a[0], a[1]);
            ans.eb(i);
        }
    }

    cout << po[ans.size()] << " " << ans.size() << "\n";
    for(auto i : ans) {
        cout << i << " ";
    }
}