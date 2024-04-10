#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001

int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	int T=get();
	while(T--)
	{
		int x=get();
		if(x<=1399)cout<<"Division 4\n";
		else if(x<=1599)cout<<"Division 3\n";
		else if(x<=1899)cout<<"Division 2\n";
		else cout<<"Division 1\n";
	}
}