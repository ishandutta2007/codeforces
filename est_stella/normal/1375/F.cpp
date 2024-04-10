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

ll a[5];
ll add;

void f() {
	cout << add << endl << endl << flush;

	ll x;
	cin >> x;

	if(x == 0 || x == -1) exit(0);

	a[x] += add;
}

int main() {
	cin >> a[1] >> a[2] >> a[3];

	cout << "First" << endl << flush;
	add = max({a[1], a[2], a[3]});

	f();

	ll x, y, z;

	x = max({a[1], a[2], a[3]});
	z = min({a[1], a[2], a[3]});
	y = a[1] + a[2] + a[3] - x - z;

	add = 2 * x - y - z;

	f();

	add = max({a[1], a[2], a[3]}) - min({a[1], a[2], a[3]});
	add /= 2;

	f();
}