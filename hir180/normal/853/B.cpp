#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
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
int n,m,k;
vector<P>in[1000005],out[1000005];
ll sum[1000005],sum2[1000005];
ll curmin[100005];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,m){
		int d,f,t,c; scanf("%d%d%d%d",&d,&f,&t,&c);
		if(t == 0){
			in[d].pb(mp(f,c));
		}
		else{
			out[d].pb(mp(t,c));
		}
	}
	repn(i,n) curmin[i] = 1000000000000LL;
	sum[0] = 1000000000000LL*n;
	for(int i=1;i<=1000000;i++){
		sum[i] = sum[i-1];
		for(int j=0;j<in[i].size();j++){
			int who = in[i][j].fi;
			int cs = in[i][j].sc;
			if(curmin[who] > cs){
				sum[i] -= (curmin[who]-1LL*cs);
				curmin[who] = 1LL*cs;
			}
		}
	}
	repn(i,n) curmin[i] = 1000000000000LL;
	sum2[1000001] = 1000000000000LL*n;
	for(int i=1000000;i>=1;i--){
		sum2[i] = sum2[i+1];
		for(int j=0;j<out[i].size();j++){
			int who = out[i][j].fi;
			int cs = out[i][j].sc;
			if(curmin[who] > cs){
				sum2[i] -= (curmin[who]-1LL*cs);
				curmin[who] = 1LL*cs;
			}
		}
	}
	ll ans = 1e18;
	for(int i=1;i<=1000000-k-1;i++){
		ans = min(ans,sum[i]+sum2[i+k+1]);
	}
	if(ans >= 1000000000000LL){
		puts("-1");
	}
	else{
		cout<<ans<<endl;
	}
}