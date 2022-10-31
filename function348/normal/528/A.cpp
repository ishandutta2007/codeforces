#include<cstdio>
#include<iostream>
using namespace std;
const int N=200010;
int kd[N],p[N];
int v1[N],v2[N],f1[N],f2[N],s1[N],s2[N];
int w,h,n,mx1,mx2;
long long ans[N];
int find(int i,int *f) { return f[i]==i?i:f[i]=find(f[i],f);}
void hb(int *f,int *s,int x,int y,int &mx)
{
	x=find(x,f);
	y=find(y,f);
	if (x==y) return;
	f[x]=y;
	s[y]+=s[x];
	mx=max(mx,s[y]);
}
int main()
{
	scanf("%d%d%d",&w,&h,&n);
	for (int i=1;i<=n;i++)
	{
		char ch;
		while ((ch=getchar())<=32);
		int x;
		scanf("%d",&x);
		if (ch=='H') kd[i]=2,p[i]=x,v2[x]=1;
		if (ch=='V') kd[i]=1,p[i]=x,v1[x]=1;
	}
	for (int i=1;i<=w;i++) f1[i]=i,s1[i]=1;
	for (int i=1;i<=h;i++) f2[i]=i,s2[i]=1;
	int mx1=1,mx2=1;
	for (int i=1;i<w;i++) if (!v1[i]) hb(f1,s1,i,i+1,mx1);
	for (int i=1;i<h;i++) if (!v2[i]) hb(f2,s2,i,i+1,mx2);
	for (int i=n;i>=1;i--)
	{
		ans[i]=1LL*mx1*mx2;
		if (kd[i]==1) hb(f1,s1,p[i],p[i]+1,mx1);
		if (kd[i]==2) hb(f2,s2,p[i],p[i]+1,mx2);
	}
	for (int i=1;i<=n;i++) cout<<ans[i]<<endl;
	return 0;
}