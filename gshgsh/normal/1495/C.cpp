#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 501
int T,N,M;char a[MAXN][MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>M;For(i,1,N)For(j,1,M)cin>>a[i][j];
		if(M%3==0){For(i,1,N)For(j,1,M/3)a[i][j*3-1]='X';For(i,1,M/3-1){int x=1;while(x<N&&a[x][i*3]=='.'&&a[x][i*3+1]=='.')x++;a[x][i*3]=a[x][i*3+1]='X';}}
		else{For(i,1,N)For(j,1,M/3+1)a[i][j*3-2]='X';For(i,1,M/3){int x=1;while(x<N&&a[x][i*3-1]=='.'&&a[x][i*3]=='.')x++;a[x][i*3-1]=a[x][i*3]='X';}}
		For(i,1,N)For(j,1,M)cout<<a[i][j],j==M?cout<<'\n',0:0;
	}
	return 0;
}