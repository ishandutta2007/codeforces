#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int main()
{
	int T;cin>>T;
	while(T--)
	{
		int N,M;cin>>N>>M;
		if((N&1)&&(M&1))
		{
			For(i,1,M)cout<<(i&1);cout<<endl;
			For(i,2,N-1){For(j,1,M)cout<<(i&1&&(j==1||j==M));cout<<endl;}
			For(i,1,M)cout<<(i&1);cout<<endl;
		}
		else if((N&1)&&!(M&1))
		{
			For(i,1,M)cout<<(i+1<M?i&1:i==M);cout<<endl;
			For(i,2,N-1){For(j,1,M)cout<<(i&1&&(j==1||j==M));cout<<endl;}
			For(i,1,M)cout<<(i+1<M?i&1:i==M);cout<<endl;
		}
		else if(!(N&1)&&(M&1))
		{
			For(i,1,M)cout<<(i&1);cout<<endl;
			For(i,2,N-1){For(j,1,M)cout<<(i+1<N&&(i&1)&&(j==1||j==M));cout<<endl;}
			For(i,1,M)cout<<(i&1);cout<<endl;
		}
		else
		{
			For(i,1,M)cout<<(i&1);cout<<endl;
			For(i,2,N-1){For(j,1,M)cout<<(i&1&&(j==1||j==M));cout<<endl;}
			For(i,1,M)cout<<((i&1)&&(i>2)&&(i<M-1));cout<<endl;
		}
	}
}