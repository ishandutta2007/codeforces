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

pl2 arr[100020];

void Main(){
	int n; cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> arr[i].fr >> arr[i].sc;
	}
	sort(arr+1, arr+n+1, [](pl2 a, pl2 b){
		return a.sc < b.sc;
	});
	int p1 = 1, p2 = n;
	ll cnt = 0, ans = 0;
	while (p1 <= p2){
		ll dif = arr[p1].sc - cnt;
		if (dif <= 0){ ans += arr[p1].fr; cnt += arr[p1].fr; p1 += 1; }
		else{
			ll can = min(dif, arr[p2].fr);
			cnt += can; ans += 2*can;
			arr[p2].fr -= can;
			if (arr[p2].fr == 0){ p2 -= 1; }
		}
	}
	cout << ans;
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(15);
	Main();
}