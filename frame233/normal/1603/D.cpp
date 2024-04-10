#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;typedef long long ll;
bool pr[N];int p[N],pos,phi[N];ll s[N];
void sieve(){
	for(int i=2;i<N;++i){
		if(!pr[i])p[++pos]=i,phi[i]=i-1;
		for(int j=1;j<=pos&&i*p[j]<N;++j){
			pr[i*p[j]]=1;
			if(i%p[j]==0){phi[i*p[j]]=phi[i]*p[j];break;}
			phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
	for(int i=1;i<N;++i)s[i]=s[i-1]+phi[i];
}
struct qry{int n,id;};
std::vector<qry> Q[18];ll ans[300005],f[N],g[N];
ll calc(int l,int n){ll ans=0;for(int r;l<=n;l=r+1)r=n/(n/l),ans+=1LL*(r-l+1)*s[n/l];return ans;}
void solve(int l,int r,int L,int R){
	if(l>r)return;
	int mid=(l+r)>>1,_r=std::min(mid-1,R),p=_r;ll cur=calc(_r+1,mid);g[mid]=cur+f[_r];
	for(int i=_r-1;i>=L;--i){
		cur+=s[mid/(i+1)];
		if(cur+f[i]<g[mid])g[mid]=cur+f[i],p=i;
	}
	solve(l,mid-1,L,p),solve(mid+1,r,p,R);
}
int main(){
	sieve();
	int q;read(q);
	for(int i=1,n,k;i<=q;++i){
		read(n,k),ans[i]=n;
		if(k<18)Q[k].pb({n,i});
	}
	memset(f,63,sizeof(f)),f[0]=0;
	for(int k=1;k<=17;++k){
		memset(g,63,(k+3)<<3),solve(k,1e5,0,1e5),memcpy(f,g,sizeof(f));
		for(auto [n,id]:Q[k])ans[id]+=f[n];
	}
	for(int i=1;i<=q;++i)printf("%lld\n",ans[i]);
	return 0;
}