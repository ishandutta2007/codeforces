#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T;ll x;
ll get(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		x=get();ll y=x,now=2;
		while(x%2==0)x/=2,now*=2;if(x==1){cout<<"-1\n";continue;}
		if((__int128_t)now*(now+1)/2<=y){cout<<now<<'\n';continue;}cout<<x<<'\n';
	}
}