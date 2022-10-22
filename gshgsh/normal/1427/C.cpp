#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define abs(x) ((x)>0?(x):-(x))
#define MAXN 100001
int N,M,t[MAXN],x[MAXN],y[MAXN],f[MAXN],ans;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	N=get(),M=get();For(i,1,M)t[i]=get(),x[i]=get(),y[i]=get();x[0]=y[0]=1;memset(f,0xbf,sizeof(f));f[0]=0;
	For(i,1,M)For(j,max(i-N*4,0),i-1)if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])ans=max(ans,f[i]=max(f[i],f[j]+1));cout<<ans<<endl;return 0;
}