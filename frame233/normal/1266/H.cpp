#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
typedef __int128 LL;
typedef __uint128_t ULL;
typedef unsigned long long ull;
const int N=60;const ull mod=9000000000000000041ULL;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
ull ksm(ull a,ull b=mod-2){ull res=1;while(b){if(b&1)res=(ULL)res*a%mod;a=(ULL)a*a%mod,b>>=1;}return res;}
char s[N];int e1[N],e2[N],coef[N][N],v[N];ull a[N][N],b[N][N],y[N];bool can[N],vis[N];
inline int get(int x){return s[x]=='B'?e1[x]:e2[x];}
int main(){
	int n;read(n);
	for(int i=1;i<n;++i)read(e1[i],e2[i]),a[i][i]+=2,add(a[e1[i]][i],mod-1),add(a[e2[i]][i],mod-1),b[i][i]=1,coef[i][i]+=2,--coef[e1[i]][i],--coef[e2[i]][i];
	for(int i=1;i<n;++i){
		if(!a[i][i])for(int j=i+1;j<n;++j)if(a[j][i]){std::swap(a[i],a[j]),std::swap(b[i],b[j]);break;}
		ull inv=ksm(a[i][i]);for(int j=n-1;j>=i;--j)a[i][j]=(ULL)a[i][j]*inv%mod;
		for(int j=n-1;j>=1;--j)b[i][j]=(ULL)b[i][j]*inv%mod;
		for(int j=1;j<n;++j)if(i!=j){
			ULL c=mod-a[j][i];
			for(int k=n-1;k>=1;--k)add(b[j][k],c*b[i][k]%mod);
			for(int k=n-1;k>=i;--k)add(a[j][k],c*a[i][k]%mod);
		}
	}
	int q;read(q);
	while(q--){
		int u;read(u);scanf("%s",s+1);
		for(int i=1;i<n;++i)v[i]=(i==1)-(s[i]=='R')-(i==u);
		for(int i=1;i<n;++i)v[e2[i]]+=s[i]=='R',y[i]=0;
		for(int i=1;i<n;++i)for(int j=1;j<n;++j)add(y[i],(ULL)b[i][j]*(v[j]+mod)%mod);
		bool flag=0;
		for(int i=1;i<n;++i){
			LL cur=0;for(int j=1;j<n;++j)cur+=(ULL)coef[i][j]*y[j];
			if(cur!=v[i]){flag=1;break;}
		}
		if(flag){puts("-1");continue;}
		memset(vis,0,sizeof(vis)),memset(can,0,sizeof(can)),can[u]=1,vis[u]=1;
		for(int i=1;i<=n;++i)if(y[i]||s[i]=='R'){
			std::vector<int> all;int u=i;
			while(!vis[u])vis[u]=1,all.pb(u),u=get(u);
			if(!can[u]){flag=1;break;}
			for(auto it:all)can[it]=1;
		}
		if(flag)puts("-1");
		else{
			ull ans=0;for(int i=1;i<n;++i)ans+=2*y[i]+(s[i]=='R');
			printf("%llu\n",ans);
		}
	}
	return 0;
}