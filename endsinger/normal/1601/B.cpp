#include<bits/stdc++.h>
using namespace std;
const int N=300005,inf=1e9;
int n,a[N],b[N],f[N],q[N],bg,ed,d[N],p[N];
int fa(int x){return x==f[x]?x:f[x]=fa(f[x]);}
vector<int>s;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		f[i]=i,d[i]=inf;
	d[n]=0;
	q[ed++]=n;
	while(bg<ed)
	{
		int u=q[bg++];
		int x=u+b[u];
		if(a[x]>=x)
		{
			p[0]=u;
			break;
		}
		for(int i=fa(x-a[x]);i<x;i=fa(i+1))
		{
			d[i]=d[u]+1;
			p[i]=u;
			q[ed++]=i;
			f[i]=fa(i+1);
		}
	}
	if(!p[0])
	{
		puts("-1");
		return 0;
	}
	for(int i=0;i!=n;i=p[i])
		s.push_back(i);
	printf("%d\n",s.size());
	for(int i=(int)s.size()-1;i>=0;i--)
		printf("%d ",s[i]);
	return 0;
}