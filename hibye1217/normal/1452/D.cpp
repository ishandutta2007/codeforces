#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define endl '\n'
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

const ll mod = 998244353;
ll dp[200020] = {0, 1, 1};

void Main(){
	int n;
	cin >> n;
	for (int i = 3; i <= n; i++){
		dp[i] = (dp[i-1] + dp[i-2]) % mod;
	}
	ll pd = 1;
	for (int i = 1; i <= n; i++){
		pd = pd*2 % mod;
	}
	ll ans = dp[n], mul = pd, val = mod-2;
	//cout << ans << ' ' << mul << endl;
	while (val){
		if (val & 1) ans = ans*mul % mod;
		mul = mul*mul % mod;
		val >>= 1;
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(15);
	Main();
}