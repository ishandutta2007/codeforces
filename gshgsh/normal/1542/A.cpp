#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	int T=get();
	while(T--)
	{
		int N=get();int cnt1=0;For(i,1,N*2)cnt1+=get()&1;
		if(cnt1==N)cout<<"YES\n";else cout<<"NO\n";
	}
	return 0;
}