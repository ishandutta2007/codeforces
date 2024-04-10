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

int n, u, v;
int a[100010];

int solve() {
    cin >> n >> u >> v;

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    bool flag = true;
    for(int i=0; i<n; i++) {
        if(a[i] != a[0]) flag = false;
    }

    if(flag) return v + min(u, v);

    int ans = 0;

    for(int i=1; i<n; i++) {
        if(abs(a[i-1] - a[i]) > 1) break;

        if(i == n-1) return min(u, v);
    }

    return 0;
}

int main() {
    fast;

    int t;
    cin >> t;

    while(t--) {
        cout << solve() << "\n";
    }
}