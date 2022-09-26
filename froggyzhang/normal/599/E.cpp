#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
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
int x[15],y[15],n,m,q;
ll dp[1<<13][13];
int a[123],b[123],c[123];
int main(){
	n=read(),m=read(),q=read();
	for(int i=1;i<=m;++i){
		x[i]=read()-1,y[i]=read()-1;
	}
	for(int i=1;i<=q;++i){
		a[i]=read()-1,b[i]=read()-1,c[i]=read()-1;
		if(a[i]==b[i]&&a[i]^c[i])return !printf("0\n");
	}
	for(int i=0;i<n;++i){
		dp[1<<i][i]=1;
	}
	for(int i=1;i<(1<<n);++i){
		for(int r1=0;r1<n;++r1){
			if(!(i>>r1&1))continue;
			for(int j=i;j;j=(j-1)&i){
				if(j>>r1&1)continue;
				int ii=i^(1<<r1);
				if((ii&(-ii))!=(j&(-j)))continue;
				bool ok=true;
				int t=i^j;
				for(int k=1;k<=q;++k){
					if(t>>a[k]&1 && j>>b[k]&1 || t>>b[k]&1 && j>>a[k]&1){
						if(c[k]^r1){
							ok=false;break;
						}
					}
				}
				if(!ok)continue;
				int myh=-1;
				for(int k=1;k<=m;++k){
					if(y[k]==r1)swap(x[k],y[k]);
					if(x[k]==r1){
						if(j>>y[k]&1){
							if(~myh){
								ok=false;break;
							}
							myh=y[k];
						}
					}
					else if(t>>x[k]&1 && j>>y[k]&1 || t>>y[k]&1 && j>>x[k]&1){
						ok=false;break;
					}
				}
				if(!ok)continue;
				int tmp=0;
				for(int r2=0;r2<n;++r2){
					if(~myh&&r2^myh)continue;
					dp[i][r1]+=dp[t][r1]*dp[j][r2];
				}
			}
		}
	}
	printf("%lld\n",dp[(1<<n)-1][0]);
	return 0;
}