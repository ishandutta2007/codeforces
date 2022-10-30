#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=22,mod=31607;
typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
int a[N][N],cnt[1<<21],b[N][N],mark[N][N];
int o[N][N],val[N],qwq,n;
void dfs(int dep,int coef){
	if(!coef)return;
	if(dep==n){
		for(int i=0;i<n;++i)coef=coef*(mod+1-val[i])%mod;
		return add(qwq,coef);
	}
	dfs(dep+1,coef);
	for(int j=0;j<n;++j)if(!mark[dep][j]++)coef=coef*a[dep][j]%mod,val[j]=val[j]*b[dep][j]%mod;
	dfs(dep+1,(mod-coef)%mod);
	for(int j=0;j<n;++j)if(!--mark[dep][j])val[j]=val[j]*a[dep][j]%mod;
}
int main(){
	for(int i=1;i<1<<21;++i)cnt[i]=cnt[i>>1]+(i&1);
	read(n);ll inv=ksm(10000);
	for(int i=0;i<n;++i)for(int j=0;j<n;++j)read(a[i][j]),a[i][j]=inv*a[i][j]%mod,b[i][j]=ksm(a[i][j]);
	int ans=0;
	for(int p=0;p<2;++p)for(int q=0;q<2;++q){
		memset(mark,0,sizeof(mark));
		int mul=1;
		if(p)for(int i=0;i<n;++i)if(!mark[i][i]++)mul=mul*a[i][i]%mod;
		if(q)for(int i=0;i<n;++i)if(!mark[i][n-1-i]++)mul=mul*a[i][n-1-i]%mod;
		for(int j=0;j<n;++j){
			val[j]=1;for(int i=0;i<n;++i)if(!mark[i][j])val[j]=val[j]*a[i][j]%mod;
		}
		qwq=0,dfs(0,mul);
		(p+q)&1?sub(ans,qwq):add(ans,qwq);
	}
	printf("%d\n",(mod+1-ans)%mod);
	return 0;
}