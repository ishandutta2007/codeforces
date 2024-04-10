#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;if(N&1){cout<<"3 1 2 ";For(i,4,N)cout<<(i^1)<<" \n"[i==N];}
		else For(i,1,N)cout<<(i&1?i+1:i-1)<<" \n"[i==N];
	}
	return 0;
}