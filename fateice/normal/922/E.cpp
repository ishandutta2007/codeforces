#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
#define pi pair<int,int>
#define pii pair<pi,int>
#define aa first
#define bb second
#define xx aa.aa
#define yy aa.bb
#define zz bb
#define mp make_pair
#define mpp(a,b,c) mp(mp(a,b),c)
using namespace std;
int n,m,t,p,x[1010],y[1010],q;
L f[1010][10010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d%d%d%d",&n,&m,&t,&p);
	for(i=1;i<=n;i++)
	  scanf("%d",&x[i]);
	for(i=1;i<=n;i++)
	  scanf("%d",&y[i]);
	f[0][0]=m;
	for(i=1;i<=10000;i++)
	  f[0][i]=-1;
	for(i=1;i<=n;i++)
	  for(j=0;j<=10000;j++)
	    {
		 f[i][j]=-1;
		 for(k=0;k<=x[i] && k<=j;k++)
		   if(f[i-1][j-k]>=0)
		     f[i][j]=max(f[i][j],min(f[i-1][j-k]+p,m+(L)t*(j-k))-(L)y[i]*k);
		 if(f[i][j]>=0)
		   q=max(q,j);
		}
	cout<<q;
	return 0;
}