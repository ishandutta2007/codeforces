#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define eb emplace_back
#define em emplace
#define pre(a) cout<<fixed; cout.precision(a)
#define mp make_pair
#define mt make_tuple
  
typedef long long ll;  
typedef long double ld;
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> ti;
typedef tuple<ll,ll,ll> tl; 
const ll INF = 1e18;
const int inf = 1e9;

int n, d, m;
int a[100010];

int main() {
	fast;

	cin >> n >> d >> m;

	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}

	sort(a+1, a+n+1);

	int k = upper_bound(a+1, a+n+1, m) - a;

	ll sum = 0;
	for(int i=1; i<k; i++) {
		sum += a[i];
	}

	int idx = 1;
	ll ans = sum;

	for(int i=1; i <= n - k + 1; i++) {
		sum += a[n - i + 1];

		int t = (i-1) * d - (n-k+1) + i;

		if(t >= k) break;

		while(idx <= t) {
			sum -= a[idx];
			idx++;
		}

		ans = max(ans, sum);
	}

	cout << ans;
}