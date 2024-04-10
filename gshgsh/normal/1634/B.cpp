#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,a[MAXN];ll x,y;
ll get(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),x=get(),y=get();For(i,1,N)a[i]=get();
		bool flag=0;For(i,1,N)flag^=a[i]&1;
		if((x&1)^(y&1)^flag)cout<<"Bob\n";else cout<<"Alice\n";
	}
	return 0;
}