#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );
#define bnt(x) __builtin_popcount(x)

int gcd(int a, int b){ return b ? gcd(b, a%b) : a; }

// #define DEBUG

const int N = 1000000;
vector<int> arr[1000020];
bool chk[1000020];

void Main(){
	int n; cin >> n;
	for (int i = 1; i <= n; i++){
		int x; cin >> x; chk[x] = 1;
	}
	for (int i = 1; i <= N; i++){
		for (int j = i; j <= N; j+=i){
			if (chk[j]){ arr[i].push_back(j); }
		}
	}
	int ans = 0;
	for (int i = N; i >= 1; i--){
		if (arr[i].empty()){ continue; }
		int g = arr[i][0];
		for (int x : arr[i]){ g = gcd(g, x); }
		if (g == i && !chk[i]){ ans += 1; }
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
	cout.precision(0);
	Main();
}