#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=605,mod=1000000007;typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a<b?a+mod-b:a-b;}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
int a[N],b[N],p1,p2,f[N][N][2],g[N][N],pw[N],ia[N],ib[N],h[N][N],pre[N],suf[N];
inline bool cmp(int x,int y){return x>y;}
int main(){
	pw[0]=1;for(int i=1;i<N;++i)pw[i]=2LL*pw[i-1]%mod;
	int n,K;read(n,K);
	for(int i=1,x;i<=n;++i)read(x),(x<0?a[++p1]:b[++p2])=abs(x);
	std::sort(a+1,a+p1+1,cmp),std::sort(b+1,b+p2+1,cmp);
	ia[0]=1;for(int i=1;i<=p1;++i)ia[i]=ksm(a[i]);
	ib[0]=1;for(int i=1;i<=p2;++i)ib[i]=ksm(b[i]);
	for(int i=1;i<=p2;++i)pre[i]=pre[i-1],add(pre[i],1LL*pw[p2-i]*b[i]%mod);
	for(int i=p2;i>=1;--i)suf[i]=suf[i+1],add(suf[i],pw[p2-i]);
	f[0][0][0]=1;
	for(int i=1;i<=p1;++i){
		for(int j=0;j<i;++j){
			for(int k=0;k<=j;++k)for(int t=0;t<2;++t)add(f[i][k+1][t^1],1LL*f[j][k][t]*a[i]%mod);
		}
	}
	g[0][0]=1;
	for(int i=1;i<=p2;++i){
		for(int j=0;j<i;++j)for(int k=0;k<=j;++k)add(g[i][k+1],1LL*g[j][k]*b[i]%mod);
	}
	int ans=0;a[0]=1e9+1,b[0]=1e9+1;
	for(int i=0;i<=p1;++i){
		for(int j=0;j<=p2;++j){
			int sum=0,cnt=0;
			for(int p=0;p<=K;++p)add(sum,1LL*f[i][p][0]*g[j][K-p]%mod);
			for(int k=i+1;k<=p1;++k)cnt+=a[k]<=b[j];
			for(int k=j+1;k<=p2;++k)cnt+=b[k]<a[i];
			add(ans,1LL*sum*pw[cnt]%mod);
			if(!i)continue;			
			sum=0;for(int p=0;p<=K;++p)add(sum,1LL*f[i][p][1]*g[j][K-p]%mod);
			if(j){
				int pos1=j+1,pos2=1;while(pos1<=p2&&b[pos1]>=a[i])++pos1;
				for(int x=i+1;x<=p1;++x)if(a[x]<=b[j]){
					while(pos2<=p2&&1LL*b[pos2]*b[j]>1LL*a[x]*a[i])++pos2;
					if(pos1<=pos2-1)add(ans,1LL*sum*(pre[pos2-1]-pre[pos1-1]+mod)%mod*ia[i]%mod*pw[p1-x]%mod);
					int lim=std::max(pos1,pos2);
					add(ans,1LL*sum*a[x]%mod*ib[j]%mod*suf[lim]%mod*pw[p1-x]%mod);
				}
				for(int x=i+1;x<=p1;++x)if(a[x]<=b[j]){
					int tmp=1LL*sum*a[x]%mod*ib[j]%mod;
					add(ans,1LL*tmp*pw[p1-x]%mod);
				}
				for(int y=j+1;y<=p2;++y)if(b[y]<a[i]){
					int tmp=1LL*sum*b[y]%mod*ia[i]%mod;
					add(ans,1LL*tmp*pw[p2-y]%mod);
				}
				sub(ans,sum);
			}
			else{
				int coef=0;for(int x=i+1;x<=p1;++x)if(a[x]<=b[j])add(coef,pw[p1-x]);
				for(int y=j+1;y<=p2;++y)if(b[y]<a[i]){
					int tmp=1LL*sum*b[y]%mod*ia[i]%mod;
					add(ans,1LL*tmp*coef%mod*pw[p2-y]%mod);
				}
				for(int y=j+1;y<=p2;++y)if(b[y]<a[i]){
					int tmp=1LL*sum*b[y]%mod*ia[i]%mod;
					add(ans,1LL*tmp*pw[p2-y]%mod);
				}
			}
			
		}
	}
	if(K%2){
		h[p1+1][0]=1;
		for(int i=p1;i>=1;--i){
			for(int j=i+1;j<=p1+1;++j){
				for(int k=0;k<=p1+1-j;++k)add(h[i][k+1],1LL*a[i]*h[j][k]%mod);
			}
		}
		for(int i=1;i<=p1;++i)sub(ans,1LL*h[i][K]*pw[i-1]%mod);
	}
	printf("%d\n",ans);
	return 0;
}