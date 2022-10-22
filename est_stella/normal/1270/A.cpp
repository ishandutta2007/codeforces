#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)
  
typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const long long INF = 1e18;  
const int inf = 1e9;

int main() {
	fast;

	int t;
	cin >> t;

	while(t--) {
		int n, k1, k2;
		cin >> n >> k1 >> k2;

		int x;
		bool flag = false;
		for(int i=1; i<=k1; i++) {
			cin >> x;

			if(x == n) flag = true;
		}

		for(int i=1; i<=k2; i++) {
			cin >> x;
		}

		if(flag) cout << "YES\n";
		else cout << "NO\n";
	}
}