#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define INF 0x3fffffff
#define MAXN 200001
int T,N,a[MAXN],f[MAXN][2];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>a[i];f[1][0]=a[1];f[0][0]=f[1][1]=INF;
		For(i,2,N)f[i][0]=min(f[i-1][1]+a[i],f[i-2][1]+a[i]+a[i-1]),f[i][1]=min(f[i-1][0],f[i-2][0]);cout<<min(f[N][0],f[N][1])<<endl;
	}
	return 0;
}