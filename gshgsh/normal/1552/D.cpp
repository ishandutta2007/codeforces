#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 10
int T,N,a[MAXN],sum[1<<MAXN];int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,0,N-1)a[i]=get();For(i,0,(1<<N)-1){sum[i]=0;For(j,0,N-1)if((i>>j)&1)sum[i]+=a[j];}
		bool flag=0;For(i,0,N-1)flag|=!a[i];For(i,1,(1<<N)-1){For(j,1,(1<<N)-1)if(!(i&j)&&sum[i]==sum[j]){flag=1;break;}if(flag)break;}
		cout<<(flag?"YES\n":"NO\n");
	}
	return 0;
}