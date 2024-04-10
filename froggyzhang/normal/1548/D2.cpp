#include<bits/stdc++.h>
using namespace std;
#define y1 ysgh
#define N 6006
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
int n,cnt[4][4][4],x[N],y[N];
ll eoo,eee;
int g[4][4];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		x[i]=read(),y[i]=read();
	}
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			g[i][j]=i|j?__gcd(i,j):0;		
		}
	}
	for(int i=1;i<=n;++i){
		memset(cnt,0,sizeof(cnt));
		for(int j=1;j<=n;++j){
			if(i==j)continue;
			++cnt[x[j]%4][y[j]%4][abs(__gcd(x[i]-x[j],y[i]-y[j]))%4];
		}
		for(int x1=0;x1<4;++x1){
			for(int y1=0;y1<4;++y1){
				for(int z1=0;z1<4;++z1){
					for(int x2=0;x2<4;++x2){
						for(int y2=0;y2<4;++y2){
							for(int z2=0;z2<4;++z2){
								if((z1+z2)&1)continue;
								int S=(((x1-x[i])*(y2-y[i])-(y1-y[i])*(x2-x[i]))%4+4)%4;
								if(S&1)continue;
								int B=(z1+z2+g[abs(x1-x2)][abs(y1-y2)])%4;
								if(B^S)continue;
								if(z1&1)eoo+=1LL*cnt[x1][y1][z1]*(cnt[x2][y2][z2]-(x1==x2&&y1==y2&&z1==z2));
								else eee+=1LL*cnt[x1][y1][z1]*(cnt[x2][y2][z2]-(x1==x2&&y1==y2&&z1==z2));
							}		
						}
					}
				}		
			}
		}
	}
	printf("%lld\n",eoo/2+eee/6);
	return 0;
}