#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// DON'T USE THESE MACROS DURING ICPC PRACTICE
#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+1;
int cnt[N], last[N];

int root[N];
int find(int i) {
	if(root[i] == -1) return i;
	return root[i] = find(root[i]);
}
int link(int i, int j) {
	i=find(i); j=find(j);
	if(i==j) return false;
	last[j] = max(last[j],last[i]);
	root[i] = j;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	memset(root,-1,sizeof root);

	int n,q;
	cin>>n>>q;
	int a[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
		cnt[a[i]]++;
		last[a[i]] = i;
	}

	unordered_set<int> cur;
	set<pii> big;
	int ans = 0;
	for(int i=0;i<n;i++) {
		int v = find(a[i]);
		cur.insert(v);
		big.insert({cnt[v],v});
		if(i==last[v]) {
			int to = -1;
			for(pii it:big) {
				if(cur.count(it.second)) {
					to = it.second;
				}
			}
			assert(to!=-1);
			for(auto it=big.begin();it!=big.end()&&next(it)!=big.end();) {
				if(it->second != to && cur.count(it->second)) {
					ans += it->first;
					link(it->second,to);
				}
				it = big.erase(it);
			}
			cur.erase(v);
		}
	}
	cout<<ans<<nl;

	return 0;
}