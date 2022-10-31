#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return !b?a:gcd(b,a%b);}
const int N=1000005,mod=1000000007;typedef long long ll;typedef std::pair<int,int> pi;
bool pr[N];int p[N],pos,md[N],mxd[N];
void sieve(){
	md[1]=1;
	for(int i=2;i<N;++i){
		if(!pr[i])p[++pos]=i,md[i]=i;
		for(int j=1;j<=pos&&i*p[j]<N;++j){
			pr[i*p[j]]=1,md[i*p[j]]=p[j];
			if(i%p[j]==0)break;
		}
	}
}
int a[N],b[N],tar,n;ll fac[N];int C[N];bool used[N];std::vector<int> all[N];
int c[N],d[N];
inline int get(int x){return x==1?1:n/x;}
int main(){
	sieve();fac[0]=1;for(int i=1;i<N;++i)fac[i]=fac[i-1]*i%mod;
	read(n);for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i){
		std::vector<std::pair<int,int>> v;int x=i;
		while(x>1){
			if(v.empty()||v.back().first!=md[x])v.pb({md[x],1});else ++v.back().second;
			x/=md[x];
		}
		int val=1;for(const auto &it:v)val*=it.first;
		if(i==1)mxd[i]=1;else mxd[i]=v.back().first;
		b[i]=val,all[val].pb(i);
	}
	for(int i=1;i<=n;++i)if(a[i]!=0){
		int x=b[i],y=b[a[i]],t1=mxd[x],t2=mxd[y];
		if(get(t1)!=get(t2))return puts("0"),0;
		if(c[t1]&&c[t1]!=t2)return puts("0"),0;
		if(d[t2]&&d[t2]!=t1)return puts("0"),0;
		c[t1]=t2,d[t2]=t1;
	}
	int ans=1;for(int i=1;i<=pos;++i)if(!c[p[i]])++C[get(p[i])];
	if(!c[1])++C[1];
	for(int i=1;i<=n;++i)ans=1LL*ans*fac[C[i]]%mod;
	for(int i=1;i<=n;++i)if(!all[i].empty()){
		int cnt=0;for(auto it:all[i])cnt+=a[it]==0;
		ans=1LL*ans*fac[cnt]%mod;
	}
	printf("%d\n",ans);
	return 0;
}