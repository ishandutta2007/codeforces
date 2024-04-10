#include<cstdio>
#include<iostream>
#include<set>
#define MP make_pair
#define FR first
#define SC second
using namespace std;
typedef pair<int,int> PII;
typedef pair<PII,PII> PIII;
typedef set<PIII>::iterator MAPI;
const int N=30;
int n,flag,sol;
int a[N],b[N],c[N],ans[N];
set<PIII> S;
void dfs1(int i,int t,int k1,int k2,int k3,int k4)
{
	if (i==t+1) { S.insert(MP( MP(k1-k2,k1-k3),MP(k1,k4) ));return;}
	dfs1(i+1,t,k1+a[i],k2+b[i],k3,k4*3);
	dfs1(i+1,t,k1+a[i],k2,k3+c[i],k4*3+1);
	dfs1(i+1,t,k1,k2+b[i],k3+c[i],k4*3+2);
}
void dfs2(int i,int t,int k1,int k2,int k3,int k4)
{
	if (i==t+1) 
	{
		MAPI it=S.lower_bound(MP(MP(k2-k1,k3-k1+1),MP(-2000000000,0)));
		if (it==S.begin()) return;
		it--;
		if ( (*it).FR.FR==k2-k1&&(*it).FR.SC==k3-k1&&k1+(*it).SC.FR>sol) 
		{
			flag=1;sol=k1+(*it).SC.FR;
			int p=(*it).SC.SC,q=k4;
			for (int j=n/2;j>=1;j--) ans[j]=p%3,p/=3;
			for (int j=n;j>=n/2+1;j--) ans[j]=q%3,q/=3;
		}
		return;
	}
	dfs2(i+1,t,k1+a[i],k2+b[i],k3,k4*3);
	dfs2(i+1,t,k1+a[i],k2,k3+c[i],k4*3+1);
	dfs2(i+1,t,k1,k2+b[i],k3+c[i],k4*3+2);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
	if (n==1)
	{
		if (a[1]==b[1]&&a[1]==c[1]) printf("LM\n");
		else if (a[1]==b[1]) printf("LM\n");
		else if (a[1]==c[1]) printf("LW\n");
		else if (b[1]==c[1]) printf("MW\n");
		else printf("Impossible\n");
		return 0;
	}
	sol=-2000000000;
	dfs1(1,n/2,0,0,0,0);
	dfs2(n/2+1,n,0,0,0,0);
	if (flag) 
	for (int i=1;i<=n;i++) 
	{
		if (ans[i]==0) printf("LM\n");
		if (ans[i]==1) printf("LW\n");
		if (ans[i]==2) printf("MW\n");
	}
	else printf("Impossible\n");
	return 0;
}