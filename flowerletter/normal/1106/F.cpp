#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 110;
const int Mod = 998244353;
const int G = 3;
int n,m,k,b[MAXN];
map<int,int> Map;
struct Matrix{
	int a[MAXN][MAXN];
	inline void Init(int opt){
		for(int i=1;i<=k;i++) 
		    for(int j=1;j<=k;j++) a[i][j]=((i==j && opt==1)?1:0);
	}
	inline int* operator [] (const int &x){
		return a[x];
	}
}A,B;
inline Matrix operator * (Matrix x,Matrix y){
	Matrix ans;ans.Init(0);
	for(int i=1;i<=k;i++)
	    for(int j=1;j<=k;j++)
	    	for(int l=1;l<=k;l++) ans[i][j]=(ans[i][j]+x[i][l]*y[l][j]%(Mod-1))%(Mod-1);
	return ans;
}
inline Matrix Pow(Matrix A,int b){
	Matrix ans;ans.Init(1);
	for(;b;b>>=1,A=A*A)	if(b&1) ans=ans*A;
	return ans;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
} 
inline int Pow(int a,int b,int p,int ans=1){
    for(;b;b>>=1,a=a*a%p) if(b&1) ans=ans*a%Mod;
	return ans; 
} 
inline void Exgcd(int a,int b,int &x,int &y){
	if(b==0) x=1,y=0;
	else Exgcd(b,a%b,y,x),y-=a/b*x;
}
inline int BSGS(int A,int B){
	Map.clear();Map[1]=0;
	int m=ceil(sqrt(Mod)),x=1,y=1;
	for(int i=1;i<m;i++) x=x*A%Mod,Map[x*B%Mod]=i;
	x=x*A%Mod;
	for(int i=1;i<=m;i++) {
		y=y*x%Mod;
		if(Map.count(y)) return i*m-Map[y];
	}
}
signed main(){
	k=read();
	for(int i=1;i<=k;i++) b[i]=read();
	n=read(),m=read();
	A[1][k]=1;
	for(int i=1;i<=k;i++) B[i][k]=b[k-i+1];
	for(int i=1;i<k;i++) B[i+1][i]=1;
	A=A*Pow(B,n-k); 
	int p=A[1][k],t=BSGS(G,m);
	if(t%__gcd(p,Mod-1)) return puts("-1")&0;
	else {
		int gcd=__gcd(p,Mod-1);
		int x,y,a=p,b=Mod-1;
		t/=gcd,a/=gcd,b/=gcd;
		Exgcd(a,b,x,y);
		x=(x%(Mod-1)+Mod-1)%(Mod-1);
		x=x*t%(Mod-1);
		printf("%lld\n",Pow(G,x,Mod)%Mod);
	}
	return 0;
}