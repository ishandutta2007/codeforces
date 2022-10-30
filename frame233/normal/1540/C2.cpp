#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=105,mod=1000000007;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
int c[N],b[N],bp[N],ap[N],dp[N][N*N],pre[N*N],ans[N+N];
int main(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(c[i]),ap[i]=ap[i-1]+c[i];
	for(int i=2;i<=n;++i)read(b[i]),bp[i]=bp[i-1]+b[i];
	for(int i=2;i<=n;++i)bp[i]+=bp[i-1];
	int mn=1e5,mx=1e5;
	for(int i=1;i<=n;++i)mn=std::min(mn,-bp[i]/i),mx=std::min(mx,(ap[i]-bp[i])/i);
	--mn,++mx;
	for(int k=mn;k<=mx;++k){
		dp[0][0]=1;int s=0;
		for(int i=1;i<=n;++i){
			int lim=std::max(0,bp[i]+i*k);s+=c[i];
			pre[0]=dp[i-1][0];for(int j=1;j<=s;++j)pre[j]=pre[j-1],add(pre[j],dp[i-1][j]);
			memset(dp[i],0,lim<<2);for(int j=lim;j<=s;++j)dp[i][j]=pre[j],sub(dp[i][j],j>=c[i]+1?pre[j-c[i]-1]:0);
		}
		for(int i=0;i<=s;++i)add(ans[k-mn],dp[n][i]);
	}
	int q;read(q);
	while(q--){
		int x;read(x),x=std::min(mx,std::max(x,mn));
		printf("%d\n",ans[x-mn]);
	}
	return 0;
}