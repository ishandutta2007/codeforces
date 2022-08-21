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
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;

bool isp[1 << 21];
void init() {
	fill(isp, isp + (1 << 21), true);
	Rep(i, 2, 1 << 21) {
		if (!isp[i])continue;
		for (int j = 2 * i; j < (1 << 21); j += i) {
			isp[j] = false;
		}
	}
}
int a[1 << 10]; int n;
vector<int> ans1,ans2;
void include1() {
	bool safe = true;
	rep(i, n) {
		if (a[i] == 1)ans1.push_back(1);
		else if(safe){
			if (isp[1 + a[i]]) {
				ans1.push_back(a[i]);
				safe = false;
			}
		}
	}
}
void exclude1() {
	rep(i, n) {
		Rep(j, i + 1, n) {
			if (isp[a[i] + a[j]]) {
				ans2.push_back(a[i]);
				ans2.push_back(a[j]);
				return;
			}
		}
	}
	ans2.push_back(a[0]);
}
void out(vector<int> &v) {
	cout << v.size() << endl;
	rep(i, v.size()) {
		if (i > 0)cout << " ";
		cout << v[i];
	}
	cout << endl;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	init();
	cin >> n;
	rep(i, n) {
		cin >> a[i];
	}
	include1();
	exclude1();
	if (ans1.size() > ans2.size())out(ans1);
	else out(ans2);
	return 0;
}