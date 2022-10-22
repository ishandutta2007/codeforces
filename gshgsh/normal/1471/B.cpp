#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,x,a[MAXN],cnt[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),x=get();ll sum=0,sum1=0;cnt[0]=100;int id=0;For(i,1,N){sum+=a[i]=get();int b=a[i];cnt[i]=0;while(b%x==0)b/=x,cnt[i]++;if(cnt[i]<cnt[id])id=i,sum1=sum-a[i];}
		cout<<sum*(cnt[id]+1)+sum1<<endl;
	}
	return 0;
}