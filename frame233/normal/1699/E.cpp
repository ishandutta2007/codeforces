#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=5000005;
int c[N],ori[N],dp[N];bool is[N];
void MAIN(){
	int n,m;read(n,m);memset(is,0,m+3),memset(ori,0,(m+3)<<2),memset(c,0,(m+3)<<2),memset(dp,0,(m+3)<<2);
	for(int i=1,x;i<=n;++i)read(x),is[x]=1;
	int ans=1e9,tot=0;for(int i=1;i<=m;++i)if(is[i])++tot;
	dp[1]=1e9;if(is[1])c[1]=tot+1;
	for(int i=1,p=1,s=is[1];i<=m;++i){
		for(int j=i,t=1;j<=m;j+=i,++t){
			if(j==1)continue;
			dp[j]=std::max(dp[j],std::min(dp[t],i));
			if(dp[j]&&is[j]){
				if(!ori[j])++s;
				--c[ori[j]],++c[ori[j]=dp[j]];
			}
		}
		while(s-c[p]==tot)s-=c[p++];
		if(s==tot)ans=std::min(ans,i-p);
	}
	printf("%d\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}