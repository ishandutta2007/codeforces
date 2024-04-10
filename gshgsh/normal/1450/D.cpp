#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 300001
int T,N,a[MAXN],cnt[MAXN],ans[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)cnt[i]=ans[i]=0;ans[1]=1;For(i,1,N)cnt[a[i]=get()]++,cnt[a[i]]>1?ans[1]=0:0,a[i]==1?ans[N]=1:0;
		int l=1,r=N;if(ans[N])For(i,1,N)if(!(--cnt[i])&&(a[l]==i||a[r]==i)&&cnt[i+1])ans[N-i]=1,a[l]==i?l++:r--;else break;For(i,1,N)cout<<ans[i];cout<<endl;
	}
}