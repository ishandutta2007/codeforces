#include<bits/stdc++.h>
using namespace std;
#ifdef flukehn
#define debug(...) fprintf(stderr,__VA_ARGS__)
#else
#define debug(...)
#endif

const int N=511;

int n,K;
int f[N][N],g[N][N];
int main(){
#ifdef flukehn
	freopen(".in","r",stdin);
#endif
	scanf("%d%d",&n,&K);
	f[0][0]=1;
	for(;n--;){
		int x;
		scanf("%d",&x);
		swap(f,g);
		memcpy(f,g,sizeof f);
		for(int i=x;i<=K;++i){
			for(int j=0;j<=i;++j){
				f[i][j]|=g[i-x][j];
				if(j>=x)f[i][j]|=g[i-x][j-x];
			}
		}
	}
	int ans=0;
	for(int i=0;i<=K;++i)if(f[K][i])++ans;
	printf("%d\n",ans);
	for(int i=0;i<=K;++i)if(f[K][i])printf("%d ",i);
}