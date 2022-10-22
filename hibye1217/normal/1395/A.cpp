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
#define dec(x) cout.precision(x);
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

int main(){
	Fast;
	int t;
	cin >> t;
	while (t--){
		int x, y, z, w;
		cin >> x >> y >> z >> w;
		int o = x%2 + y%2 + z%2 + w%2;
		if (o <= 1) cout << "Yes" << endl;
		else if (o == 2) cout << "No" << endl;
		else if (min(x, min(y, z)) == 0) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
}