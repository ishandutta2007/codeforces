#include<bits/stdc++.h>
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
int n,m,Q,a[N],c[N],s[N];
int f[N][20];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		++c[a[i]];
	}
	for(int i=1;i<=m;++i){
		s[i]=s[i-1]+c[i];
	}
	for(int i=1;i<=m;++i){
		f[i][0]=0;
	}
	for(int j=1;j<=18;++j){
		for(int i=1;i+(1<<j)-1<=m;++i){
			f[i][j]=f[i][j-1]^f[i+(1<<j-1)][j-1];
			if((s[i+(1<<j)-1]-s[i+(1<<j-1)-1])&1)f[i][j]^=1<<j-1;
		}
	}
	Q=read();
	while(Q--){
		int l=read(),r=read(),ans=0;
		for(int i=18;i>=0;--i){
			if(l+(1<<i)-1<=r){
				ans^=f[l][i]^(((s[r]-s[l+(1<<i)-1])&1)<<i);
				l+=(1<<i);	
			}
		}
		putchar(ans?'A':'B');
	}
	return 0;
}