#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 998244353;

int n, k;
int a[200010];
int chk[200010];

void solve() {
    cin >> n >> k;

    for(int i=0; i<=n; i++) chk[i] = 0;
    
    for(int i=0; i<n; i++) {
        cin >> a[i];
        if(a[i] < n) chk[a[i]]++;
    }
    
    sort(a, a+n);

    int cnt = 0, last = 0;
    for(last = 0; last < n; last++) {
        if(!chk[last]) {
            if(cnt == k) break;
            else cnt++;
        }
    }

    int ans = 0;
    vector<int> v;
    for(int i=0; i<n; ) {
        int j = i;
        while(j < n && a[j] == a[i]) j++;
        if(a[i] >= last) v.eb(j - i), ans++;
        
        i = j;
    }

    sort(all(v));

    for(auto i : v) {
        if(k < i) break;
        k -= i;
        ans--;
    }

    cout << ans << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}