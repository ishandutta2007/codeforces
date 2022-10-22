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
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0}; // ^>v<
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

// #define DEBUG

int arr[200020];
int cnt[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; i++){
			cin >> arr[i];
			cnt[ arr[i] ] += 1;
			if (cnt[ arr[i] ] == 1){ ans += 1; }
		}
		queue<int> q;
		for (int i = 1; i <= n; i++){ q.push(i); }
		for (int i = 1; i <= n; i++){
			if (cnt[i] != 0){ continue; }
			while (1){
				int pos = q.front();
				if (cnt[ arr[pos] ] == 1){ q.pop(); }
				else if (pos == i){ q.push(pos); q.pop(); }
				else{ break; }
			}
			int pos = q.front();
			cnt[ arr[pos] ] -= 1; cnt[i] += 1;
			arr[pos] = i;
		}
		cout << ans << endl;
		for (int i = 1; i <= n; i++){ cout << arr[i] << ' '; cnt[i] -= 1; }
		cout << endl;
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