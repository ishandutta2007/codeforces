#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,a[MAXN],cnt[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();For(i,0,100)cnt[i]=0;For(i,1,N)cnt[a[i]]++;
		int ans1=0,ans2=0;while(cnt[ans1])cnt[ans1]--,ans1++;while(cnt[ans2])cnt[ans2]--,ans2++;
		cout<<ans1+ans2<<endl;
	}
	return 0;
}