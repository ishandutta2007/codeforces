#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

//[l,r]
//(l,r)

//0


//x....
//x
//OK

//
//Z_algorithm

void Z_algorithm(const vector<int> &s, vector<int> &a) {
	int sz = s.size();
	a.resize(sz);
	a[0] = sz;
	int i = 1, j = 0;
	while (i < sz) {
		while (i + j < sz&&s[j] == s[i + j])++j;
		a[i] = j;
		if (j == 0) { ++i; continue; }
		int k = 1;
		while (i + k < sz&&k + a[k] < j)a[i + k] = a[k], ++k;
		i += k; j -= k;
	}
}

int c[1 << 17];
void solve() {
	int n; cin >> n;
	vector<int> a(n);
	int chk;
	rep(i, n) {
		cin >> a[i];
		c[a[i]]++;
	}
	{
		bool valid = true;
		int tmp = 0;
		rep1(i, n) {
			if (c[i] % 2) {
				tmp++; chk = i;
			}
		}
		if (n % 2 == 0 && tmp > 0)valid = false;
		if (n % 2 && tmp > 1)valid = false;
		if (!valid) {
			cout << 0 << endl; return;
		}
	}
	vector<int> z;
	rep(i, n) {
		z.push_back(a[i]);
	}
	per(i, n) {
		z.push_back(a[i]);
	}
	vector<int> ra;
	Z_algorithm(z, ra);
	int same = ra[n];

	ll ans = 0;
	//lr
	
	int cc = 0;
	vector<int> num2(n + 1,0);
	for (int i = n - 1; i >= 0; i--) {
		num2[a[i]]++;
		if (num2[a[i]] > c[a[i]] / 2) {
			cc = i; break;
		}
	}

	vector<int> num(n + 1,0);
	int mid = n / 2;
	for (int l = 0; l < (n+1) / 2; l++) {
		if (l <= same) {

			ans += (n - max(mid,cc));
		}
		else {
			ans += same + 1;
		}
		num[a[l]]++;
		if (num[a[l]] > c[a[l]] / 2)break;
	}

	fill(num.begin(), num.end(), 0);
	rep(i, n / 2) {
		num[a[i]]++;
	}

	if (n % 2 && a[n / 2] != chk) {
		cout << ans << endl; return;
	}
	rep(i, n / 2) {
		if (num[a[i]] != c[a[i]] / 2) {
			cout << ans << endl;
			return;
		}
	}
	//l
	for (int l = (n + 1) / 2; l < n; l++) {
		if (l>(n+1)/2&&a[l-1] != a[n - 1 - (l-1)])break;
		int rl = n - 1 - l;
		if (rl <= same)ans += (n -l);
		else {
			ans += same + 1;
		}
	}
	//cout << ans << endl;
	
	//r
	for (int r = n / 2 - 1; r >= 0; r--) {
		if (r<n/2-1&&a[r + 1] != a[n - 1 - (r + 1)])break;
		if (r <= same)ans += r + 1;
		else {
			ans += same+1;
		}
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}