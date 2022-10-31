#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=200010;
int n;
int a[N],id[N],ans[N];
int fa[N],s[N];
int v[N];
int cmp(int i,int j) { return a[i]>a[j];}
int find(int i) { return fa[i]==i?i:fa[i]=find(fa[i]);}
void hb(int i,int j)
{
	i=find(i),j=find(j);
	fa[j]=i;s[i]+=s[j];
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+1+n,cmp);
	for (int i=1;i<=n;i++) fa[i]=i,s[i]=1;
	for (int i=1;i<=n;i++)
	{
		int j=id[i];
		v[j]=1;
		if (v[j-1]) hb(j-1,j);
		if (v[j+1]) hb(j+1,j);
		int p=s[find(j)];
		ans[p]=max(ans[p],a[j]);
	}
	for (int i=n;i>=1;i--) ans[i]=max(ans[i],ans[i+1]);
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}