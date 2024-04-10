#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e2+1;
string g[N];
char ans[N][N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	vector<char> c;
	for(int i=0;i<26;i++) {
		c.push_back(i+'a');
		c.push_back(i+'A');
	}
	for(int i=0;i<10;i++) {
		c.push_back(i+'0');
	}

	int T;
	cin>>T;
	while(T--) {
		int n,m,k;
		cin>>n>>m>>k;

		int rice = 0;
		for(int i=0;i<n;i++) {
			cin>>g[i];
			for(int j=0;j<m;j++) {
				rice += (g[i][j] == 'R');
			}
		}

		int lb = rice / k;
		int ubcnt = rice - lb*k;
		//cerr<<"lb: "<<lb<<nl;
		//cerr<<"ubcnt "<<ubcnt<<nl;
		int cur = 0;
		int id = 0;
		for(int i=0;i<n;i++) {
			if(i%2) {
				for(int j=0;j<m;j++) {
					cur += (g[i][j] == 'R');
					if((id < ubcnt && cur > lb+1) || (id >= ubcnt && cur > lb)) {
						id++;
						cur = 1;
					}
					ans[i][j] = c[id];
				}
			} else {
				for(int j=m-1;j>=0;j--) {
					cur += (g[i][j] == 'R');
					if((id < ubcnt && cur > lb+1) || (id >= ubcnt && cur > lb)) {
						id++;
						cur = 1;
					}
					ans[i][j] = c[id];
				}
			}
		}
		//cerr<<"id: "<<id<<nl;
		assert(id == k-1);

		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				cout<<ans[i][j];
			}
			cout<<nl;
		}
		//cerr<<nl;
	}

	return 0;
}