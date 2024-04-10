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

const int N = 1<<20;
const int M = 3e5+1;
int a[M], b[M];

int st[2*N], z[2*N];

void push(int i) {
	if(z[i]) {
		st[2*i]+=z[i];
		st[2*i+1]+=z[i];
		z[2*i]+=z[i];
		z[2*i+1]+=z[i];
		z[i]=0;
	}
}

void insert(int l, int r, int v, int i=1, int s=0, int e=N-1) {
	if(r<s||e<l) return;
	if(l<=s&&e<=r) {
		st[i]+=v;
		z[i]+=v;
		return;
	}
	push(i);
	int m=(s+e)/2;
	insert(l,r,v,2*i,s,m);
	insert(l,r,v,2*i+1,m+1,e);
	st[i]=max(st[2*i],st[2*i+1]);
}

int query(int l, int r, int i=1, int s=0, int e=N-1) {
	if(r<s||e<l) return -1;
	if(l<=s&&e<=r&&st[i]<=0) return -1;
	if(s==e) return s;
	push(i);
	int m=(s+e)/2;
	int id=query(l,r,2*i+1,m+1,e);
	if(id==-1) id=query(l,r,2*i,s,m);
	return id;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		insert(0,a[i],1);
	}
	for(int i=1;i<=m;i++) {
		cin>>b[i];
		insert(0,b[i],-1);
	}

	int q;
	cin>>q;
	while(q--) {
		int t,i,x;
		cin>>t>>i>>x;
		if(t==1) {
			insert(0,a[i],-1);
			insert(0,a[i]=x,1);
		} else {
			insert(0,b[i],1);
			insert(0,b[i]=x,-1);
		}
		cout<<query(0,N-1)<<nl;
	}

	return 0;
}