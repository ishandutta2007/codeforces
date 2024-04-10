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

//#define DEBUG

const int N = 262144;
ll two[20];
int arr[200020];

void Main(){
	two[0] = 1; int nn = 0;
	for (int i = 1; two[i-1] < N; i++){ two[i] = two[i-1]*2; nn = i; }
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		sort(arr+1, arr+n+1);
		vector<int> prf; prf.push_back(0);
		prf.push_back(1); int m = 1;
		for (int i = 2; i <= n; i++){
			if (arr[i-1] == arr[i]){ prf[m] += 1; }
			else{ prf.push_back(1); m += 1; }
		}
		//cout << "PRF ";
		for (int i = 1; i <= m; i++){ prf[i] += prf[i-1]; }
		//for (int x : prf){ cout << x << ' '; } cout << endl;
		int ans = 1e9;
		for (int a = 1; a <= 2*n; a*=2){
			for (int b = 1; b <= 2*n; b*=2){
				for (int c = 1; c <= 2*n; c*=2){
					if (a+b+c < n){ continue; }
					int x1 = a;
					int i1 = upper_bound(all(prf), x1) - prf.begin() - 1;
					//cout << "I1 " << a << ' ' << b << ' ' << c << endl;
					int x2 = prf[i1] + b;
					int i2 = upper_bound(all(prf), x2) - prf.begin() - 1;
					if (n-prf[i2] > c){ continue; }
					//cout << "I2 " << a << ' ' << b << ' ' << c << endl;
					int res = a+b+c - n;
					ans = min(ans, res);
				}
			}
		}
		cout << ans << endl;
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