/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
typedef long long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 101010
#define MOD 100000009
#define INF 1000000000000

#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

vector<ll> arr;

void solve() {
	ll N, K;
	ll i;
	cin >> N >> K;
	vector<ll> v(N);
	ll M;
	if (N % 2 == 0) M = N - 1;
	else M = N;
	for (i = 0; i < M; i++) {
		ll a, b;
		cout << "and" << bb << i + 1 << bb << ((i + 1) % M + 1) << ln;
		cout.flush();
		cin >> a;
		cout << "or" << bb << i + 1 << bb << ((i + 1) % M + 1) << ln;
		cout.flush();
		cin >> b;
		v[i] = (a + b);
	}
	ll sum = 0;
	for (i = 0; i < M; i++) {
		if (i % 2 == 0) sum += v[i];
		else sum -= v[i];
	}
	ll x = sum / 2;
	arr.push_back(x);
	for (i = 0; i < M - 1; i++) {
		x = v[i] - x;
		arr.push_back(x);
	}
	if (M != N) {
		ll a, b;
		cout << "and" << bb << 1 << bb << N << ln;
		cout.flush();
		cin >> a;
		cout << "or" << bb << 1 << bb << N << ln;
		cout.flush();
		cin >> b;
		ll s = (a + b);
		arr.push_back(s - (sum / 2));
	}
	sort(arr.begin(), arr.end());
	cout << "finish" << bb << arr[K - 1] << ln;
}

void init() {

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	omode;
	while (T--) {
		init();
		solve();
	}
}