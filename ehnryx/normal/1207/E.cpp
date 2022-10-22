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



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	cout<<"? ";
	for(int i=0;i<100;i++) {
		cout<<i<<" ";
	}
	cout<<endl;

	int n;
	cin>>n;
	assert(n!=-1);
	vector<int> v;
	for(int i=0;i<100;i++) {
		v.push_back(i^n);
	}

	const int C = 1<<14;
	unordered_map<int,int> val;
	vector<int> q;
	for(int i=100;i<C&&q.size()<100;i++) {
		bool ok = true;
		vector<pii> cur;
		for(int j:v) {
			if(val.count(j^i)) {
				ok = false;
				break;
			}
			cur.push_back(pii(j^i,j));
		}
		if(ok) {
			for(pii it:cur) {
				val.insert(it);
			}
			q.push_back(i);
		}
	}
	assert(q.size()==100);

	cout<<"? ";
	for(int i:q) {
		cout<<i<<" ";
	}
	cout<<endl;

	cin>>n;
	assert(n!=-1);
	cout<<"! "<<val[n]<<endl;

	return 0;
}