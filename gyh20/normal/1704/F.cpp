#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,a[1000002],ans,A,B,f[1000002];
char s[1000002],vis[500002],vis1[500002];
int main(){
	f[1]=0,f[2]=1;
	for(re int i=3;i<=500000;++i){
	//	for(re int j=1;j<i;++j)vis[f[j-1]^f[i-j-1]]=1;
		for(re int j=1;j<min(i,200);++j)vis1[f[j-1]^f[i-j-1]]=1;
		re int pos=0,p1=0;
		while(vis1[p1])++p1;
		f[i]=p1;//assert(pos==p1);
		assert(p1<=200);
		for(re int j=0;j<=200;++j)vis1[j]=0;
	}
	t=read();
	while(t--){
		n=read();
		scanf("%s",s+1);
		int cnt1=0,cnt2=0;
		for(re int i=1;i<=n;++i)if(s[i]=='R')++cnt1;else ++cnt2;
		if(cnt1>cnt2){
			puts("Alice");
			continue;
		}
		if(cnt2>cnt1){
			puts("Bob");
			continue;
		}
		re int ss=0;
		for(re int l=1,r;l<=n;l=r+1){
			r=l;
			while(r<n&&s[r+1]!=s[r])++r;
			ss^=f[r-l+1];
		}
		puts(ss?"Alice":"Bob");
	}
}