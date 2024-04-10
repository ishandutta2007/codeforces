#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,a[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getc(){char c=getchar();while(c!='B'&&c!='R'&&c!='W')c=getchar();return c=='B'?0:c=='R'?1:2;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=getc();
		bool flag=1;bool f0=0,f1=0;
		For(i,1,N+1)if(a[i]==2||i==N+1)
		{
			if(!f0&&!f1)continue;
			if(f0^f1){flag=0;break;}
			f0=f1=0;
		}
		else if(a[i]==0)f0=1;
		else f1=1;
		cout<<(flag?"YES\n":"NO\n");
	}
}