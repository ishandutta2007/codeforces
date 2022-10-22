#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 201
int T,N,a[MAXN][MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)For(j,1,N){char c;cin>>c;a[i][j]=c-'0';}
		if(a[1][2]==a[2][1]){int cnt=0;if(a[N][N-1]==a[1][2])cnt++;if(a[N-1][N]==a[1][2])cnt++;cout<<cnt<<endl;if(a[N][N-1]==a[1][2])cout<<N<<' '<<N-1<<endl;if(a[N-1][N]==a[1][2])cout<<N-1<<' '<<N<<endl;continue;}
		if(a[N-1][N]==a[N][N-1]){int cnt=0;if(a[1][2]==a[N-1][N])cnt++;if(a[2][1]==a[N-1][N])cnt++;cout<<cnt<<endl;if(a[1][2]==a[N-1][N])cout<<"1 2\n";if(a[2][1]==a[N-1][N])cout<<"2 1\n";continue;}
		cout<<2<<endl;if(a[1][2])cout<<"1 2\n";else cout<<"2 1\n";if(a[N-1][N])cout<<N<<' '<<N-1<<endl;else cout<<N-1<<' '<<N<<endl;
	}
	return 0;
}