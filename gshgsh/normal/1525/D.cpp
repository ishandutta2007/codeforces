#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define abs(x) ((x)>0?(x):-(x))
#define MAXN 5001
int N,M,a[MAXN],b[MAXN],f[MAXN][MAXN];
int main()
{
	cin>>N;For(i,1,N)cin>>a[i],a[i]?b[++M]=i:0;memset(f,0x3f,sizeof(f));f[0][0]=0;
	For(i,0,N-1)For(j,0,min(i,M)){f[i+1][j]=min(f[i+1][j],f[i][j]);if(j<M&&!a[i+1])f[i+1][j+1]=min(f[i+1][j+1],f[i][j]+abs(b[j+1]-i-1));}
	cout<<f[N][M]<<endl;return 0;
}