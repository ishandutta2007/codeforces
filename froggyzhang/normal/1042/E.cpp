#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
#define N 1010
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
int a[N][N],n,tot,f[N*N],inv[N*N],dx,dy,m;
pair<int,int> d[N*N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			a[i][j]=read();
			d[++tot]=make_pair(i,j);
		}
	}
	dx=read(),dy=read();
	sort(d+1,d+tot+1,[](pair<int,int> x,pair<int,int> y){return a[x.first][x.second]<a[y.first][y.second];});
	inv[1]=1;
	for(int i=2;i<=tot;++i){
		inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
	}
	int sx=0,sy=0,sxx=0,syy=0,sum=0; 
	for(int i=1,j=0;i<=tot;i=j){
		j=i;
		while(a[d[j].first][d[j].second]==a[d[j-1].first][d[j-1].second]||j==i){
			int x=d[j].first,y=d[j].second;
			f[j]=1LL*inv[i-1]*((sxx+syy-2LL*x*sx-2LL*y*sy+1LL*(i-1)*(x*x+y*y)%mod+sum)%mod+mod)%mod;
			if(x==dx&&y==dy){
				printf("%d\n",f[j]);
				return 0;
			}
			++j;
		}
		j=i;
		while(a[d[j].first][d[j].second]==a[d[j-1].first][d[j-1].second]||j==i){
			int x=d[j].first,y=d[j].second;
			sxx=(sxx+x*x)%mod;
			syy=(syy+y*y)%mod;
			sx=(sx+x)%mod;
			sy=(sy+y)%mod;
			sum=(sum+f[j])%mod;
			++j;
		}
	}
	return 0;
}