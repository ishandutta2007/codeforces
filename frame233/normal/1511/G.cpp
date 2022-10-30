#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=400005;
int f[N][21],sum[N];
int main(){
	int n,m;read(n,m);
	for(int i=1,x;i<=n;++i)read(x),sum[x]^=1;
	for(int i=1;i<N;++i)sum[i]^=sum[i-1];
	for(int i=m;i>=1;--i){
		for(int j=1;j<=20&&i+(1<<(j-1))<=m;++j){
			f[i][j]=f[i][j-1]^f[i+(1<<(j-1))][j-1]^(sum[i+(1<<j)-1]^sum[i+(1<<(j-1))-1]?(1<<(j-1)):0);
		}
	}
	int q;read(q);
	while(q--){
		int l,r;read(l,r);
		int ans=0;
		for(int i=20;i>=0;--i)if(l+(1<<i)<=r){
			ans^=f[l][i],l+=1<<i;
			if(sum[r]^sum[l-1])ans^=1<<i;
		}
		putchar("AB"[!ans]);
	}
	return 0;
}