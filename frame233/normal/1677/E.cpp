#include<bits/stdc++.h>
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005,NC=(1<<19)+5,M=1000005;typedef std::pair<int,int> pi;typedef long long ll;
std::vector<pi> vec[N];ll ans[M];
int p[N];std::vector<pi> Q[N];std::vector<int> d[N];
struct BIT{
	ll c[N];void add(int x,ll C){for(;x;x-=lowbit(x))c[x]+=C;}
	ll ask(int x){ll ans=0;for(;x<N;x+=lowbit(x))ans+=c[x];return ans;}
}tr1,tr2,tr3,tr4;
int st[N],top,q[N];bool in[N];int L[N],R[N];
inline void push(int x,int y,int C){vec[y].pb({x,C});}
inline void push(int x1,int x2,int y1,int y2){
	push(x2,y1,1),push(x2,y2+1,-1),push(x1-1,y1,-1),push(x1-1,y2+1,1);
}
int main(){
	int n,m;read(n,m);
	for(int i=1;i<=n;++i)for(int j=i;j<=n;j+=i)d[j].pb(i);
	for(int i=1;i<=n;++i)read(p[i]),q[p[i]]=i;
	for(int i=1;i<=n;++i){
		while(top&&p[i]>p[st[top]])--top;
		L[i]=st[top]+1,st[++top]=i;
	}
	st[0]=n+1,top=0;
	for(int i=n;i>=1;--i){
		while(top&&p[i]>p[st[top]])--top;
		R[i]=st[top]-1,st[++top]=i;
	}
	for(int i=1;i<=n;++i){
		int l=L[i],r=R[i];
		std::vector<pi> vec;
		for(auto it:d[p[i]]){
			int x=q[it],y=q[p[i]/it];if(x>y)std::swap(x,y);
			if(x<l||y>r||x==y)continue;
			vec.pb({std::min(x,i),std::max(y,i)});
		}
		std::sort(vec.begin(),vec.end(),std::greater<pi>());int mn=r+1;
		for(const auto &it:vec)if(it.second<mn)push(l,it.first,it.second,mn-1),mn=it.second;
	}
	for(int i=1,l,r;i<=m;++i)read(l,r),Q[r].pb({l,i});
	for(int i=1;i<=n;++i){
		for(const auto &it:vec[i]){
			tr1.add(it.first,it.second);
			tr2.add(it.first,it.second*it.first);
			tr3.add(it.first,it.second*i);
			tr4.add(it.first,it.second*1LL*i*it.first);
		}
		for(const auto &it:Q[i]){
			int l=it.first,r=i;
			ans[it.second]= tr1.ask(it.first)*(r+1)*(-l+1)+
							tr2.ask(it.first)*(r+1)-
							tr3.ask(it.first)*(-l+1)-
							tr4.ask(it.first);
		}
	}
	for(int i=1;i<=m;++i)printf("%lld\n",ans[i]);
	return 0;
}