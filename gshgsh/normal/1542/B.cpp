#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	int T=get();
	while(T--)
	{
		int N=get(),a=get(),b=get();
		if(a!=1){ll x=1;bool flag=0;while(x<=N){if((N-x)%b==0){flag=1;break;}x*=a;}cout<<(flag?"Yes\n":"No\n");}
		else cout<<((N-1)%b==0?"Yes\n":"No\n");
	}
	return 0;
}