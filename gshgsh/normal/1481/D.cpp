#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 1001
int N,M,T,a[MAXN][MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>M;For(i,1,N)For(j,1,N){char c;cin>>c;a[i][j]=c;}
		if(M&1){cout<<"YES\n";For(i,0,M/2)cout<<"1 2 ";cout<<endl;continue;}
		if(N==2){if(a[1][2]==a[2][1]){cout<<"YES\n";For(i,1,M/2)cout<<"1 2 ";cout<<"1\n";}else cout<<"NO\n";continue;}
		int f=a[1][2]==a[2][3]?1:a[3][1]==a[1][2]?0:2;cout<<"YES\n";For(i,0,M)cout<<(i+f+M)%3+1<<' ';cout<<endl;
	}
	return 0;
}