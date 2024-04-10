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

ll arr[100020];
vector<pl2> brr[100020];
bool chk[100020][3];
int prf[100020][3];

inline bool f(int st, int ed, int m){
	if (st > ed){ return 1; }
	return (prf[ed][m]-prf[st-1][m] == ed-st+1);
}

void Main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		int num = 0;
		for (int i = 1; i <= m; i++){
			int k; cin >> k; ll sum = 0;
			brr[i].resize(k+1);
			for (int j = 1; j <= k; j++){
				cin >> brr[i][j].fr; sum += brr[i][j].fr;
				brr[i][j].sc = num; num += 1;
			}
			brr[i][0].fr = sum;
		}
		sort(arr+1, arr+n+1, [](ll a, ll b){ return a > b; });
		sort(brr+1, brr+m+1, [](vector<pl2> a, vector<pl2> b){ return a[0].fr*(b.size()-1) > b[0].fr*(a.size()-1); });
		for (int i = 1; i <= m; i++){
			ll va = arr[i]*(brr[i].size()-1), vb = brr[i][0].fr; chk[i][0] = (va >= vb);
			if (i != 1){ va = arr[i-1]*(brr[i].size()-1); chk[i][1] = (va >= vb); }
			if (i != m){ va = arr[i+1]*(brr[i].size()-1); chk[i][2] = (va >= vb); }
			//cout << "CHK " << chk[i][0] << ' ' << chk[i][1] << ' ' << chk[i][2] << endl;
		}
		for (int i = 1; i <= m; i++){
			prf[i][0] = prf[i-1][0]; if (chk[i][0]){ prf[i][0] += 1; }
			prf[i][1] = prf[i-1][1]; if (chk[i][1]){ prf[i][1] += 1; }
			prf[i][2] = prf[i-1][2]; if (chk[i][2]){ prf[i][2] += 1; }
			//cout << "PRF " << prf[i][0] << ' ' << prf[i][1] << ' ' << prf[i][2] << endl;
		}
		string ans = "";
		for (int i = 0; i < num; i++){ ans += '0'; }
		for (int i = 1; i <= m; i++){
			int bl = brr[i].size();
			for (int j = 1; j < bl; j++){
				int val = brr[i][j].fr, idx = brr[i][j].sc;
				ll sum = brr[i][0].fr - val; int sz = brr[i].size()-2;
				int st = 1, ed = m, pos = m+1;
				while (st <= ed){
					int mid = st+ed >> 1;
					//cout << "MID " << idx << ' ' << mid << endl;
					ll val = brr[mid][0].fr; int szm = brr[mid].size()-1;
					ll r1 = sum*szm, r2 = val*sz;
					if (r1 >= r2){ ed = mid-1; pos = mid; }
					else{ st = mid+1; }
				}
				//cout << "I " << idx << ' ' << i << ' ' << pos << endl;
				if (pos < i){
					bool chk = f(1, pos-1, 0) && (sum <= arr[pos]*sz) && f(pos, i-1, 2) && f(i+1, m, 0);
					//cout << "P1 " << f(1, pos-1, 0) << ' ' << (sum <= arr[pos]*sz) << ' ' << f(pos, i-1, 2) << ' ' << f(i+1, m, 0) << endl;
					if (chk){ ans[idx] = '1'; }
				}
				else if (pos == i){
					bool chk = f(1, i-1, 0) && (sum <= arr[pos]*sz) && f(i+1, m, 0);
					//cout << "P2 " << f(1, i-1, 0) << ' ' << (sum <= arr[pos]*sz) << ' ' << f(i+1, m, 0) << endl;
					if (chk){ ans[idx] = '1'; }
				}
				else if (pos > i){
					bool chk = f(1, i-1, 0) && f(i+1, pos-1, 1) && (sum <= arr[pos-1]*sz) && f(pos, m, 0);
					//cout << "P3 " << f(1, i-1, 0) << ' ' << f(i+1, pos, 2) << ' ' << (sum <= arr[pos-1]*sz) << ' ' << f(pos+1, m, 0) << endl;
					if (chk){ ans[idx] = '1'; }
				}
			}
		}
		cout << ans << endl;
		for (int i = 1; i <= n; i++){
			arr[i] = 0;
			chk[i][0] = chk[i][1] = chk[i][2] = 0;
			prf[i][0] = prf[i][1] = prf[i][2] = 0;
		}
		for (int i = 1; i <= m; i++){ brr[i].clear(); }
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