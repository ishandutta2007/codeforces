#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define abs(x) ((x)>0?(x):-(x))
#define INF 0x3fffffffffffffff
#define MAXN 200001
ll T,N,t[MAXN],x[MAXN],ans;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'?f=-1:0,c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)t[i]=get(),x[i]=get();ll pos=0,to=0,tim0=0,tim1=0,dir=1;ans=0;bool vis=0;t[N+1]=INF;
		For(i,1,N)if(t[i]>=tim1)pos=to,tim0=t[i],tim1=abs(x[i]-pos)+t[i],to=x[i],dir=(x[i]>pos?1:-1),ans+=(i==N||tim1<=t[i+1]),vis=1;
		else if(vis)ans+=(pos+dir*(t[i]-tim0)<=x[i]&&pos+dir*(min(tim1,t[i+1])-tim0)>=x[i])||(pos+dir*(t[i]-tim0)>=x[i]&&pos+dir*(min(tim1,t[i+1])-tim0)<=x[i]);
		cout<<ans<<endl;
	}
	return 0;
}