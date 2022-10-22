#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;
using ld = long double;

#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;

#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

// #define DEBUG

ll arr[50020];
ll prf[50020];
pl2 stk[50020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		ll x; cin >> x;
		for (int i = 1; i <= n; i++){ arr[i] -= x; }
		for (int i = 1; i <= n; i++){ prf[i] = prf[i-1] + arr[i]; }
		vector<pl2> v; int sti = 0;
		for (int i = n; i >= 1; i--){
			if (i != n){
				ll val = prf[i-1];
				if (stk[0].fr < val){
					int st = 0, ed = sti-1, idx = 0;
					while (st <= ed){
						int mid = st+ed >> 1;
						pl2 p = stk[mid];
						if (p.fr < val){ idx = mid; st = mid+1; }
						else{ ed = mid-1; }
					}
					v.push_back({i, stk[idx].sc});
				}
			}
			pl2 p = {prf[i], i};
			while (sti != 0){
				pl2 p2 = stk[sti-1];
				if (p < p2){ sti -= 1; }
				else{ break; }
			}
			stk[sti] = p; sti += 1;
		}
		sort(all(v)); int ed = -1;
		int ans = 0;
		for (pl2 p : v){
			int pst = p.fr, ped = p.sc;
			//cout << "P " << pst << ' ' << ped << endl;
			if (ed < pst){
				if (ed != -1){ ans += 1; }
				ed = 1e9;
			}
			ed = min(ed, ped);
		}
		if (ed != -1){ ans += 1; }
		cout << n-ans << endl;
	}
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}