#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return !b?a:gcd(b,a%b);}
const int N=200005;typedef long long ll;const ll INF=1e18;typedef std::pair<ll,ll> pr;
std::vector<int> e[N];int siz[N],Fa[N],dep[N],son[N],top[N];
void dfs1(int x,int fa){
	siz[x]=1,Fa[x]=fa,dep[x]=dep[fa]+1;
	for(auto v:e[x])if(v!=fa){
		dfs1(v,x),siz[x]+=siz[v];
		if(siz[v]>siz[son[x]])son[x]=v;
	}
}
void dfs2(int x,int topf){
	top[x]=topf;if(son[x])dfs2(son[x],topf);
	for(auto v:e[x])if(!top[v])dfs2(v,v);
}
int lca(int x,int y){while(top[x]!=top[y])dep[top[x]]>dep[top[y]]?x=Fa[top[x]]:y=Fa[top[y]];return dep[x]<dep[y]?x:y;}
inline int getdis(int x,int y){return dep[x]+dep[y]-dep[lca(x,y)]*2;}
inline bool cmp(int x,int y){return dep[x]>dep[y];}
int u,v,x,y,c1,c2,D1,D2,T11,T12,T21,T22,len;
void exgcd(int &x,int &y,int a,int b){
	if(!b)return x=1,y=0,void();
	exgcd(y,x,b,a%b),y-=a/b*x;
}
ll calc1(int D1,int D2,int T1,int T2){
	int g=gcd(D1,D2);if((T2-T1)%g)return INF;
	int x,y;exgcd(x,y,D1,D2);ll X=1LL*(T2-T1)/g*x,Y=1LL*(T2-T1)/g*y,dx=D2/g,dy=D1/g;
	if(X<0){ll tmp=(-X+dx-1)/dx;X+=tmp*dx,Y-=tmp*dy;}
	if(Y>0){ll tmp=(Y+dy-1)/dy;X+=tmp*dx,Y-=tmp*dy;}
	if(X<0||Y>0)return INF;
	ll tmp=std::min(X/dx,(-Y)/dy);X-=tmp*dx,Y+=tmp*dy;
	return X*D1+T1;
}
pr f(ll L,ll R,ll D1,ll D2){// 0<=L<=R
	if(D1==0)return L==0?(pr){0,0}:(pr){INF,INF};
	ll k1=(L+D1-1)/D1;if(k1*D1<=R)return {k1,0};
	if(D1>D2){
		ll t=(R+D1-1)/D1;pr tmp=f(-R+t*D1,-L+t*D1,D2,D1);
		if(tmp.second<INF)tmp.second+=t,std::swap(tmp.first,tmp.second);
		return tmp;
	}
	pr tmp=f(L%D1,R%D1,D1,D2%D1);
	if(tmp.second<INF)tmp.first+=tmp.second*(D2/D1)+L/D1;
	return tmp;
}
ll calc2(int D1,int D2,int T1,int T2){
	if((T1+T2+len)%2)return INF;
	if(T1>T2)std::swap(T1,T2),std::swap(D1,D2);
	ll L=T2-T1-len,R=T2-T1+len;pr tmp;
	if(L<=0)tmp={0,0};else tmp=f(L,R,D1,D2);
	if(tmp.first>=INF)return INF;
	return (tmp.first*D1+tmp.second*D2+T1+T2+len)/2;
}
int main(){
	int n;read(n);
	for(int i=1,x,y;i<n;++i)read(x,y),e[x].pb(y),e[y].pb(x);
	dfs1(1,0),dfs2(1,1);
	int q;read(q);
	while(q--){
		read(u,v,x,y);std::vector<int> nd={lca(u,x),lca(u,y),lca(v,x),lca(v,y)};
		std::sort(nd.begin(),nd.end(),cmp);c1=nd[0],c2=nd[1];
		if(c1==c2&&dep[c1]<std::max(dep[lca(x,y)],dep[lca(u,v)])){puts("-1");continue;}
		D1=2*getdis(u,v),D2=2*getdis(x,y),len=getdis(c1,c2);
		int a=getdis(u,c1),b=getdis(u,c2);T11=a<=b?a:D1/2+getdis(v,c1),T12=b<a?b:D1/2+getdis(v,c2);
		a=getdis(x,c1),b=getdis(x,c2);T21=a<=b?a:D2/2+getdis(y,c1),T22=b<a?b:D2/2+getdis(y,c2);
		ll ans=std::min({calc1(D1,D2,T11,T21),calc1(D1,D2,T12,T22),calc2(D1,D2,T11,T22),calc2(D1,D2,T12,T21)});
		printf("%lld\n",ans>=INF?-1:ans);
	}
	return 0;
}