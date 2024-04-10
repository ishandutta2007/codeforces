#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
const int N=3005;
std::vector<int> v[N];
int a[N],dp[N][N];
void MAIN(){
	int n;read(n);
	for(int i=1;i<=n;++i)v[i].clear();
	for(int i=1;i<=n;++i)read(a[i]),v[a[i]].pb(i);
	for(int i=0;i<=n+1;++i)memset(dp[i],0,(n+3)<<2);
	for(int len=2;len<=n;++len){
		for(int l=1,r=len;r<=n;++l,++r){
			dp[l][r]=std::max(dp[l+1][r],dp[l][r-1])+(a[l]==a[r]);
			for(auto x:v[a[l]])if(l<=x&&x<=r)chmax(dp[l][r],dp[l][x]+dp[x][r]);
			for(auto x:v[a[r]])if(l<=x&&x<=r)chmax(dp[l][r],dp[l][x]+dp[x][r]);
		}
	}
	printf("%d\n",n-1-dp[1][n]);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}