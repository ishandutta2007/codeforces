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
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 3e5+1;
const int L = 19;
int minv[N][L];
void build() {
	for(int j=1;j<L;j++) {
		for(int i=0;i+(1<<j)-1<N;i++) {
			minv[i][j] = min(minv[i][j-1], minv[i+(1<<(j-1))][j-1]);
		}
	}
}
int query(int l, int r) {
	int j = 31 - __builtin_clz(r-l+1);
	return min(minv[l][j], minv[r-(1<<j)+1][j]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
		minv[i][0] = minv[i+n][0] = minv[i+n+n][0] = a[i];
	}
	build();

	int rb[n];
	for(int i=0;i<n;i++) {
		int l = i;
		int r = 3*n;
		while(l<r) {
			int m = (l+r)/2;
			if(2*query(i,m) < a[i]) {
				r = m;
			} else {
				l = m+1;
			}
		}
		rb[i] = l;
		//cerr<<i<<" -> "<<rb[i]<<nl;
	}

	for(int i=0;i<n;i++) {
		for(int j=0;j<3;j++) {
			minv[i+j*n][0] = rb[i] + j*n;
		}
	}
	build();

	int cnt = 0;
	for(int i=0;i<n;i++) {
		int l = i;
		int r = 3*n;
		while(l<r) {
			int m = (l+r+1)/2;
			//cerr<<"query "<<i<<" "<<m<<" -> "<<query(i,m)<<nl;
			if(query(i,m)>m) {
				l = m;
			} else {
				r = m-1;
			}
		}
		if(l-i>=2*n) {
			cout<<-1<<" ";
			cnt++;
		} else {
			cout<<l-i+1<<" ";
		}
	}
	cout<<nl;
	assert(cnt==0 || cnt==n);


	return 0;
}