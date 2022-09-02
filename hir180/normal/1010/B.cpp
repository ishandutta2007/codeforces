#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define int long long
int n,m;
int lb,ub;
vector<int>ret;
signed main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cout<<1<<endl;fflush(stdout);
		int x; cin>>x; ret.pb(x);
		if(x == 0) exit(0);
	}
	lb=1,ub=n;
	int xx = 0;
	while(1){
		if(lb == ub){
			cout<<lb<<endl;
			int x; cin>>x;
			assert(x==0) ; exit(0);
		}
		if(ret[xx] == 1){
			//true
			int mid = (lb+ub)/2;
			cout<<mid<<endl; fflush(stdout);
			int x; cin>>x;
			if(x == 0) exit(0);
			else if(x == 1) lb=mid+1;
			else ub=mid-1;
		}
		else{
			//false
			int mid = (lb+ub)/2;
			cout<<mid<<endl;fflush(stdout);
			int x; cin>>x;
			if(x == 0) exit(0);
			else if(x == -1) lb=mid+1;
			else ub=mid-1;
		}
		xx = (xx+1)%m;
	}
}