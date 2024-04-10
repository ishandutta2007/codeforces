#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<set>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,l[MAXN],r[MAXN],c[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)l[i]=get(),r[i]=get(),c[i]=get();c[0]=2.1e9;
		cout<<c[1]<<'\n';int x=1,y=1,z=1;
		For(i,2,N)
		{
			if(l[i]<l[x])x=i;if(r[i]>r[y])y=i;
			if(l[i]==l[x]&&c[i]<c[x])x=i;if(r[i]==r[y]&&c[i]<c[y])y=i;
			if(l[x]!=l[z]||r[y]!=r[z])z=0;
			if(l[i]==l[x]&&r[i]==r[y]&&c[i]<c[z])z=i;
			cout<<min(c[x]+c[y],c[z])<<'\n';
		}
	}
	return 0;
}