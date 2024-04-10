#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,K,a[MAXN];
int get(){char c=getchar();int x=0;while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),K=get();For(i,1,N)a[i]=get();if(K==1&&a[1]!=a[N]){cout<<-1<<endl;continue;}if(K==1){cout<<1<<endl;continue;}
		int cnt=1;For(i,2,N)cnt+=a[i]!=a[i-1];cout<<max((cnt+K-3)/(K-1),1)<<endl;
	}
	return 0;
}