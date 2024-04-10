#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define endl '\n'
#define all(v) v.begin(),v.end()
#define fr(p) get<0>(p)
#define sc(p) get<1>(p)
#define th(p) get<2>(p)
#define fo(p) get<3>(p)
#define fi(p) get<4>(p)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef tuple<int, int> pii;
typedef tuple<int, int, int> piii;
typedef tuple<int, int, int, int> piiii;
typedef tuple<int, int, int, int, int> piiiii;
typedef tuple<ll, ll> pll;
typedef tuple<ll, ll, ll> plll;
typedef tuple<ll, ll, ll, ll> pllll;
typedef tuple<ll, ll, ll, ll, ll> plllll;

string mp[120];

int main(){
	Fast;
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		int ans = 0;
		for (int i = 0; i < n; i++) cin >> mp[i];
		for (int i = 0; i < m; i++){
			if (mp[n-1][i] == 'D') ans++;
		}
		for (int i = 0; i < n; i++){
			if (mp[i][m-1] == 'R') ans++;
		}
		cout << ans << endl;
	}
}