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
	int n, m, x, y;
	cin >> n >> m >> y >> x;
	cout << y << ' ' << x << endl;
	cout << 1 << ' ' << x << endl;
	for (int i = 1; i <= n; i++){
		if (i%2 == 1){
			for (int j = 1; j <= m; j++){
				if ((i == y || i == 1) && j == x) continue;
				cout << i << ' ' << j << endl;
			}
		}
		else{
			for (int j = m; j >= 1; j--){
				if ((i == y || i == 1) && j == x) continue;
				cout << i << ' ' << j << endl;
			}
		}
	}
}