#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-9
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
using namespace std;
typedef long long LL;
long double dp[2505][2505][2];
int n;
pll p[2505];
long double dis(int a,int b){
	a=(a+n)%n;
	b=(b+n)%n;
	return sqrt(sqr(p[a].x-p[b].x)+sqr(p[a].y-p[b].y));
}
long double DP(int x,int y,int now){
	x=(x+n)%n;
	y=(y+n)%n;
	if(x+1==y||(x==n-1&&y==0)){
		return dis(x,y);
	}
	if(dp[x][y][now]!=0){
		return dp[x][y][now];
	} 
	if(now==0){
		long double ans=max(DP(x+1,y,0)+dis(x+1,x),DP(x+1,y,1)+dis(y,x));
		return dp[x][y][now]=ans;
	}
	else{
		long double ans=max(DP(x,y-1,0)+dis(x,y),DP(x,y-1,1)+dis(y-1,y));
		return dp[x][y][now]=ans;
	}
}
int main(){
//	int n;
	//pii p[5005];
	MEM(dp);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		p[i]=mp(x,y);
	}
	if(n==2){
		cout<<fixed<<setprecision(12)<<dis(0,1)<<endl;
		return 0;
	}
	long double ans=0;
	for(int i=0;i<n;i++){
		ans=max(ans,max(DP(i+1,i,0),DP(i+1,i,1)));
	}
	cout<<fixed<<setprecision(12)<<ans<<endl;
}