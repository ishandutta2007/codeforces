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

pi2 arr[300020];
int dis[300020];
priority_queue< pi2, vector<pi2>, greater<pi2> > pq;
bool chk[300020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n, k; cin >> n >> k;
		for (int i = 1; i <= n; i++){
			dis[i] = 2e9;
			chk[i] = 0;
		}
		for (int i = 1; i <= k; i++){ cin >> arr[i].fr; }
		for (int i = 1; i <= k; i++){ cin >> arr[i].sc; }
		for (int i = 1; i <= k; i++){
			dis[ arr[i].fr ] = arr[i].sc;
			pq.push({ arr[i].sc, arr[i].fr });
		}
		while (!pq.empty()){
			int dst = pq.top().fr, now = pq.top().sc;
			pq.pop();
			if (chk[now]){ continue; }
			chk[now] = 1;
			for (int nxt : {now-1, now+1}){
				if (1 > nxt || nxt > n){ continue; }
				if (chk[nxt] || dis[nxt] <= dst+1){ continue; }
				dis[nxt] = dst+1;
				pq.push({ dst+1, nxt });
			}
		}
		for (int i = 1; i <= n; i++){
			cout << dis[i] << ' ';
		}
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