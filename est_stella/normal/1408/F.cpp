#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define eb emplace_back
#define em emplace
#define mp make_pair
#define pre(a) cout<<fixed; cout.precision(a);
  
typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll; 
typedef long double ld;
const long long INF = 1e18;  
const int inf = 1e9;

int n;
vector<pii> ans;

void f(int s, int e) {
	if(s == e) return;

	int m = s + e >> 1;
	f(s, m);
	f(m+1, e);
	for(int i=s; i<=m; i++) {
		ans.eb(i, i - s + m + 1);
	}
}

int main() {
	fast;

	cin >> n;

	int k = 0;
	for(int i=0; i<=14; i++) {
		if((1 << i) <= n) k = i;
	}

	f(1, (1<<k));
	f(n - (1<<k) + 1, n);

	cout << ans.size() << "\n";

	for(auto i : ans) {
		cout << i.fi << " " << i.se << "\n";
	}
}