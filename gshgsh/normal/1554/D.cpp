#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();if(N==1){cout<<"a\n";continue;}
		if(N&1){For(i,1,N>>1)cout<<'a';cout<<"bc";For(i,1,(N>>1)-1)cout<<'a';cout<<'\n';continue;}
		For(i,1,N>>1)cout<<'a';cout<<'b';For(i,1,(N>>1)-1)cout<<'a';cout<<'\n';
	}
	return 0;
}