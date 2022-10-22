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

int n, m, q;
string s[22];
string t[22];

int main() {
	fast;

	cin >> n >> m;

	for(int i=0; i<n; i++) {
		cin >> s[i];
	}

	for(int i=0; i<m; i++) {
		cin >> t[i];
	}

	cin >> q;

	while(q--) {
		int y;
		cin >> y;
		y--;
		cout << s[y%n] + t[y%m] << "\n";
	}
}