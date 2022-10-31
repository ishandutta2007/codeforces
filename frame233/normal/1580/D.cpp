#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
const int N=4005;typedef long long ll;
ll dp[N][N],tp[N];int a[N],st[N],top,ls[N],rs[N],m;
int dfs(int x,int w){
	int siz=1;dp[x][0]=0,dp[x][1]=0;std::vector<int> son;if(ls[x])son.pb(ls[x]);if(rs[x])son.pb(rs[x]);
	for(auto y:son){
		int tmp=dfs(y,a[y]-a[x]);memset(tp,-63,(siz+tmp+3)<<3);
		for(int i=0;i<=siz;++i)for(int j=0;j<=tmp;++j)chmax(tp[i+j],dp[x][i]+dp[y][j]);
		memcpy(dp[x],tp,(siz+tmp+3)<<3),siz+=tmp;
	}
	for(int i=0;i<=siz;++i)dp[x][i]+=1LL*w*i*(m-i);
	return siz;
}
int main(){
	int n;read(n,m);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i){
		while(top&&a[i]<a[st[top]])ls[i]=st[top--];
		if(top)rs[st[top]]=i;
		st[++top]=i;
	}
	memset(dp,-63,sizeof(dp)),dfs(st[1],0);
	printf("%lld\n",dp[st[1]][m]);
	return 0;
}