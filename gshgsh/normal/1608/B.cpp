#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,a,b;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),a=get(),b=get();int lim=N-1>>1;if(a>lim||b>lim||a+b>N-2||abs(a-b)>1){cout<<"-1\n";continue;}
		if(a==b)
		{
			if(!a){For(i,1,N)cout<<i<<' ';cout<<'\n';continue;}
			For(i,1,a)cout<<i*2<<' '<<i*2-1<<' ';For(i,a*2+1,N-1)cout<<i+1<<' ';cout<<a*2+1<<'\n';continue;
		}
		if(a>b)
		{
			int l1=1,l2=a+2,tot=N-a-b-2;
			For(i,1,tot)cout<<i<<' ';For(i,1,a+b+2)cout<<tot+(i&1?l1++:l2++)<<' ';cout<<'\n';continue;
		}
		swap(a,b);int l1=1,l2=a+2,tot=N-a-b-2;
		For(i,1,tot)cout<<N+1-i<<' ';For(i,1,a+b+2)cout<<N+1-tot-(i&1?l1++:l2++)<<' ';cout<<'\n';continue;
	}
}