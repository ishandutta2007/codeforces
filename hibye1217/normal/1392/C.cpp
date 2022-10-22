#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define pf push_front
#define endl '\n'
#define up front()
#define tp top()
#define all(v) v.begin(),v.end()
#define fr(p) get<0>(p)
#define sc(p) get<1>(p)
#define th(p) get<2>(p)
#define fo(p) get<3>(p)
#define fi(p) get<4>(p)
#define dec(x) cout.precision(x);
#define t1(x) cout << #x << ' ' << x << endl ;
#define t2(x,y) cout << #x << ' ' << x << " / " << #y << ' ' << y << endl ;
#define t3(x,y,z) cout << #x << ' ' << x << " / " << #y << ' ' << y << " / " << #z << ' ' << z << endl ;
#define t4(x,y,z,w) cout << #x << ' ' << x << " / " << #y << ' ' << y << " / " << #z << ' ' << z << " / " << #w << ' ' << w << endl ;
#define t5(x,y,z,w,v) cout << #x << ' ' << x << " / " << #y << ' ' << y << " / " << #z << ' ' << z << " / " << #w << ' ' << w << " / " << #v << ' ' << v << endl ;
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

int arr[200020];

int main(){
    Fast;
	int t = 1;
	cin >> t;
	while (t--){
		ll n, ans=0;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> arr[i];
			if (i != 1 && arr[i-1] > arr[i]) ans += arr[i-1]-arr[i];
		}
		cout << ans << endl;
	}
}