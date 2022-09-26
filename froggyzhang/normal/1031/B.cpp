#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100010
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
int n,a[N],b[N];
bool dp[N][4];
void dfs(int u,int x){
	if(u>=0){
	for(int y=0;y<=3;++y){
		if((x|y)==a[u]&&(x&y)==b[u]&&dp[u-1][y]){
			dfs(u-1,y);
			break;
		}
	}
	}
	printf("%d ",x);
}
int main(){
	n=read()-1;
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		b[i]=read();
	}
	for(int i=0;i<=3;++i)dp[0][i]=true;
	for(int i=1;i<=n;++i){
		for(int x=0;x<=3;++x){
			for(int y=0;y<=3;++y){
				if((x|y)==a[i]&&(x&y)==b[i]){
					dp[i][x]|=dp[i-1][y];
				}
			}
		}
	}
	for(int x=0;x<=3;++x){
		if(dp[n][x]){
			puts("YES");
			dfs(n,x);
			return 0;
		}
	}
	puts("NO");
	return 0;
}