#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define N 2000100
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
int f[N],n,lim,mx,pw2[N];
void FWT_and(int *f,int x,int n){
	for(int p=2;p<=n;p<<=1){
		int len=p>>1;
		for(int k=0;k<n;k+=p){
			for(int i=k;i<k+len;++i){
				f[i]=(f[i]+(x?f[i+len]:mod-f[i+len]))%mod;
			}
		}
	}
}
int main(){
	n=read();
	pw2[0]=1;
	for(int i=1;i<=n;++i){
		int x=read();
		++f[x],mx=max(mx,x);
		(pw2[i]=pw2[i-1]<<1)%=mod;
	}
	lim=1;
	while(lim<=mx)lim<<=1;
	FWT_and(f,1,lim);
	for(int i=0;i<lim;++i){
		f[i]=pw2[f[i]];
	}
	FWT_and(f,0,lim);
	printf("%d\n",f[0]==pw2[n]?f[0]-1:f[0]);
	return 0;
}