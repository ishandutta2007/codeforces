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

int k, n, m;
int arr[120], brr[120];

void Main(){
	int t; cin >> t;
	while (t--){
		cin >> k >> n >> m;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		for (int i = 1; i <= m; i++){ cin >> brr[i]; }
		vector<int> ans;
		int p1 = 1, p2 = 1;
		while (p1 <= n || p2 <= m){
			if (p1 > n || arr[p1] > k){ if (p2 > m || brr[p2] > k){ cout << -1; goto done; } ans.push_back(brr[p2++]); }
			else{ ans.push_back(arr[p1++]); }
			if (ans[ ans.size()-1 ] == 0){ k += 1; }
		}
		for (int x : ans){ cout << x << ' '; }
		done: cout << endl;
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