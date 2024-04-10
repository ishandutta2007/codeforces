#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=31,mod=1000000007;typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
int K,p[N],st[61],top;
struct mat{
	int a[N][N];
	mat operator * (const mat &o)const{
		mat c;memset(c.a,0,sizeof(c.a));
		for(int i=0;i<=K;++i)for(int k=0;k<=K;++k)for(int j=0;j<=K;++j)add(c.a[i][j],1ULL*a[i][k]*o.a[k][j]%mod);
		return c;
	}
}I,f[61][N],M[N];
mat ksm(mat a,int b){mat res=I;while(b){if(b&1)res=res*a;a=a*a,b>>=1;}return res;}
int main(){
	ll n;read(n,K);for(int i=0;i<=K;++i)I.a[i][i]=1;
	while(n)st[top++]=n%K,n/=K;
	for(int t=0;t<K;++t)M[t]=I,M[t].a[t][t]=0,M[t].a[K][K]=2,M[t].a[K][t]=mod-1,M[t].a[t][K]=1;
	for(int i=0;i<K;++i)f[0][i]=M[i];
	for(int i=1;i<top;++i){
		f[i][0]=I;for(int t=0;t<K;++t)f[i][0]=f[i-1][t]*f[i][0];
		for(int j=1;j<K;++j){
			p[K]=K;for(int t=0;t<K;++t)p[t]=(t+j)%K;
			for(int a=0;a<=K;++a)for(int b=0;b<=K;++b)f[i][j].a[p[a]][p[b]]=f[i][0].a[a][b];
		}
	}
	int cur=0;mat res=I;
	for(int i=top-1;i>=0;--i){
		for(int j=0;j<st[i];++j)res=f[i][(cur+j)%K]*res;
		cur=(cur+st[i])%K;
	}
	printf("%d\n",res.a[K][K]);
	return 0;
}