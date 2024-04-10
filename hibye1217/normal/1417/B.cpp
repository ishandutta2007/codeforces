#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ps push
#define psb push_back
#define psf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define mt make_tuple
#define endl '\n'
#define up front()
#define tp top()
#define sz size()
#define em empty()
#define all(v) v.begin(),v.end()
#define fr(p) get<0>(p)
#define sc(p) get<1>(p)
#define th(p) get<2>(p)
#define fo(p) get<3>(p)
#define fi(p) get<4>(p)
#define dec(x) cout.setf(ios::fixed); cout.precision(x);
#define t(x) if (!submit){ cout << #x << " : " << x << endl ; }
#define ta1(a,s,e) if (!submit){ cout << #a << " : " ; for (int iter = s; iter < e; iter++) cout << a[iter] << ' ' ; cout << endl ; }
#define ta2(a,s,e) if (!submit){ cout << #a << " : " ; for (int iter = s; iter <= e; iter++) cout << a[iter] << ' ' ; cout << endl ; }
#define tv(v) if (!submit){ cout << #v << " : " ; for ( int iter : v ) cout << iter << ' ' ; cout << endl ; }
#define tm() if (!submit){ cout << endl ; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef tuple<int, int> pii;
typedef tuple<int, int, int> piii;
typedef tuple<ll, ll> pll;
typedef tuple<ll, ll, ll> plll;
typedef tuple<string, int> psi;
typedef tuple<string, ll> psl;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const bool submit = 1;

ll arr[100020];

int main(){
	if (submit){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	}
	int t;
	cin >> t;
	while (t--){
		ll n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		ll k = m/2;
		if (m%2 == 1){
			for (int i = 1; i <= n; i++){
				if (arr[i] <= k) cout << 1 << ' ';
				else cout << 0 << ' ';
			}
		}
		else{
			int cnt = 0;
			for (int i = 1; i <= n; i++){
				if (arr[i] == k) cnt += 1;
			}
			int ct = 0;
			for (int i = 1; i <= n; i++){
				if (arr[i] < k){ cout << 1 << ' '; }
				else if (arr[i] > k){ cout << 0 << ' '; }
				else{
					if (ct < cnt/2) cout << 1 << ' ';
					else cout << 0 << ' ';
					ct += 1;
				}
			}
		}
		cout << endl;
	}
}