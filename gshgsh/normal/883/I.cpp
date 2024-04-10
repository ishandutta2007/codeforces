#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<deque>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 300001
int N,K,a[MAXN],f[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
bool check(int x)
{
	deque<int>q;f[0]=1;
	For(i,K,N)
	{
		while(!q.empty()&&f[q.back()]<=f[i-K])q.pop_back();q.push_back(i-K);
		while(!q.empty()&&a[i]-a[q.front()+1]>x)q.pop_front();
		if(!q.empty())f[i]=f[q.front()];else f[i]=0;
	}
	return f[N];
}
int main()
{
	N=get(),K=get();For(i,1,N)a[i]=get();sort(a+1,a+N+1);
	int l=0,r=a[N]-a[1],ans=r;while(l<=r){int mid=l+r>>1;check(mid)?ans=mid,r=mid-1:l=mid+1;}cout<<ans<<'\n';return 0;
}