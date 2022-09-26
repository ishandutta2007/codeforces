#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 200020
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
int n,Q,a[N],vis[20];
ll fac[20],tot,s[N];
void Get(){
	int len=min(n,15);
	ll now=tot;
	for(int i=1;i<=len;++i)vis[i]=0;
	for(int i=n-len+1;i<=n;++i){
		int k=now/fac[n-i]+1;
		now%=fac[n-i];
		int p=1;
		while(true){
			k-=!vis[p];
			if(!k)break;
			++p;
		}
		vis[p]=1;
		a[i]=n-len+p;
	}
	for(int i=n-len+1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
}
int main(){
	n=read(),Q=read();
	fac[0]=1;
	for(int i=1;i<=15;++i)fac[i]=fac[i-1]*i;
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+i;
	}
	while(Q--){
		int opt=read();
		if(opt==2){
			tot+=read();
			Get();
		}
		else{
			int l=read(),r=read();
			printf("%lld\n",s[r]-s[l-1]);
		}
	}		
	return 0;
}