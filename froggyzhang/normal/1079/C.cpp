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
int n,a[N];
bool dp[N][6];
void dfs(int u,int x){
	if(u>1){
		if(a[u]>a[u-1]){
			for(int y=1;y<x;++y){
				if(dp[u-1][y]){
					dfs(u-1,y);
					break;
				}
			}
		}
		else if(a[u]<a[u-1]){
			for(int y=x+1;y<=5;++y){
				if(dp[u-1][y]){
					dfs(u-1,y);
					break;
				}
			}
		}
		else{
			for(int y=1;y<=5;++y){
				if(x==y)continue;
				if(dp[u-1][y]){
					dfs(u-1,y);
					break;
				}
			}
		}
	}
	printf("%d ",x);
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=5;++i){
		dp[1][i]=true;
	}
	for(int i=2;i<=n;++i){
		for(int x=1;x<=5;++x){
			if(a[i]>a[i-1]){
				for(int y=1;y<x;++y){
					dp[i][x]|=dp[i-1][y];
				}
			}
			else if(a[i]<a[i-1]){
				for(int y=x+1;y<=5;++y){
					dp[i][x]|=dp[i-1][y];
				}
			}
			else{
				for(int y=1;y<=5;++y){
					if(x==y)continue;
					dp[i][x]|=dp[i-1][y];
				}
			}
		}
	}
	for(int x=1;x<=5;++x){
		if(dp[n][x]){
			dfs(n,x);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}