#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=105;int mod;typedef long long ll;typedef unsigned long long ull;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
int C[N][N],f[N][N][N];
struct FastMod{
	typedef __uint128_t LLL;
	ull b,m;
	void init(ull b){this->b=b,m=ull((LLL(1)<<64)/b);}
	inline ull operator()(ull a){
		ull r=a-(ull)((LLL(m)*a)>>64)*b;
		return r>=b?r-b:r;
	}
}M;
int main(){
	int n,m,k;read(n,m,k,mod),M.init(mod);
	for(int i=0;i<N;++i)for(int j=C[i][0]=1;j<=i;++j)C[i][j]=C[i-1][j-1],add(C[i][j],C[i-1][j]);
	for(int i=0;i<=m;++i)f[i][0][0]=1;
	for(int i=1,cur=1;i<=n;++i)f[0][i][0]=cur=1LL*cur*i%mod;
	for(int j=1;j<=m;++j){
		for(int i=1;i<=n;++i){
			for(int k=0;k<=(i+1)/2;++k){
				for(int p=0;p<i;++p){
					int tmp=0;for(int c=0;c+(j==1)<=k;++c)tmp=M(tmp+1ULL*f[j-1][p][c]*f[j-1][i-p-1][k-c-(j==1)]);
					add(f[j][i][k],M(1LL*tmp*C[i-1][p]));
				}
			}
		}
	}
	printf("%d\n",f[m][n][k]);
	return 0;
}