#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define em emplace
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)
#define mp make_pair

typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const ll INF = 1e18;
const int inf = 1e9;

int n, m;
int a[100010];

void solve() {
    cin >> n >> m;

    for(int i=1; i<=n*m; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<i; j++) {
            if(a[i] > a[j]) ans++;
        }
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