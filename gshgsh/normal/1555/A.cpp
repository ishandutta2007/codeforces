#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
ll get(){ll x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	int T=get();
	while(T--)
	{
		ll N=get();if(N<6)cout<<"15\n";else if(N&1)cout<<(N+1>>1)*5<<'\n';else cout<<(N>>1)*5<<'\n';
	}
	return 0;
}