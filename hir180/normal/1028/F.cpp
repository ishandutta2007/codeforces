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
int n;
vector<ll>za;
vector<P>tb[200005];
int id[200005],x[200005],y[200005];
vector<pair<double,P> >ang;
bool cmp(const pair<double,P>&aa,const pair<double,P>&bb){
	//a.sc/a.fi < b.sc/b.fi?
	P a = aa.sc, b = bb.sc;
	ll X = 1LL*a.sc*b.fi;
	ll Y = 1LL*b.sc*a.fi;
	return X < Y;
}
ll ans[200005];
vector<int>used[200005];
int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%d%d%d",&id[i],&x[i],&y[i]);
		if(id[i] == 1){
			za.pb(1LL*x[i]*x[i]+1LL*y[i]*y[i]);
		}
		else if(id[i] == 3){
			int a = __gcd(x[i],y[i]);
			x[i] /= a; y[i] /= a;
			ang.pb(mp(0,mp(x[i],y[i])));
		}
	}
	SORT(za); ERASE(za);
	sort(ang.begin(),ang.end(),cmp); ERASE(ang);
	rep(i,ang.size()){
		ang[i].fi = atan2((double)ang[i].sc.sc,(double)ang[i].sc.fi);
	}
	rep(i,n){
		if(id[i] == 1){
			int yy = POSL(za,(1LL*x[i]*x[i]+1LL*y[i]*y[i]));
			tb[yy].pb(mp(x[i],y[i]));
		}
	}
	rep(i,za.size()){
		SORT(tb[i]); ERASE(tb[i]);
		used[i].resize(tb[i].size(),0);
	}
	int cur = 0;
	rep(i,n){
		if(id[i] == 1){
			int yy = POSL(za,(1LL*x[i]*x[i]+1LL*y[i]*y[i]));
			int id;
			for(int xx=0;xx<tb[yy].size();xx++){
				if(P(x[i],y[i]) == tb[yy][xx]){
					id = xx;
					double md = atan2( (double)y[i], (double)x[i] ) ;
					int xw = POSL(ang,mp(md,mp(-1,-1)));
					for(int w=max(0,xw-3);w<xw+3 && w<ang.size();w++){
						//(x[i],y[i]) (ang[w].sc)
						ll X = ang[w].sc.fi, Y = ang[w].sc.sc;
						ll XX = x[i], YY = y[i];
						if(X*YY-XX*Y == 0){
							ans[w]++;
						}
					}
					continue;
				}
				if(used[yy][xx] == 0) continue;
				//mp(x[i],y[i])tb[yy][x]ang?
				double md = (atan2( (double)y[i], (double)x[i] ) + atan2( (double)tb[yy][xx].sc, (double)tb[yy][xx].fi ))/2.0;
				int xw = POSL(ang,mp(md,mp(-1,-1)));
				for(int w=max(0,xw-3);w<xw+3 && w<ang.size();w++){
					//(x[i],y[i]) tb[yy][x] (ang[w].sc)
					ll X = ang[w].sc.fi, Y = ang[w].sc.sc;
					ll XX = x[i]-tb[yy][xx].fi, YY = y[i]-tb[yy][xx].sc;
					if(X*XX+Y*YY == 0){
						ans[w]+=2;
					}
				}
			}
			used[yy][id] = 1; cur++;
		}
		else if(id[i] == 2){
			int yy = POSL(za,(1LL*x[i]*x[i]+1LL*y[i]*y[i]));
			int id;
			for(int xx=0;xx<tb[yy].size();xx++){
				if(P(x[i],y[i]) == tb[yy][xx]){
					id = xx;
					double md = atan2( (double)y[i], (double)x[i] ) ;
					int xw = POSL(ang,mp(md,mp(-1,-1)));
					for(int w=max(0,xw-3);w<xw+3 && w<ang.size();w++){
						//(x[i],y[i]) (ang[w].sc)
						ll X = ang[w].sc.fi, Y = ang[w].sc.sc;
						ll XX = x[i], YY = y[i];
						if(X*YY-XX*Y == 0){
							ans[w]--;
						}
					}
					continue;
				}
				if(used[yy][xx] == 0) continue;
				//mp(x[i],y[i])tb[yy][x]ang?
				double md = (atan2( (double)y[i], (double)x[i] ) + atan2( (double)tb[yy][xx].sc, (double)tb[yy][xx].fi ))/2.0;
				int xw = POSL(ang,mp(md,mp(-1,-1)));
				for(int w=max(0,xw-3);w<xw+3 && w<ang.size();w++){
					//(x[i],y[i]) tb[yy][x] (ang[w].sc)
					ll X = ang[w].sc.fi, Y = ang[w].sc.sc;
					ll XX = x[i]-tb[yy][xx].fi, YY = y[i]-tb[yy][xx].sc;
					if(X*XX+Y*YY == 0){
						ans[w]-=2;
					}
				}
			}
			used[yy][id] = 0; cur--;
		}
		else{
			double v = atan2((double)y[i],(double)x[i]);
			int f = POSL(ang,mp(v,mp(x[i],y[i])));
			int id;
			for(int w=max(0,f-3);w<f+3 && w<ang.size();w++){
					ll X = ang[w].sc.fi, Y = ang[w].sc.sc;
					if(X == x[i] && Y == y[i]){
						id = w; break;
					}
				
			}
			printf("%lld\n",cur-ans[id]);
		}
	}
}