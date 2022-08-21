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
typedef long double ld;
const ld INF = (ld)10000000000000;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s, t; cin >> s >> t;
	int le = stoi(s.substr(0, 2));
	int ri = stoi(s.substr(3, 2));
	int x1 = le * 60 + ri;
	le = stoi(t.substr(0, 2));
	ri = stoi(t.substr(3, 2));
	int x2 = le * 60 + ri;
	int mid = (x1 + x2) / 2;
	int l = mid / 60, r = mid % 60;
	if (l < 10)cout << "0"; cout << l; cout << ":"; if (r < 10)cout << "0"; cout << r << endl;
	//stop
		return 0;
}