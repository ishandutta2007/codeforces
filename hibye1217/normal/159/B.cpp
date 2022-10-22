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

const int N = 1000;
vector<int> v1[1020], v2[1020];

void Main(){
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++){
		int a, b; cin >> a >> b;
		v1[b].push_back(a);
	}
	for (int i = 1; i <= m; i++){
		int a, b; cin >> a >> b;
		v2[b].push_back(a);
	}
	int ans=0, cnt=0;
	for (int i = 1; i <= N; i++){
		sort(all(v1[i])); sort(all(v2[i]));
		int l1 = v1[i].size(), l2 = v2[i].size();
		ans += min(l1, l2);
		int p1 = 0, p2 = 0, res = 0;
		while (p1 < l1 && p2 < l2){
			if (v1[i][p1] == v2[i][p2]){ p1 += 1; p2 += 1; res += 1; }
			else if (v1[i][p1] > v2[i][p2]){ p2 += 1; }
			else{ p1 += 1; }
		}
		cnt += res;
	}
	cout << ans << ' ' << cnt;
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(2);
	Main();
}