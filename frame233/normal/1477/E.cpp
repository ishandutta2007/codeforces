#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005,NN=1000005;typedef long long ll;
int n,m,q,a[N],b[N],M;ll s=0;
struct BIT{
	ll c[NN];void add(int x,int C){++x;for(;x;x-=lowbit(x))c[x]+=C;}
	ll ask(int x){++x;ll ans=0;for(;x<NN;x+=lowbit(x))ans+=c[x];return ans;}
}tr1,tr2;
std::multiset<int> A,B;
inline ll calc1(int k,int t){return k+s-t-1LL*(n-1)*M+1LL*(n-1)*std::max(0,M+k-t)-(tr2.ask(std::max(0,t-k))+1LL*(k-t)*tr1.ask(std::max(0,t-k)));}
inline ll calc2(int k,int t){return s-1LL*n*M+1LL*n*std::max(0,-t+k+M)-(tr2.ask(std::max(0,t-k))+1LL*(k-t)*tr1.ask(std::max(0,t-k)));}
int main(){
	read(n,m,q);
	for(int i=1;i<=n;++i)read(a[i]),A.insert(a[i]),s+=a[i];
	for(int i=1;i<=m;++i)read(b[i]),B.insert(b[i]),tr1.add(b[i],1),tr2.add(b[i],b[i]);
	int opt,x,y;
	while(q--){
		read(opt,x);
		if(opt==1)read(y),A.erase(A.find(a[x])),s-=a[x],A.insert(a[x]=y),s+=a[x];
		else if(opt==2)read(y),B.erase(B.find(b[x])),tr1.add(b[x],-1),tr2.add(b[x],-b[x]),B.insert(b[x]=y),tr1.add(b[x],1),tr2.add(b[x],b[x]);
		else{
			M=std::min(*A.begin(),*B.begin());ll ans=calc1(x,*A.begin());
			auto it=A.lower_bound(x+*B.rbegin());
			if(it!=A.end())ans=std::max(ans,calc1(x,*it));
			if(it!=A.begin())ans=std::max(ans,calc1(x,*--it));
			ans=std::max({ans,calc2(x,*B.begin()),calc2(x,*B.rbegin())});
			printf("%lld\n",ans);
		}
	}
	return 0;
}