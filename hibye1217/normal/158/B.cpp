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
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using cpl = complex<ld>;
const ld pi = 3.14159265358979323846264338327950288;
const ld tau = 2 * pi;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int cnt[5];

void Main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		cnt[x] += 1;
	}
	int ans = 0;
	ans += cnt[4]; cnt[4] = 0;
	int mn = min(cnt[3], cnt[1]);
	ans += mn; cnt[3] -= mn; cnt[1] -= mn;
	ans += cnt[3]; cnt[3] = 0;
	ans += cnt[2]/2; cnt[2] &= 1;
	if (cnt[2]){ ans += cnt[2]; cnt[2] = 0; cnt[1] -= min(cnt[1], 2); }
	ans += cnt[1] / 4; cnt[1] &= 3;
	ans += !!cnt[1];
	cout << ans;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}