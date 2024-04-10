#include<bits/stdc++.h>
#define int long long
#define plb pair<long long,bool>
#define mp make_pair
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
unordered_map<int,int> mem;
int phi(int x)
{
	if(mem[x]) return mem[x];
	int X=x,d=x;
	for(int i=2; i*i<=x; ++i) 
		if(x%i==0) 
		{
			d=d/i*(i-1);
			while(x%i==0) x/=i;
		}
	if(x>1) d=d/x*(x-1);
	return mem[X]=d;
}
inline plb qpow(long long s,long long y,long long mod)
{
	long long ret=1;
	bool f=0;
	if(s>=mod) s%=mod,f=1;
	for(;y;y>>=1,s=s*s,(s>=mod)&&(f=1,s%=mod)) if(y&1) ret=1ll*ret*s,(ret>=mod)&&(f=1,ret%=mod); 
	return mp(ret,f);
}
int n,p,a[100003];
inline plb solve(int l,int r,long long p)
{
	if(p==1) return mp(0,1);
	long long tmp=a[l];
	if(tmp==1) return mp(1,0);
	if(l==r) if(tmp>=p) return mp(tmp%p,1);
	else return mp(tmp,0);
	plb res=solve(l+1,r,phi(p));
	if(res.second) res.first+=phi(p);
	return qpow(tmp,res.first,p);
}
signed main()
{
	n=read(),p=read();
	for(int i=1,x; i<=n; i++) a[i]=read();
	for(int T=read(),l,r,x=1; T--;)
		l=read(),r=read(),printf("%lld\n",solve(l,r,p).first);
	return 0;
}