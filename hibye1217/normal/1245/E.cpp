#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() )
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl
#define bcnt(x) __builtin_popcount(x)
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

const int N = 10;

int arr[120];
ld dp[120];

inline int f(int y, int x){
	if (~y & 1){ return (N-y)*N + x; }
	else{ return (N-y)*N + (N+1-x); }
}

void Main(){
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			//cout << f(i,j) << '\t';
			cin >> arr[ f(i,j) ];
			arr[ f(i,j) ] = f( i - arr[ f(i,j) ], j );
		}
		//cout << endl;
	}
	dp[100] = 0;
	for (int i = 99; i >= 1; i--){
		dp[i] = 1;
		for (int j = 1; j <= 6 && i+j <= N*N; j++){
			dp[i] += min( dp[i+j], dp[ arr[i+j] ] ) / 6;
		}
		if (i >= 95){ dp[i] *= 6 / (ld)(100-i); }
	}
	cout << dp[1];
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(9);
	Main();
}