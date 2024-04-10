#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=100005;typedef long long ll;typedef __int128 LL;typedef std::pair<LL,ll> pr;const LL INF=((LL)1)<<100;const ll inf=1e18;
inline pr operator + (const pr &a,const pr &b){return (pr){a.first+b.first,a.second+b.second};}
inline void operator += (pr &a,const pr &b){a.first+=b.first,a.second+=b.second;}
inline pr operator - (const pr &a,const pr &b){return (pr){a.first-b.first,a.second-b.second};}
ll a[N],premin[N],s[N],t[N];int S[N],n,pos;pr b[N],pre[N],dp[N],PRE[N];int d[N];
inline int get(ll x){return std::upper_bound(t+1,t+pos+1,x)-t-1;}
inline ll up(ll a,int b){return a>=0?(a+b-1)/b:a/b;}
struct BIT{
	pr c[N];void clear(){std::fill(c,c+N,(pr){0,0});}
	void add(int x,const pr &C){for(;x<N;x+=lowbit(x))c[x]+=C;}
	pr ask(int x){pr ans={0,0};for(;x;x-=lowbit(x))ans+=c[x];return ans;}
}tr1;
struct BBIT{
	int c[N];void clear(){memset(c,63,sizeof(c));}
	void add(int x,int C){for(;x<N;x+=lowbit(x))chmin(c[x],C);}
	int ask(int x){int ans=1e9;for(;x;x-=lowbit(x))chmin(ans,c[x]);return ans;}
}tr3;
struct BBBIT{
	pr c[N];void clear(){std::fill(c,c+N,(pr){-INF,-inf});}
	void add(int x,const pr &C){++x;for(;x;x-=lowbit(x))chmax(c[x],C);}
	pr ask(int x){++x;pr ans={-INF,-inf};for(;x<N;x+=lowbit(x))chmax(ans,c[x]);return ans;}
}tr2;
pr calc(ll mid){
	tr1.clear(),tr2.clear(),tr3.clear(),tr1.add(get(0),{0,1}),tr3.add(get(0),0);
	for(int i=1;i<=n;++i){
		int tmp=get(s[i]-mid);pr w=tr1.ask(tmp);LL x=w.second,y=w.first;int z=tr3.ask(tmp);
		b[i]={x*(s[i]-mid)-y,x},d[i]=z,tr1.add(S[i],{s[i],1}),tr3.add(S[i],i),pre[i]=pre[i-1]+b[i];
	}
	dp[0]={0,0},tr2.add(0,{0,0});
	for(int i=1;i<=n;++i){
		int j=std::min(i,d[i]);dp[i]=tr2.ask(j)+pre[i];if(j)chmax(dp[i],PRE[j-1]+(pr){s[i]-mid,1}+pre[i]);
		tr2.add(i,dp[i]-pre[i]),PRE[i]=std::max(PRE[i-1],dp[i]-(pr){premin[i],0}-pre[i]);
	}
	return dp[n];
}
int main(){
	ll m;read(n,m);
	for(int i=1;i<=n;++i)read(a[i]),s[i]=s[i-1]+a[i],t[i]=s[i];
	pos=n,t[++pos]=0,std::sort(t+1,t+pos+1);pos=std::unique(t+1,t+pos+1)-t-1;
	for(int i=1;i<=n;++i)premin[i]=std::min(premin[i-1],s[i]);
	for(int i=1;i<=n;++i)S[i]=get(s[i]);
	ll l=-1e10,r=1e10,mid;
	while(l<r)mid=up(l+r,2),calc(mid).second>=m?l=mid:r=mid-1;
	pr tmp=calc(l);printf("%lld\n",(ll)(tmp.first+l*m));
	return 0;
}