#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#pragma GCC optimize(3)
typedef long long ll;
#define N 20 
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
int n,g[N][N],p[N],cnt0[1<<8][N],cnt1[1<<8][N],vis[N],a[N],mid,vis0[1<<8],vis1[1<<8];
ll ans[1<<20];
char s[N];
inline void Solve(){
	memset(vis,0,sizeof(vis));
	memset(vis0,0,sizeof(vis0));
	memset(vis1,0,sizeof(vis1));
	memset(cnt0,0,sizeof(cnt0));
	memset(cnt1,0,sizeof(cnt1));
	for(int i=1;i<=mid;++i){
		p[i]=a[i];
		vis[a[i]]=1;
	}
	int os=1;
	for(int i=mid+1;i<=n;++i){
		while(vis[os])++os;
		p[i]=os;++os;
	}
	
	do{
		int num=0;
		for(int i=1;i<mid;++i){
			num=(num<<1)+g[p[i]][p[i+1]];
		}
		++cnt0[num][p[mid]];
		vis0[num]=1;
	}while(next_permutation(p+1,p+mid+1));
	do{
		int num=0;
		for(int i=mid+1;i<n;++i){
			num=(num<<1)+g[p[i]][p[i+1]];
		}
		++cnt1[num][p[mid+1]];
		vis1[num]=1;
	}while(next_permutation(p+mid+1,p+n+1));
	int L=(1<<(mid-1))-1,R=(1<<(n-mid-1))-1;
	for(register int i=0;i<=L;++i){
		int l=(i<<(n-mid));
		if(!vis0[i])continue;
		for(int x=1;x<=n;++x){
			if(!cnt0[i][x])continue;
			for(int j=0;j<=R;++j){
				if(!vis1[j])continue;
				for(int y=1;y<=n;++y){
					if(!cnt1[j][y])continue;
					ans[l+g[x][y]*(1<<(n-mid-1))+j]+=cnt0[i][x]*cnt1[j][y];
				}
			}
		}
	}
}
void dfs(int dep,int las){
	if(dep==mid+1){
		Solve();
		return;
	}
	for(int i=las+1;i<=n;++i){
		a[dep]=i;
		dfs(dep+1,i);
	}
}
int main(){
	n=read();mid=n/2;
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=n;j++){
			g[i][j]=s[j]-'0';
		}
		p[i]=i;
	}
	dfs(1,0);
	int all=(1<<(n-1))-1;
	for(register int i=0;i<=all;++i){
		printf("%I64d ",ans[i]); 
	}
	return 0;
}