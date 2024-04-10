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

int n;
ll a[1010];

int main() {
    fast;

    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        if(i & 1) a[i] = a[i-1] + a[i];
        else a[i] = a[i-1] - a[i];
    }
    if(n & 1) n--;

    ll ans = 0;
    for(int i=0; i<=n; i+=2) {
        ll mn = a[i+1];
        for(int j=i+2; j<=n; j+=2) {
            ans += max(0LL, mn - max(a[i], a[j]) + 1);
            mn = min({mn, a[j], a[j+1]});
        }
    }

    cout << ans - (n/2);
}