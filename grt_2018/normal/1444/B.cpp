#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
 
using namespace std;
 
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
 
const int nax = 300 * 1000 + 10, mod = 998244353;
int n;
int a[nax];
 
int fast_pow(int A, int B) {
	int w = 1;
	while(B > 0) {
		if(B&1) w = ((ll)w * A) % mod;
		B/=2;
		A = ((ll)A * A) % mod;
	}
	return w;
}
 
int main() {_
	cin >> n;
	for(int i = 1; i <= 2 * n; ++i) {
		cin >> a[i];
	}
	ll sum = 0;
	sort(a + 1, a + n + 1);
	sort(a + n + 1, a + 2 * n + 1);
	for(int i = 1; i <= n; ++i) {
		sum += abs(a[i] - a[2 * n - i + 1]);
	}
	sum %= mod;
	int w1 = 1, w2 = 1;
	for(int i = 1; i <= 2 * n; ++i) {
		if(i <= n) {
			w1 = ((ll)w1 * i)%mod;
		}
		w2 = ((ll)w2 * i) % mod;
	}
	int w = (ll)w2 * fast_pow(w1, mod - 2) % mod;
	w = ((ll)w * fast_pow(w1, mod - 2)) % mod;
	sum = (sum * w) % mod;
	cout << sum << "\n";
		
	
	
}