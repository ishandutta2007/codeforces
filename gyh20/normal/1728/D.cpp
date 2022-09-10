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
int t,n,m,f[2002][2002],ans,A,B;
char s[1000002];
inline int solve(re int l,re int r){
	if(~f[l][r])return f[l][r];
	if(l>r)return 1;
	re int o1=solve(l+1,r-1),o2=solve(l,r-2),o3=solve(l+2,r);
	re int no1=o1,no3=o3,no2=o2,ss=0;
	if(no1==1){
		if(s[l]<s[r])no1=2;
		else if(s[l]>s[r])no1=0;
	}
	if(no3==1){
		if(s[l]<s[l+1])no3=2;
		else if(s[l+1]>s[l])no3=0;
	}
	ss=max(ss,min(no1,no3));
	no1=o1;
	if(no1==1){
		if(s[l]<s[r])no1=0;
		else if(s[l]>s[r])no1=2;
	}
	if(no2==1){
		if(s[r]<s[r-1])no2=2;
		else if(s[r]>s[r-1])no2=0;
	}
	ss=max(ss,min(no2,no1));
	return f[l][r]=ss;
}
int main(){
	t=read();
	while(t--){
		scanf("%s",s+1),n=strlen(s+1);
		for(re int i=0;i<=n+1;++i)for(re int j=0;j<=n+1;++j)f[i][j]=-1;
		re int x=solve(1,n);
		if(x==0)puts("Bob");
		else if(x==1)puts("Draw");
		else if(x==2)puts("Alice");
	}
}