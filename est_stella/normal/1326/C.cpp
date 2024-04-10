#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)
#define mp make_pair
  
typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const long long INF = 1e18;  
const int inf = 1e9;
const ll Mod = 998244353;

int n, k;
int a[200010];
ll ans, cnt=1;

int main() {
	fast;

	cin >> n >> k;

	int l = 0;
	for(int i=1; i<=n; i++) {
		cin >> a[i];

		if(a[i] > n - k) {
			ans += a[i];

			if(l) cnt *= (i - l);
			cnt %= Mod;
			l = i;
		}
	}

	cout << ans << " " << cnt << endl;
}