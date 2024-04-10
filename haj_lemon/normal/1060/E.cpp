#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Info{int nu,ne;}a[400010];
struct dp{ll le;int su;}dp[200010][2];
int n,x,y,num,b[200010];
ll ansn;
void jb(int x,int y){a[++num].nu=y;a[num].ne=b[x];b[x]=num;}
void dfs(int x,int fa){
	dp[x][0].su=1;dp[x][0].le=0;dp[x][1].le=dp[x][1].su=0;
	for (int y=b[x];y;y=a[y].ne){
		if (a[y].nu!=fa){
			dfs(a[y].nu,x);
			dp[x][0].su+=dp[a[y].nu][1].su;
			dp[x][0].le+=dp[a[y].nu][1].le+dp[a[y].nu][1].su;
			dp[x][1].su+=dp[a[y].nu][0].su;
			dp[x][1].le+=dp[a[y].nu][0].le+dp[a[y].nu][0].su;
		}
	}
}
void dfs1(int x,int fa){
	if (fa!=0){
		dp[0][0]=dp[fa][0];dp[0][1]=dp[fa][1];
		dp[0][0].su-=dp[x][1].su;
		dp[0][0].le-=dp[x][1].le+dp[x][1].su;
		dp[0][1].su-=dp[x][0].su;
		dp[0][1].le-=dp[x][0].le+dp[x][0].su;
		dp[x][0].su+=dp[0][1].su;
		dp[x][0].le+=dp[0][1].le+dp[0][1].su;
		dp[x][1].su+=dp[0][0].su;
		dp[x][1].le+=dp[0][0].le+dp[0][0].su;
	}
	ansn=ansn+dp[x][0].le/2+(dp[x][1].le-dp[x][1].su)/2+dp[x][1].su;
	for (int y=b[x];y;y=a[y].ne){
		if (a[y].nu!=fa){
			dfs1(a[y].nu,x);
		}
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		scanf("%d %d",&x,&y);
		jb(x,y);jb(y,x);
	}
	dfs(1,0);
	dfs1(1,0);
	cout<<ansn/2<<endl;
	return 0;
}