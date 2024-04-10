#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 2001
int N,a[MAXN];ll f[MAXN][MAXN];
int main()
{
	cin>>N;For(i,1,N)cin>>a[i];memset(f,0xbf,sizeof(f));f[0][0]=0;
	For(i,1,N)For(j,0,i){if(j&&f[i-1][j-1]+a[i]>=0)f[i][j]=max(f[i][j],f[i-1][j-1]+a[i]);if(j<i&&f[i-1][j]>=0)f[i][j]=max(f[i][j],f[i-1][j]);}
	int x=0;For(i,1,N)if(f[N][i]>=0)x=i;cout<<x<<endl;return 0;
}