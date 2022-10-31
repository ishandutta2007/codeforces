#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=500010,mo=1000000007;
const LL inf=1e+18;
int n,h,w;
int ans;
char s[N];
LL L[N],R[N],U[N],D[N];
LL sumL[N],sumR[N];
void init()
{
	int x=0,y=0;
	int ymin=0,ymax=0,xmin=0,xmax=0;
	for (int i=0;i<w;i++) R[i]=inf;
	for (int i=0;i<w;i++) L[i]=inf;
	for (int i=0;i<h;i++) U[i]=inf;
	for (int i=0;i<h;i++) D[i]=inf;
	for (int i=1;i<=n;i++)
	{
		if (s[i]=='L') { x--;if (xmin>x) xmin=x,L[-x-1]=i;}
		if (s[i]=='R') { x++;if (xmax<x) xmax=x,R[ x-1]=i;}
		if (s[i]=='U') { y++;if (ymax<y) ymax=y,U[ y-1]=i;}
		if (s[i]=='D') { y--;if (ymin>y) ymin=y,D[-y-1]=i;}
	}
	for (int i=1;i<w;i++) if (R[i]==inf&&x>0) R[i]=R[i-x]+n;
	for (int i=1;i<w;i++) if (L[i]==inf&&x<0) L[i]=L[i+x]+n;
	for (int i=1;i<h;i++) if (U[i]==inf&&y>0) U[i]=U[i-y]+n;
	for (int i=1;i<h;i++) if (D[i]==inf&&y<0) D[i]=D[i+y]+n;
}
int main()
{
	scanf("%d%d%d",&n,&h,&w);
	scanf("%s",s+1);
	init();
	sumL[0]=L[0]%mo;for (int i=1;i<w;i++) sumL[i]=(sumL[i-1]+L[i])%mo;
	sumR[0]=R[0]%mo;for (int i=1;i<w;i++) sumR[i]=(sumR[i-1]+R[i])%mo;
	int pt=-1,flag=0;
	for (int i=0;i<w;i++) if (L[i]<R[w-i-1]) pt=i;else if (R[w-i-1]==inf) flag=1;
	for (int i=1;i<=h;i++)
	{
		LL p=min(U[i-1],D[h-i]);
		if (p==inf&&flag)
		{
			printf("-1\n");
			return 0;
		}
		int l=upper_bound(L,L+pt+1,p)-L;
		int r=upper_bound(R,R+w-pt-1,p)-R;
		LL now=1LL*(w-l-r)*p;
		if (l>0) now+=sumL[l-1];
		if (r>0) now+=sumR[r-1];
		ans=(ans+now%mo)%mo;
	}
	printf("%d\n",ans);
	return 0;
}