#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,a[MAXN],x,y;
int getc(){char c=getchar();while(c!='0'&&c!='1')c=getchar();return c-'0';}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>x>>y;For(i,1,N)a[i]=getc();
		if(y>=0){cout<<N*(x+y)<<endl;continue;}
		int cnt0=0,cnt1=0;For(i,1,N)if(i==N||a[i]!=a[i+1])(a[i]?cnt1:cnt0)++;
		cout<<N*x+(min(cnt0,cnt1)+1)*y<<endl;
	}
	return 0;
}