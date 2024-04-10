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
//#define revstr(s) reverse(s.begin(),s.end())
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;

int par[200000];
int rank1[200000];
int sum[200000];
void init(int n) {
	for (int i = 0; i < n; i++) {
		par[i] = i;
		rank1[i] = 0;
		sum[i] = 1;
	}
}
int find(int x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	if (rank1[x] < rank1[y]) {
		par[x] = y; sum[y] += sum[x];
	}
	else {
		par[y] = x; sum[x] += sum[y];
		if (rank1[x] == rank1[y])rank1[x]++;
	}
}
bool same(int x, int y) {
	return find(x) == find(y);
}
int val(int x) {
	return sum[find(x)];
}
int a[1 << 18]; int n;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n; init(n);
	vector<P> v;
	rep(i, n) {
		cin >> a[i]; v.push_back({ a[i],i });
	}
	sort(v.begin(), v.end());
	string ans = "YES";
	rep(i,v.size()) {
		queue<int> q; q.push(v[i].second);
		while (i + 1 < v.size() && v[i + 1].first == v[i].first) {
			i++; q.push(v[i].second);
		}
		queue<int> nq;
		while (!q.empty()) {
			int id = q.front(); nq.push(id); q.pop();
			if (id - 1 >= 0 && a[id - 1] <= a[id])unite(id - 1, id);
			if (id + 1 < n&&a[id + 1] <= a[id])unite(id, id + 1);
		}
		while (!nq.empty()) {
			int id = nq.front(); nq.pop();
			if (val(id) % 2&&val(id)!=n)ans = "NO";
		}
	}
	cout << ans << endl;
	return 0;
}