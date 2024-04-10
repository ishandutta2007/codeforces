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

vector<int> v1, v2;
int dp[2520][5020];

void Main(){
	int n; cin >> n;
	v1.push_back(0); v2.push_back(0);
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		if (x == 1){ v1.push_back(i); }
		else{ v2.push_back(i); }
	}
	memset(dp, 0x3f, sizeof(dp));
	int l1 = v1.size()-1, l2 = v2.size()-1;
	for (int i = 0; i <= l1; i++){
		for (int j = i; j <= l2; j++){
			if (i==0 && j==0){ dp[i][j] = 0; }
			else if (i==0){ dp[i][j] = 0; }
			else{
				dp[i][j] = min( dp[i][j-1], dp[i-1][j-1] + abs(v1[i]-v2[j]) );
			}
		}
	}
	cout << dp[l1][l2];
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