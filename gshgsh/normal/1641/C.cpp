#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int N,M,f[MAXN],mx[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
int main()
{
	N=get(),M=get();For(i,0,N)f[i]=i,mx[i]=-1;
	For(i,1,M)
	{
		int opt=get();
		if(opt==0)
		{
			int l=get(),r=get(),v=get();
			if(!v){l=getf(l-1);for(int j=getf(r);j!=l;j=getf(j-1))mx[l]=max(mx[l],mx[j]),f[j]=l;}
			else r=getf(r),mx[r]=max(mx[r],l-1);
		}
		else{int x=get();cout<<(f[x]==x?mx[x]!=-1&&getf(mx[x])==getf(x-1)?"YES\n":"N/A\n":"NO\n");}
	}
	return 0;
}