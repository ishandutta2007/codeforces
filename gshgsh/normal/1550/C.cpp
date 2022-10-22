#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int T,N,a[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
bool check(int l,int r,int x){For(i,l,r-1)For(j,i+1,r)if((a[i]>=a[j]&&a[j]>=x)||(a[i]<=a[j]&&a[j]<=x))return 0;return 1;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();
		int r=0,ans=0;For(i,1,N){while(r<N&&check(i,r,a[r+1]))r++;ans+=r-i+1;}
		cout<<ans<<endl;
	}
	return 0;
}