#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,a[MAXN],b[MAXN];
double dis(int x,int y){return sqrt(1ll*x*x+1ll*y*y);}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;int A=0,B=0;For(i,1,N*2){int x,y;cin>>x>>y;x?a[++A]=max(x,-x):b[++B]=max(y,-y);}sort(a+1,a+N+1);sort(b+1,b+N+1);
		double ans=0;For(i,1,N)ans+=dis(a[i],b[i]);printf("%.12lf\n",ans);
	}
	return 0;
}