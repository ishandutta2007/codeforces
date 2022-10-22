#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
int N,M,x,y;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	int T=get();
	while(T--)
	{
		N=get(),M=get(),x=get(),y=get();
		bool flag1=0,flag2=0,flag3=0,flag=0;
		For(i,1,N)For(j,1,M)
		{
			char c;cin>>c;if(c=='B')flag1|=i==x,flag2|=j==y,flag3|=i==x&&j==y,flag=1;
		}
		if(flag3)cout<<"0\n";else if(flag1||flag2)cout<<"1\n";else if(flag)cout<<"2\n";else cout<<"-1\n";
	}
	return 0;
}