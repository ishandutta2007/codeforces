#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define N 10010
const int inf=0x3f3f3f3f;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int len,n,A,B,id[N],L[N],R[N],siz[N],dp[N][103][2],ans;
char s[N];
vector<int> G[N];
void dfs1(int u){
	if(G[u].empty())return;
	siz[u]=1;
	for(int i=0;i<=A;++i){
		dp[u][i][0]=inf,dp[u][i][1]=-inf;
	}
	int ls=G[u][0],rs=G[u][1];
	dfs1(ls),dfs1(rs);
	siz[u]+=siz[ls]+siz[rs];
	for(int i=0;i<=siz[ls]&&i<=A;++i){
		for(int j=0;j<=siz[rs]&&i+j<=A;++j){
			// L+R
			dp[u][i+j+1][0]=min(dp[u][i+j+1][0],dp[ls][i][0]+dp[rs][j][0]);
			dp[u][i+j+1][1]=max(dp[u][i+j+1][1],dp[ls][i][1]+dp[rs][j][1]);
			// L-R
			dp[u][i+j][0]=min(dp[u][i+j][0],dp[ls][i][0]-dp[rs][j][1]);
			dp[u][i+j][1]=max(dp[u][i+j][1],dp[ls][i][1]-dp[rs][j][0]);
		}
	}
}
void dfs2(int u){
	if(G[u].empty())return;
	siz[u]=1;
	for(int i=0;i<=B;++i){
		dp[u][i][0]=inf,dp[u][i][1]=-inf;
	}
	int ls=G[u][0],rs=G[u][1];
	dfs2(ls),dfs2(rs);
	siz[u]+=siz[ls]+siz[rs];
	for(int i=0;i<=siz[ls]&&i<=B;++i){
		for(int j=0;j<=siz[rs]&&i+j<=B;++j){
			// L+R
			dp[u][i+j][0]=min(dp[u][i+j][0],dp[ls][i][0]+dp[rs][j][0]);
			dp[u][i+j][1]=max(dp[u][i+j][1],dp[ls][i][1]+dp[rs][j][1]);
			// L-R
			dp[u][i+j+1][0]=min(dp[u][i+j+1][0],dp[ls][i][0]-dp[rs][j][1]);
			dp[u][i+j+1][1]=max(dp[u][i+j+1][1],dp[ls][i][1]-dp[rs][j][0]);
		}
	}
}
int main(){
	scanf("%s",s+1);
	len=strlen(s+1);
	A=read(),B=read();
	for(int i=1;i<=len;++i){
		if(isdigit(s[i])){
			id[i]=++n;
			L[i]=R[i]=i;
			dp[n][0][0]=dp[n][0][1]=s[i]-'0';
		}
	}
	while(!id[1]){
		for(int i=1;i<=len;++i){
			if(!id[i]&&s[i]=='?'&&id[i-1]&&id[i+1]){
				int l=L[i-1]-1,r=R[i+1]+1;
				id[i]=id[l]=id[r]=++n;
				G[n].push_back(id[i-1]);
				G[n].push_back(id[i+1]);
				R[l]=r,L[r]=l;
			}
		}
	}
	if(A<=B){
		dfs1(n);
		ans=dp[n][A][1];
	}
	else{
		dfs2(n);
		ans=dp[n][B][1];
	}
	printf("%d\n",ans);
	return 0;
}