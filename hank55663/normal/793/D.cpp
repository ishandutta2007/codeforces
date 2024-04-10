//#include<stdio.h>
//#include<stdlib.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
#define N 200005
#define M
#define pi 3.14159265359
#define count Count
using namespace std;
typedef long long LL;
int dp[85][85][85];
bool cmp(const pair<pii,int> &a,const pair<pii,int> &b){
	if(abs(a.x.x-a.x.y)!=abs(b.x.x-b.x.y))
	return abs(a.x.x-a.x.y)>abs(b.x.x-b.x.y);
	else
	return min(a.x.x,a.x.y)<min(b.x.x,b.x.y);
}
vector<pii> v[85];
int main(){
	int n,K;
	scanf("%d %d",&n,&K);
	for(int i=0;i<85;i++)
		for(int j=0;j<85;j++)
			for(int k=0;k<85;k++)
					dp[i][j][k]=1e9;
	for(int i=1;i<=n;i++){
		v[i].clear();
		dp[0][i][1]=dp[n+1][i][1]=0;
		v[i].pb(mp(0,1));
		v[i].pb(mp(n+1,1));
	}
	int m;
	scanf("%d",&m);
	pair<pii,int> p[2005];
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(a==b){
			i--,m--;
			continue;
		}
		p[i]=mp(mp(a,b),c);
	}
	for(int t=0;t<n;t++)
		for(int i=0;i<m;i++){
			if(p[i].x.x<p[i].x.y){
				for(vector<pii>::iterator it=v[p[i].x.x].begin();it!=v[p[i].x.x].end();it++){
					if(it->x<p[i].x.x)
					continue;
					if(it->x>p[i].x.y){
						if(dp[it->x][p[i].x.y][it->y+1]==1e9)
						v[p[i].x.y].pb(mp(it->x,it->y+1));
						dp[it->x][p[i].x.y][it->y+1]=min(dp[it->x][p[i].x.y][it->y+1],dp[it->x][p[i].x.x][it->y]+p[i].y);
						if(dp[p[i].x.x][p[i].x.y][it->y+1]==1e9)
						v[p[i].x.y].pb(mp(p[i].x.x,it->y+1));
						dp[p[i].x.x][p[i].x.y][it->y+1]=min(dp[p[i].x.x][p[i].x.y][it->y+1],dp[it->x][p[i].x.x][it->y]+p[i].y);
					}
				}
			}
			else{
				for(vector<pii>::iterator it=v[p[i].x.x].begin();it!=v[p[i].x.x].end();it++){
					if(it->x>p[i].x.x)
					continue;
					if(it->x<p[i].x.y){
						if(dp[it->x][p[i].x.y][it->y+1]==1e9)
						v[p[i].x.y].pb(mp(it->x,it->y+1));
						dp[it->x][p[i].x.y][it->y+1]=min(dp[it->x][p[i].x.y][it->y+1],dp[it->x][p[i].x.x][it->y]+p[i].y);
						if(dp[p[i].x.x][p[i].x.y][it->y+1]==1e9)
						v[p[i].x.y].pb(mp(p[i].x.x,it->y+1));
						dp[p[i].x.x][p[i].x.y][it->y+1]=min(dp[p[i].x.x][p[i].x.y][it->y+1],dp[it->x][p[i].x.x][it->y]+p[i].y);
					}
				}
			}
		}
	int ans=1e9;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			ans=min(ans,dp[i][j][K]);
	if(ans==1e9)
	printf("-1\n");
	else
	printf("%d\n",ans);
}

/*90 110
180 220
270 330
360 440                
    550           
    660 
630
 7=k70
xy=kx+ky
kx/(x-k)=y 
*/