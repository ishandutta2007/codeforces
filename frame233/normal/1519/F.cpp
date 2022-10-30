#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int pw[]={1,5,25,125,625,3125,15625},inf=0x3f3f3f3f;
int a[7],b[7],c[7],rest[7];
int dp[15627],f[5][15627];
int main(){
	int n,m;read(n,m);
	for(int i=0;i<n;++i)read(a[i]);
	for(int i=0;i<m;++i)read(b[i]);
	int all=pw[m],cur=0;
	memset(dp,63,sizeof(dp));
	for(int i=0;i<m;++i)cur+=b[i]*pw[i];
	dp[cur]=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j)read(c[j]);
		memset(f,63,sizeof(f));
		for(int st=0;st<all;++st)f[a[i]][st]=dp[st];
		for(int j=m-1;j>=0;--j)for(int o=0;o<=a[i];++o){
			for(int st=0;st<all;++st)if(f[o][st]<inf){
				int cur=st/pw[j]%5;
				for(int k=1;k<=cur&&k<=o;++k)chmin(f[o-k][st-k*pw[j]],f[o][st]+c[j]);
			}
		}
		memcpy(dp,f[0],sizeof(dp));
	}
	int ans=*std::min_element(dp,dp+all);
	printf("%d\n",ans>=inf?-1:ans);
	return 0;
}