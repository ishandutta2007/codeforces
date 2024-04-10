#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,a[1111111],xx,yy;
long long pre[1111111];
double ans[1111111];
deque<int> q;
long long cross(long long x,long long y,long long xx,long long yy)
{
	return (x*yy-y*xx);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	q.push_back(0);q.push_back(1);
	for (int i=2;i<=n;i++)
	{
		while(q.size()>1)
		{
			xx=q[(int)q.size()-1];yy=q[(int)q.size()-2];
			if (cross(i-xx,pre[i]-pre[xx],xx-yy,pre[xx]-pre[yy])>0) q.pop_back();
			else break;
		}
		q.push_back(i);
	}
	for (int i=0;i<(int)q.size()-1;i++)
	{
		xx=q[i];yy=q[i+1];
		for (int j=xx+1;j<=yy;j++) ans[j]=(double)(pre[yy]-pre[xx])/(double)(yy-xx);
	}
	for (int i=1;i<=n;i++) printf("%.9lf\n",ans[i]);
	return Accepted;
}