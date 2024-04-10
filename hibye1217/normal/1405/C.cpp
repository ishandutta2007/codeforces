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
typedef tuple<string, int> psi;
typedef tuple<string, ll> psl;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main(){
	Fast;
    int t = 1;
    cin >> t;
    while (t--){
		int n, k;
		string s;
		cin >> n >> k >> s;
		bool ans = true;
		for (int i = 0; i < k; i++){
			bool ze = true, on = true;
			for (int j = i; j < n; j += k){
                if (s[j] == '0') on = false;
				if (s[j] == '1') ze = false;
			}
			if (ze && !on){
                for (int j = i; j < n; j += k) s[j] = '0';
			}
			if (!ze && on){
				for (int j = i; j < n; j += k) s[j] = '1';
			}
			if (!ze && !on){
				ans = false;
			}
		}
		//t2(s, ans);
		int ze=0, on=0, qu=0;
		for (int i = 0; i < k; i++){
			if (s[i] == '0') ze += 1;
			if (s[i] == '1') on += 1;
			if (s[i] == '?') qu += 1;
		}
		if (ze > k/2 || on > k/2) ans = false;
		cout << (ans ? "YES" : "NO");
        done: ;
		cout << endl;
	}
}