#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;if(N&1)For(i,1,N-1){For(j,1,min(N-i,N-1>>1))cout<<1<<' ';For(j,min(N-i,N-1>>1)+1,N-i)cout<<-1<<' ';}
		else For(i,1,N){For(j,1,min(N-i,N-1>>1))cout<<1<<' ';if((N-1>>1)<N-i)cout<<0<<' ';For(j,min(N-i,N-1>>1)+2,N-i)cout<<-1<<' ';}cout<<endl;
	}
	return 0;
}