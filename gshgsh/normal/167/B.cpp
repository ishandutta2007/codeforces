#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 201
int N,M,K,a[MAXN];double p[MAXN],f[MAXN][MAXN][MAXN],ans;
int main()
{
	cin>>N>>M>>K;For(i,1,N)cin>>p[i],p[i]/=100;For(i,1,N)cin>>a[i];For(i,1,N)For(j,1,N-1)if(a[j]<a[j+1])swap(a[j],a[j+1]),swap(p[j],p[j+1]);f[0][0][min(K,N)]=1;
	For(i,0,N-1)For(j,0,i)For(k,0,N)f[i+1][j][k]+=(1-p[i+1])*f[i][j][k],k+a[i+1]>=0?f[i+1][j+1][min(k+a[i+1],N)]+=p[i+1]*f[i][j][k]:0;
	For(i,M,N)For(j,0,N)ans+=f[N][i][j];printf("%.10lf\n",ans);return 0;
}