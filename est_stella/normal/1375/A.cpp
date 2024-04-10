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

void solve() {
	int n;
	int a[100];
	cin >> n;

	for(int i=0; i<n; i++) {
		cin >> a[i];

		a[i] = abs(a[i]);
		if(i % 2) a[i] = -a[i];

		cout << a[i] << " ";
	}
	cout << "\n";
}

int main() {
	fast;
	int t;

	cin >> t;

	while(t--) {
		solve();
	}
}