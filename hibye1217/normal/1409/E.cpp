#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define pf push_front
#define mt make_tuple
#define endl '\n'
#define up front()
#define tp top()
#define em empty()
#define all(v) v.begin(),v.end()
#define fr(p) get<0>(p)
#define sc(p) get<1>(p)
#define th(p) get<2>(p)
#define fo(p) get<3>(p)
#define fi(p) get<4>(p)
#define dec(x) cout.setf(ios::fixed); cout.precision(x);
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
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int arr[200020];
int ans[200020];
set<pii> s;

int main(){
	Fast;
	int t = 1;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		for (int i = 1; i <= n; i++){ int _; cin >> _; }
        sort(arr+1, arr+n+1);
        int j = 1, sz = 0;
        for (int i = 1; i <= n; i++){
			for (; j <= n; j++){
				if (arr[i]+k < arr[j]) break;
				s.insert(mt(arr[j], j)); sz += 1;
			}
			ans[i] = sz;
			s.erase(mt(arr[i], i)); sz -= 1;
			//for (pii p : s) cout << fr(p) << ' ' << sc(p) << " / "; cout << endl;
        }
        for (int i = 1; i <= n; i++) s.insert(mt(ans[i], i));
        sz = n;
        j = 1;
        int res = 0;
        for (int i = 1; i <= n; i++){
            for (; j <= n; j++){
				if (arr[i]+k < arr[j]) break;
				s.erase(mt(ans[j], j)); sz -= 1;
            }
			if (sz > 0) res = max(res, ans[i] + fr(*(s.rbegin())));
			else res = max(res, ans[i]);
			//for (pii p : s) cout << fr(p) << ' ' << sc(p) << " / "; cout << endl;
        }
        cout << res << endl;
	}
}