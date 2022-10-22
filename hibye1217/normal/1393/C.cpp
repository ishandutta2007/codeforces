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

int main(){
	Fast;
	int t;
	cin >> t;
	int mx = 0;
	while (t--){
		set<int> s;
		int cnt[100020] = {};
		int n;
		cin >> n;
		int mx = 0;
		for (int i = 1; i <= n; i++){
			int x;
			cin >> x;
			cnt[x]++;
			if (cnt[x] == 2) s.insert(x);
			mx = max(mx, cnt[x]);
		}
		//for (int x :s)cout<<x<<' ';
		int st=0, ed=n-2, ans=0;
		loop:
		while (st <= ed){
			//cout << st << ' ' << ed <<endl;
			int mid = st + ed >> 1;
			int m = 0;
			int ptr[100020] = {};
			for (int i = 0; i*(mid+1) < n; i++){ ptr[i] = i * (mid+1); m = i; }
			if (m+1 < mx){
				ed = mid-1;
				goto loop;
			}
			for (int x : s){
				for (int i = 0; i < cnt[x]; i++) ptr[i]++;
				for (int i = 0; i <= m; i++){
					if (ptr[i] > n){
						ed = mid-1;
						goto loop;
					}
				}
			}
			ans = mid;
			st = mid+1;
		}
		//cout << st << ' ' << ed <<endl;
		cout << ans << endl;
	}
}