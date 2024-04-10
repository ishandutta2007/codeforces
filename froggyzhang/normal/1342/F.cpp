#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 16
const int inf=0x3f3f3f3f;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,T,tot,a[N],vis[N]; 
int sum[1<<N];
int dp[N][N][1<<N];
pair<pair<int,int>,int> from[N][N][1<<N];
void dfs(int i,int p,int k){
	if(!i)return;
	dfs(from[i][p][k].first.first,from[i][p][k].first.second,from[i][p][k].second);
	int S=k^from[i][p][k].second;
	while("I love myh forever!"){
		bool ok=false;
		int cnt=0;
		int pp=0;
		for(int j=1;j<=n;++j){
			if(!vis[j])++pp;
			if(j==p)break;
		}
		for(int j=1;j<=n;++j){
			if(!vis[j])++cnt;
			else continue;
			if(j^p&&(S>>(j-1))&1){
				printf("%d %d\n",cnt,pp);
				vis[j]=1;ok=true;break;
			}
		}
		if(!ok)break;
	}
}
void Solve(){
	for(int i=0;i<=n;++i){
		vis[i]=0;
		for(int j=0;j<=n;++j){
			for(int k=0;k<=tot;++k){
				dp[i][j][k]=inf;
			}
		}
	}
	dp[0][0][0]=0;
	for(int i=0;i<n;++i){
		for(int p=0;p<n;++p){
			for(int k=0;k<=tot;++k){
				if(dp[i][p][k]>=inf)continue;
				int S=tot^k;
				for(int g=S;g;g=(g-1)&S){
					if((sum[g]>dp[i][p][k])&&(g>>p)){
						int np=p+1+__builtin_ctz(g>>p);
						if(dp[i+1][np][g|k]>sum[g]){
							from[i+1][np][g|k]=make_pair(make_pair(i,p),k);
							dp[i+1][np][g|k]=sum[g];
						}
					}
				}
			}
		}
	}
	for(int i=n;i>=1;--i){
		for(int p=1;p<=n;++p){
			if(dp[i][p][tot]<inf){
				printf("%d\n",n-i);
				dfs(i,p,tot);
				return ;
			}
		}
	}
}
int main(){
	T=read();
	while(T--){
		n=read(),tot=(1<<n)-1;
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		for(int i=0;i<=tot;++i){
			sum[i]=0;
			for(int j=1;j<=n;++j){
				if((i>>(j-1))&1)sum[i]+=a[j];
			}
		}
		Solve();
	}
	return 0;
}