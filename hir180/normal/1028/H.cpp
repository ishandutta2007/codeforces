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

int n,q,a[200005];
vector<P>pos[6000005];
int mn[6000005][8];
vector<int>prr[200005];
int cur[15];
vector<P>query[200005];
int res[2000005];

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=q;i++){
	    int L,R;
		scanf("%d%d",&L,&R);
		query[R].pb(mp(L,i));
	}
	for(int i=1;i<=n;i++){
		vector<int>pr;
		for(int j=2;j*j<=a[i];j++){
			if(a[i]%j == 0){
				int c = 0;
				while(a[i]%j == 0){
					a[i] /= j;
					c ++;
				}
				if(c%2 == 1) pr.pb(j);
			}
		}
		if(a[i] != 1) pr.pb(a[i]);
		prr[i] = pr;
	}
	rep(i,15) cur[i] = -INF;
	for(int i=1;i<=n;i++){
		int ans[25]={};
		rep(j,25) ans[j] = -INF;
		int sz = prr[i].size();
		rep(mask,(1<<sz)){
			int M = 1;
			rep(ii,sz) if(((mask>>ii)&1)) M *= prr[i][ii];
			rep(i,8){
				if(mn[M][i]){
					ans[i+sz-2*__builtin_popcount(mask)] = max(ans[i+sz-2*__builtin_popcount(mask)],mn[M][i]);
				}
			}
		}
		rep(ii,12){
			if(1){
				cur[ii] = max(cur[ii],ans[ii]);
			}
		}
		rep(j,query[i].size()){
			int en = query[i][j].fi, id = query[i][j].sc;
			res[id] = INF;
			rep(k,12){
				if(cur[k] >= en) res[id] = min(res[id],k);
			}
		}
		rep(mask,(1<<sz)){
			int M = 1;
			rep(ii,sz) if(((mask>>ii)&1)) M *= prr[i][ii];
			mn[M][sz] = i;
		}
	}
	repn(i,q) printf("%d\n",res[i]);
}