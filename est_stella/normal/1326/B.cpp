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

int n;
ll b[200010];
ll a[200010];

int main() {
	cin >> n;

	ll mx = 0;
	for(int i=1; i<=n; i++) {
		cin >> b[i];
		a[i] = b[i] + mx;
		mx = max(mx, a[i]);
	}

	for(int i=1; i<=n; i++) {
		cout << a[i] << " ";
	}
}