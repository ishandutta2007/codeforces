#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,N,a[MAXN],b[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
bool check(int x){int cnt=0;For(i,1,N)if(b[i]>=cnt&&a[i]>=x-cnt-1)cnt++;return cnt>=x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get(),b[i]=get();
		int l=1,r=N,ans=1;while(l<=r){int mid=l+r>>1;check(mid)?ans=mid,l=mid+1:r=mid-1;}cout<<ans<<'\n';
	}
	return 0;
}