#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 501
int T,N,M;string a,b;
bool check(int x,int y,int z){For(i,x,y)if(a[i]!=b[i-x+1])return 0;FOR(i,y-1,z)if(a[i]!=b[y*2-x+1-i])return 0;return 1;}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>a>>b;N=a.length(),M=b.length();a=" "+a,b=" "+b;
		bool flag=0;For(i,1,N)For(j,i,N)if(j-i+1<=M&&j*2-i>=M&&check(i,j,1+j*2-i-M)){flag=1;break;}
		cout<<(flag?"YES\n":"NO\n");
	}
	return 0;
}