#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,M,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>M;if(M*2>=N){cout<<-1<<endl;continue;}
		int j=2;For(i,1,N)a[i]=0;For(i,1,M)a[j]=N-i+1,j+=2;j=0;For(i,1,N)if(!a[i])a[i]=++j;
		For(i,1,N)cout<<a[i]<<' ';cout<<endl;
	}
	return 0;
}