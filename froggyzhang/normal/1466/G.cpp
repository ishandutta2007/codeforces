#include<bits/stdc++.h>
using namespace std;
#define N 200020
#define M 1000010
const int mod=1e9+7;
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
int n,len,Q,pw2[N];
int a[N][26];
char s[233],t[N],g[M],h[M<<3];
int KMP(char *s,int n,char *t,int m){
	static int nxt[M];
	int ans=0;
	nxt[1]=0;
	for(int i=2,j=0;i<=n;++i){
		while(j&&s[j+1]!=s[i])j=nxt[j];
		if(s[j+1]==s[i])++j;
		nxt[i]=j;
	}
	for(int i=1,j=0;i<=m;++i){
		while(j&&s[j+1]!=t[i])j=nxt[j];
		if(s[j+1]==t[i])++j;
		if(j==n)++ans,j=nxt[j];
	}
	return ans;
}
int main(){
	n=read(),Q=read();
	scanf("%s",s+1);
	len=strlen(s+1);
	scanf("%s",t+1);
	pw2[0]=1;
	for(int i=1;i<=n;++i){
		pw2[i]=(pw2[i-1]<<1)%mod;
		for(int j=0;j<26;++j){
			a[i][j]=(a[i-1][j]<<1)%mod;
		}
		++a[i][t[i]-'a'];
	}
	while(Q--){
		int k=read();
		scanf("%s",g+1);
		int z=strlen(g+1);
		if(k<=20&&len*(1<<k)+(1<<k)-1<z){
			printf("0\n");
			continue;
		}
		int now=len,u=0,ans=0;
		for(int i=1;i<=len;++i)h[i]=s[i];
		do{
			ans=(ans+1LL*KMP(g,z,h,now)*pw2[k-u])%mod;
			h[now+1]=t[++u];
			for(int i=1;i<=now;++i)h[i+now+1]=h[i];
			now=(2*now+1);
		}while((now>>1)<z&&u<=k);
		--u;
		for(int c=0;c<26;++c){
			h[z]=c+'a';
			int now=0;
			for(int i=z-1,j=len;i>=1;--i){
				if(!j)j=len,h[i]=t[__builtin_ffs(++now)];
				else h[i]=s[j--];
			}
			now=0;
			for(int i=z+1,j=1;i<=2*z-1;++i){
				if(j==len+1)j=1,h[i]=t[__builtin_ffs(++now)];
				else h[i]=s[j++];
			}
			int x=KMP(g,z,h,2*z-1);
			ans=(ans+1LL*(a[k][c]-1LL*a[u][c]*pw2[k-u]%mod)*x)%mod;
		}
		printf("%d\n",(ans+mod)%mod);
	}
	return 0;
}
/*qwq*/