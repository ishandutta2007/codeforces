#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int base=233;
const int mod=1e9+9;
typedef long long ll;
typedef unsigned long long ull;
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
int n,Q,t[N];
int pw[N],h[N][2];
char s[N];
inline ull Hash(int l,int r,int x){
	return (h[r][x]-1LL*h[l-1][x]*pw[t[r]-t[l-1]]%mod+mod)%mod;	
}
int main(){
	n=read();
	pw[0]=1;
	for(int i=1;i<=n;++i){
		pw[i]=1LL*pw[i-1]*base%mod;
	}
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		if(s[i]=='1')h[i][0]=h[i-1][0],h[i][1]=h[i-1][1],t[i]=t[i-1];
		else h[i][0]=(1LL*h[i-1][0]*base+(i&1)+1)%mod,h[i][1]=(1LL*h[i-1][1]*base+((i&1)^1)+1)%mod,t[i]=t[i-1]+1;
	}
	Q=read();
	while(Q--){
		int l1=read(),l2=read(),len=read();
		printf(Hash(l1,l1+len-1,l1&1)==Hash(l2,l2+len-1,l2&1)?"Yes\n":"No\n");
	}
	return 0;
}