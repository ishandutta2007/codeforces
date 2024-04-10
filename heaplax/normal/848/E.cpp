#include<bits/stdc++.h>
#define _ %mod
#define N 50010
using namespace std;
const int mod=998244353;
int n,L,R[1<<18],p[1<<18],q[1<<18];
int add(int a){return a<mod?a:a-mod;}
int dec(int a){return a<0?a+mod:a;}
int mi(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)res=1ll*res*a _;
        a=1ll*a*a _;
        b>>=1;
    }
    return res;
}
void fft(int x[],int n,int f)
{
    for(int i=0;i<n;++i)
        if(i<R[i])
            swap(x[i],x[R[i]]);
    for(int i=1;i<n;i<<=1)
    {
        int wn=mi(3,(mod-1)/(i<<1));
        if(!~f)wn=mi(wn,mod-2);
        for(int j=0;j<n;j+=i<<1)
            for(int k=0,w=1;k<i;++k,w=1ll*w*wn _)
            {
                int l=x[j+k],r=1ll*w*x[i+j+k] _;
                x[j+k]=add(l+r);x[i+j+k]=dec(l-r);
            }
    }
    if(!~f)
    {
        int inv=mi(n,mod-2);
        for(int i=0;i<n;++i)
            x[i]=1ll*x[i]*inv _;
    }
}
int g[N],sqr[N];
struct node
{
    int n;
    vector<int> x;
    node(){n=0;}
    node operator * (const node &e)const
    {
        node res;
        int m=e.n;
        res.n=n+m;
        int nn;L=0;
        for(nn=1;nn<=n+m;nn<<=1)++L;--L;
        for(int i=0;i<nn;++i)R[i]=(R[i>>1]>>1)|((i&1)<<L);
        for(int i=0;i<nn;++i)p[i]=q[i]=0;
        for(int i=0;i<=n;++i)p[i]=x[i];
        for(int i=0;i<=m;++i)q[i]=e.x[i];
        fft(p,nn,1);fft(q,nn,1);
        for(int i=0;i<nn;++i)
            p[i]=1ll*p[i]*q[i] _;
        fft(p,nn,-1);
        for(int i=0;i<=n+m;++i)
            res.x.push_back(p[i]);
        return res;
    }
    node operator % (const int &a)const
    {
        node res=*this;
        while(res.n>=a)
            --res.n,res.x.pop_back();
        return res;
    }
}f0,f1,f2;
void add(node &a,node b,int be)
{
	for(int i=0;i<=a.n;++i)if(i+be>=0)
		a.x[i]=(a.x[i]+b.x[i+be]) _;
}
void solve(int n)
{
	if(n==0)return;
	int m=n>>1;
	node e0,e1,e2;e0.n=e1.n=e2.n=n-m-1;
	for(int i=m+1;i<=n;++i)
		e0.x.push_back(f0.x[i]),
		e1.x.push_back(f1.x[i]),
		e2.x.push_back(f2.x[i]);
	f0=f0%(m+1);f1=f1%(m+1);f2=f2%(m+1);
	solve(m);
	node g0,g1,g2;g0.n=g1.n=g2.n=n;
	for(int i=0;i<=n;++i)
		g0.x.push_back(1ll*g[i]*sqr[i] _),
		g1.x.push_back(1ll*g[i]*sqr[i+1] _),
		g2.x.push_back(1ll*g[i]*sqr[i+2] _);
	add(e0,f0*g0,m);add(e0,f1*g1,m-2);
	add(e1,f0*g1,m);add(e1,f1*g2,m-2);
	add(e2,f1*g1,m);add(e2,f2*g2,m-2);
	node a=f0,b=f1,c=f2;
	f0=e0;f1=e1;f2=e2;
	solve(n-m-1);
	for(int i=m+1;i<=n;++i)
		a.x.push_back(f0.x[i-m-1]),
		b.x.push_back(f1.x[i-m-1]),
		c.x.push_back(f2.x[i-m-1]);
	a.n=b.n=c.n=n;
	f0=a;f1=b;f2=c;
}
int main()
{
	scanf("%d",&n);
	g[0]=g[2]=1;
	for(int i=4;i<=n+3;++i)g[i]=(g[i-2]+g[i-4]) _;
	for(int i=1;i<=n+3;++i)sqr[i]=1ll*i*i _;
	f0.n=f1.n=f2.n=n;
	for(int i=0;i<=n;++i)
		f0.x.push_back(1ll*g[i]*sqr[i] _),
		f1.x.push_back(1ll*g[i]*sqr[i+1] _),
		f2.x.push_back(1ll*g[i]*sqr[i+2] _);
	solve(n);
	int ans=1ll*sqr[n-1]*(g[n-1]+g[n-3]) _*n _;
	for(int i=3;i<n;++i)
	{
		ans=(ans+1ll*sqr[i-2]*g[i-2] _*f0.x[n-i] _*(i-1)) _;
		ans=(ans+1ll*sqr[i-2]*g[i-3] _*f1.x[n-i-1] _*2*(i-1)) _;
		if(i>=4 && i+1<n)ans=(ans+1ll*sqr[i-2]*g[i-4] _*f2.x[n-i-2] _*(i-1)) _;
	}
	printf("%d\n",ans _);
}