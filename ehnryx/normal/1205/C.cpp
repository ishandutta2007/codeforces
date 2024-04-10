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

	int n;
	cin>>n;
	int a[n+1][n+1];
	memset(a,-1,sizeof a);
	a[1][1] = 1;
	a[n][n] = 0;

	{
		int u,v;
		cout<<"? 1 2 2 3" << endl;
		cin>>u;
		assert(u!=-1);
		cout<<"? 2 1 2 3" << endl;
		cin>>v;
		assert(v!=-1);
		if(u==v) {
			a[1][2]=a[2][1]=1;
		} else {
			a[1][2]=1;
			a[2][1]=0;
		}
		if(u) {
			a[2][3]=a[1][2];
		} else {
			a[2][3]=!a[1][2];
		}
	}

	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(a[i][j]!=-1) continue;
			int pi,pj;
			if(i>2) { pi=i-2; pj=j; }
			else if(j>2) { pi=i; pj=j-2; }
			else { pi=i-1; pj=j-1; }
			cout<<"? " << pi << " " << pj << " " << i << " " << j << endl;
			int r;
			cin>>r;
			assert(r!=-1);
			if(r) {
				a[i][j]=a[pi][pj];
			} else {
				a[i][j]=!a[pi][pj];
			}
		}
	}

	int ok = -1;
	int swapped = 0;
	for(int i=1;i<n;i+=2) {
		if(a[i][i]==1&&a[i+2][i+2]==0) {
			redo:
			if(a[i][i]==a[i+1][i+2] &&
				(a[i][i+1]==a[i+1][i+1]||a[i][i+1]==a[i][i+2]||a[i+1][i]==a[i+1][i+1])) {
				cout<<"? " << i << " " << i << " " << i+1 << " " << i+2 << endl;
				cin>>ok;
				assert(ok!=-1);
			} else if(a[i][i]==a[i+2][i+1] &&
				(a[i][i+1]==a[i+1][i+1]||a[i+1][i]==a[i+2][i]||a[i+1][i]==a[i+1][i+1])) {
				cout<<"? " << i << " " << i << " " << i+2 << " " << i+1 << endl;
				cin>>ok;
				assert(ok!=-1);
			} else if(a[i+2][i+2]==a[i][i+1] &&
				(a[i][i+2]==a[i+1][i+2]||a[i+1][i+1]==a[i+2][i+1]||a[i+1][i+1]==a[i+1][i+2])) {
				cout<<"? " << i << " " << i+1 << " " << i+2 << " " << i+2 << endl;
				cin>>ok;
				assert(ok!=-1);
			} else if(a[i+2][i+2]==a[i+1][i] && 
				(a[i+2][i]==a[i+2][i+1]||a[i+1][i+1]==a[i+2][i+1]||a[i+1][i+1]==a[i+1][i+2])) {
				cout<<"? " << i+1 << " " << i << " " << i+2 << " " << i+2 << endl;
				cin>>ok;
				assert(ok!=-1);
			} else {
				swapped = true;
				for(int i=1;i<=n;i++) {
					for(int j=1;j<=n;j++) {
						if((i+j)%2==1) a[i][j]=!a[i][j];
					}
				}
				cerr<<"redo"<<nl;
				goto redo;
			}
			break;
		}
	}

	cout<<"!"<<endl;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if((i+j)%2==1) {
				if(ok) cout<<a[i][j];
				else cout<<!a[i][j];
			} else {
				cout<<a[i][j];
			}
		}
		cout<<endl;
	}

	return 0;
}