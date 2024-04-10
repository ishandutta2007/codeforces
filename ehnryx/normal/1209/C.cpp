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
int val[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		string s;
		cin>>s;
		bool done = false;
		for(int v=0;v<=9;v++) {
			fill(val,val+n,0);
			bool ok = true;
			int last = -1;
			int pre = 0;
			for(int i=0;i<n;i++) {
				if(s[i]-'0'<v) {
					val[i] = 1;
					last = i;
					ok &= (s[i] >= pre);
					pre = s[i];
				}
			}
			for(int i=last+1;i<n;i++) {
				if(s[i]-'0'==v) {
					val[i] = 1;
				}
			}
			last = n;
			pre = '9'+1;
			for(int i=n-1;i>=0;i--) {
				if(s[i]-'0'>v) {
					val[i] = 2;
					last = i;
					ok &= (s[i] <= pre);
					pre = s[i];
				}
			}
			for(int i=last-1;i>=0;i--) {
				if(s[i]-'0'==v) {
					val[i] = 2;
				}
			}
			for(int i=0;i<n;i++) {
				ok &= (val[i] != 0);
			}
			if(ok) {
				for(int i=0;i<n;i++) {
					cout<<val[i];
				}
				cout<<nl;
				done = true;
				break;
			}
		}
		if(!done) {
			cout<<'-'<<nl;
		}
	}

	return 0;
}