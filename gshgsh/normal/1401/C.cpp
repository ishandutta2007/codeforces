#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,a[MAXN],b[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();int mn=a[1];For(i,2,N)mn=min(mn,a[i]);
		vector<int>v;For(i,1,N)if(a[i]%mn==0)v.push_back(a[i]);sort(v.begin(),v.end());
		FOR(i,N,1)if(a[i]%mn==0)b[i]=v.back(),v.pop_back();else b[i]=a[i];
		bool flag=1;For(i,2,N)if(b[i]<b[i-1])flag=0;cout<<(flag?"YES\n":"NO\n");
	}
	return 0;
}