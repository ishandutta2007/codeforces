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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)

int n,a[300005];
int best[300005][8][2][2];
ll dp[300005][2];
int cut[300005][8][2][2];
P1 prv[300005][2];
int main(){
	scanf("%d",&n);
	repn(i,n){
		scanf("%d",&a[i]);
	}
	rep(i,300005)rep(j,8)rep(x,2)rep(y,2){
		best[i][j][x][y] = -INF;
		dp[i][x] = -INF;
	}
	repn(i,n){
		for(int j=1;j<=6&&i+j-1<=n;j++){
			ll sum[2]={};
			for(int x=i;x<=i+j-1;x++){
				sum[x%2]+=a[x];
			}
			for(int x=i;x<=i+j-1;x++){
				if(sum[x%2]<sum[1-x%2]) continue;
				ll w=a[x]-sum[x%2]+sum[1-x%2];
				ll v=0;
				for(int y=i;y<=i+j-1;y++){
					v*=-1;
					if(y!=x) v+=a[y];
					else v+=w;
					if(v<0) goto plz;
				}
				if(v!=0) goto plz;
				if(best[i][j][(x==i)][(x==i+j-1)]<sum[x%2]-sum[1-x%2]){
					best[i][j][(x==i)][(x==i+j-1)]=sum[x%2]-sum[1-x%2];
					cut[i][j][(x==i)][(x==i+j-1)]=x;
				}
				plz:;;
			}
		}
	}
	dp[0][0] = 0;
	rep(i,n)rep(j,2){
		if(dp[i][j]<0) continue;
		for(int k=1;i+k<=n&&k<=6;k++){
			rep(b,2)rep(c,2){
				if(best[i+1][k][b][c]<0) continue;
				if(j&&b) continue;
				if(dp[i+k][c]<dp[i][j]+best[i+1][k][b][c]){
					dp[i+k][c]=dp[i][j]+best[i+1][k][b][c];
					prv[i+k][c]=mp(b,mp(i,j));
				}
			}
		}
	}
	pair<ll,pair<int,int> >ans;
	rep(j,2) ans=max(ans,make_pair(dp[n][j],make_pair(n,j)));
	int X=ans.sc.fi,Y=ans.sc.sc;
	vector<int>use;
	while(make_pair(X,Y)!=make_pair(0,0)){
		int b=prv[X][Y].fi, i=prv[X][Y].sc.fi, j=prv[X][Y].sc.sc;
		int k=X-i, c=Y;
		for(int q=i+1;q<cut[i+1][k][b][c];q++)
		{
			if(a[q]==0||a[q+1]==0)continue;
			use.pb(q);
			int V=min(a[q],a[q+1]);
			a[q]-=V;
			a[q+1]-=V;
		}
		for(int q=i+k-1;q>=cut[i+1][k][b][c];q--)
		{
			if(a[q]==0||a[q+1]==0)continue;
			use.pb(q);
			int V=min(a[q],a[q+1]);
			a[q]-=V;
			a[q+1]-=V;
		}
		X=i;Y=j;
	}
	printf("%d\n",use.size());
	rep(i,use.size()){
		printf("%d\n",use[i]);
	}
}