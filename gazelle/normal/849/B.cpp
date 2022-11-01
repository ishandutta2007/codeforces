#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-8
#define rep(i,m) for(long long i=0; i<m; ++i)
#define repp(i,n,m) for(long long i=n; i<m; ++i)
#define all(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef vector<long long> vl;
typedef vector<vector<long long> > vll;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vl y(n);
	rep(i,n) cin>>y[i];
	bool d=false;
	ll dx=0,dy=0;
	rep(i,n) {
		if(i==0) {
			ll dx=1,dy=y[2]-y[1];
			vector<bool> used(n);
			used[1]=true;
			used[2]=true;
			rep(j,n) {
				ll ddx=j-1,ddy=y[j]-y[1];
				if(ddy*dx==dy*ddx) used[j]=true;
			}
			bool e=true;
			repp(j,1,n) {
				e=e&used[j];
			}
			if(e&&!used[0]) d=true;
		} else {
			dx=i;
			dy=y[i]-y[0];
			vector<bool> used(n);
			used[0]=true;
			rep(j,n) {
				if(j==0) continue;
				ll ddx=j,ddy=y[j]-y[0];
				if(ddy*dx==dy*ddx) used[j]=true;
			}
			ll ai=-1;
			ll bi=-1;
			rep(j,n) {
				if(!used[j]&&ai==-1) ai=j;
				else if(!used[j]&&bi==-1) bi=j;
			}
			if(ai==-1) continue;
			if(bi==-1) {
				d=true;
				break;
			}
			bool e=true;
			ll ddx=bi-ai,ddy=y[bi]-y[ai];
			if(ddx*dy!=ddy*dx) continue;
			used[ai]=true;
			rep(j,n) {
				if(!used[j]) {
					ll dddx=j-ai,dddy=y[j]-y[ai];
					if(dddy*ddx==ddy*dddx) continue;
					else {
						e=false;
						break;
					}
				}
			}
			if(e) {
				d=true;
			}
		}
	}
	if(d) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}