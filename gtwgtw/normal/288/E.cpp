#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#define For(i,a,n)  for(int i=(a);i<=(n);i++)
#define Forn(i,a,n) for(int i=(a);i>=(n);i--)
using namespace std;
const int maxn=100005;
const int mod=1000000007;

void setIO(string a){
	 string in=a+".in",out=a+".out";
	 freopen(in.c_str(),"r",stdin);
	 freopen(out.c_str(),"w",stdout);
}

int f[maxn],n,A,B,na[maxn],nb[maxn],p2[maxn];
int g[maxn],p10[maxn];
char s[maxn];

inline void UP(int &x,int y){
	x+=y;
	while(x>=mod)x-=mod;
}

inline int Sum(int x){
	int A=g[x]+g[x];
	if(A>=mod) A-=mod;
	A+=mod-na[x];
	if(A>=mod) A-=mod;
	A+=mod-nb[x];
	if(A>=mod) A-=mod;
	return A;
}

void prepare(){
	f[1]=A*B;g[1]=A+B;
	p2[0]=1;For(i,1,n){
		p2[i]=(p2[i-1]<<1);
		if(p2[i]>=mod) p2[i]-=mod;
	}
	p10[0]=1;
	For(i,1,n) p10[i]=p10[i-1]*10ll%mod;
	For(i,1,n) na[i]=(na[i-1]*10ll+A)%mod;
	For(i,1,n) nb[i]=(nb[i-1]*10ll+B)%mod;
	For(i,2,n){
		int Sm=Sum(i-1);
		int vA=na[i]+mod-na[i-1],vB=nb[i]+mod-nb[i-1];
		if(vA>=mod) vA-=mod;
		if(vB>=mod) vB-=mod;
		f[i]=f[i-1];
		UP(f[i],1ll*vA*vA%mod*(p2[i-1]+mod-1)%mod);
		UP(f[i],1ll*Sm*vA%mod);
		UP(f[i],1ll*vB*vB%mod*(p2[i-1]+mod-1)%mod);
		UP(f[i],1ll*Sm*vB%mod);
		UP(f[i],f[i-1]);
		UP(f[i],1ll*(vB+na[i-1])*(vA+nb[i-1])%mod);
		UP(g[i],(g[i-1]+1ll*p2[i-1]*vA%mod)%mod);
		UP(g[i],(g[i-1]+1ll*p2[i-1]*vB%mod)%mod);
	}
}

char t[maxn];
inline int tui(char *s){
	For(i,1,n) t[i]=s[i];
	int j=n,c=0;
	for(;j && t[j]-'0'==A;j--);
	t[j]=A+'0';
	for(int i=j+1;i<=n;i++) t[i]=B+'0';
	For(i,1,n){
		c=(10ll*c+t[i]-'0')%mod;
	}
	return c;
}

inline int work(char *s){
	int prefix=0,ans=0;
	For(i,1,n){
		if(s[i]-'0'==A){
			prefix=(prefix*10ll+A)%mod;
		}else{
			int P=(prefix*10ll+A)%mod;
			P=1ll*P*p10[n-i]%mod;
			UP(ans,f[n-i]);
			UP(ans,1ll*P*P%mod*(p2[n-i]+mod-1)%mod);
			UP(ans,1ll*P*Sum(n-i)%mod);
			prefix=(10ll*prefix+B)%mod;
			int tp=1ll*prefix*p10[n-i]%mod;
			UP(ans,1ll*(P+nb[n-i])*(tp+na[n-i])%mod);
		}
	}
	return ans;
}

int main(){
	A=4;B=7;
	int Ans=0;
	scanf("%s",s+1);
	n=strlen(s+1);
	prepare();
	Ans=mod-work(s);
	scanf("%s",s+1);
	Ans+=work(s);
	if(Ans>=mod) Ans-=mod;
	printf("%d\n",Ans);
	return 0;
}