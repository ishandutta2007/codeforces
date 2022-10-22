#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() )
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl
#define mkp(a,b) make_pair(a,b)
#define gcd(a,b) __gcd(a,b)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using cpl = complex<ld>;
const ld pi = 3.14159265358979323846264338327950288;
const ld tau = 2 * pi;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

// #define DEBUG

int arr[10020];
bool chk[120];
pi2 ans[120];
int cnt[120], pre[120];

void Main(){
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n*k; i++){ cin >> arr[i]; }
	int x = (n + k-2) / (k-1);
	int c = 0;
	for (int i = 1; i <= n*k; i++){
		int col = arr[i];
		if (chk[col]){ continue; }
		cnt[col] += 1;
		if (cnt[col] == 2){
			c += 1; chk[col] = 1;
			ans[col] = { pre[col], i };
		}
		pre[col] = i;
		if (c == x){
			memset(cnt, 0, sizeof(cnt));
			memset(pre, 0, sizeof(pre));
			c = 0;
		}
	}
	for (int i = 1; i <= n; i++){
		cout << ans[i].fr << ' ' << ans[i].sc << endl;
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