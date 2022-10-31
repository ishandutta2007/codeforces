#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005,mod=1000000007,inf=2e9;typedef std::pair<int,int> pi;typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
int a[N];std::vector<pi> Q[N];int s[N],pw[N];
int sum[N],val[N],len[N],pre[N],fa[N],ans[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main(){
	pw[0]=1;for(int i=1;i<N;++i)pw[i]=2LL*pw[i-1]%mod;
	int n,q;read(n,q);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=n;i>=1;--i)s[i]=(2LL*s[i+1]+a[i]+mod)%mod;
	for(int i=1,l,r;i<=q;++i)read(l,r),Q[r].pb({l,i});
	for(int i=1;i<=n;++i){
		fa[i]=i,sum[i]=a[i],len[i]=1,val[i]=2LL*(a[i]+mod)%mod;
		while(find(i)>1&&sum[find(i)]>0){
			int y=find(i),x=find(y-1);
			if(len[x]>=31||sum[x]+(((ll)sum[y])<<len[x])>=inf)sum[x]=inf;
			else sum[x]=sum[x]+(sum[y]<<len[x]);
			fa[y]=x,val[x]=(val[x]+1LL*pw[len[x]]*val[y])%mod,len[x]+=len[y];
		}
		int x=find(i);pre[x]=pre[find(x-1)],add(pre[x],val[x]);
		for(const auto &it:Q[i]){
			int l=it.first,id=it.second,R=find(l)+len[find(l)];
			int res=pre[find(i)];sub(res,pre[find(l)]);
			add(res,(s[l]+1LL*(mod-s[R])*pw[R-l])%mod),ans[id]=res;
		}
	}
	for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
	return 0;
}