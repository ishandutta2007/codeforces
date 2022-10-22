#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int N,M,K=1000;double f[2][MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	cin>>N>>M;
	For(i,1,N)For(j,1,K)f[i&1][j]=f[i-1&1][j]*(M-1)/M+(f[i-1&1][j+1]+j)/M/(j+1)+(f[i-1&1][j]+(j+1.0)/2)/M*j/(j+1);
	double ans=0;printf("%.10lf\n",f[N&1][1]*M);return 0;
}