#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 2333
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
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
int n,k,dp[N][N],mx,vis[N][N];
vector<pair<int,int> > A,B;
char s[N][N];
const int d[2][2]={{1,0},{0,1}};
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i){
		scanf("%s",s[i]+1);
	}
	memset(dp,0x3f,sizeof(dp));
	dp[1][1]=s[1][1]!='a';
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==1&&j==1)continue;
			dp[i][j]=min(dp[i-1][j],dp[i][j-1])+(s[i][j]!='a');
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(dp[i][j]<=k)mx=max(mx,i+j);
		}
	}
	mx=min(mx,n+n);
	for(int i=1;i<=mx-1;++i)putchar('a');
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(dp[i][j]<=k&&mx==i+j){
				A.push_back({i,j});
			}
		}
	}
	if(!mx){
		A.push_back({0,1});
		mx=1;
	}
	for(int i=mx+1;i<=n+n;++i){
		char mn='z';
		B.clear();
		for(auto [x,y]:A){
			for(int p=0;p<2;++p){
				int nx=x+d[p][0],ny=y+d[p][1];
				if(nx<1||ny<1||nx>n||ny>n)continue;
				mn=min(mn,s[nx][ny]);
			}
		}
		putchar(mn);
		for(auto [x,y]:A){
			for(int p=0;p<2;++p){
				int nx=x+d[p][0],ny=y+d[p][1];
				if(nx<1||ny<1||nx>n||ny>n)continue;
				if(mn==s[nx][ny]&&!vis[nx][ny]){
					B.push_back({nx,ny});
					vis[nx][ny]=1;
				}
			}
		}
		swap(A,B);
	}
	return 0;
}