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
#define t(x) cout << #x << " : " << x << endl ;
#define ta1(a,s,e) cout << #a << " : " ; for (int iter = s; iter < e; iter++) cout << a[iter] << ' ' ; cout << endl ;
#define ta2(a,s,e) cout << #a << " : " ; for (int iter = s; iter <= e; iter++) cout << a[iter] << ' ' ; cout << endl ;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef tuple<int, int> pii;
typedef tuple<int, int, int> piii;
typedef tuple<ll, ll> pll;
typedef tuple<string, int> psi;
typedef tuple<string, ll> psl;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int cnt[120];

int main(){
    Fast;
    int t = 1;
    cin >> t;
    while (t--){
		for (int i = 0; i <= 100; i++) cnt[i] = 0;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			int x;
			cin >> x;
			cnt[x] += 1;
		}
		int m1=0, m2=0;
		bool chk = false;
		for (int i = 0; i <= 100; i++){
			if (cnt[i] == 0){
				if (chk){ m2 = i; break; }
				m1 = m2 = i;
				break;
			}
			if (cnt[i] == 1){
				if (chk) continue;
				m1 = i;
				chk = true;
			}
		}
		cout << m1+m2 << endl;
	}
}