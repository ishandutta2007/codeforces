#include<cstdio>
#include<iostream>
#include<set>
#include<queue>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
#define fr first
#define sc second
#define MP make_pair
using namespace std;
void upmax(int &a,int b) { if (a<b) a=b;}
void upmin(int &a,int b) { if (a>b) a=b;}
typedef long long LL;
typedef pair<int,int> PII;
//---------------------------------
const int N=4101;
int n,m,cnt;
int ans[N];
PII a[N];
int c[N],v[N],b[N];
int cmp(int i,int j) { return a[i].fr<a[j].fr;}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d%d",&a[i].fr,&a[i].sc);
	for (int i=1;i<=m;i++) b[i]=i;
	sort(b+1,b+1+m,cmp);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=0;i<=n;i++)
	{
		int flag;
		cnt=0;
		for (int j=m,l=i;j>=1;j--)
		if (a[b[j]].fr<=i)
		{
			flag=1;
			for (int k=a[b[j]].fr,h=a[b[j]].sc;k<=l;k++)
			{
				h+=c[k];
				if (h<0) { flag=0;break;}
			}
			if (flag) ans[++cnt]=b[j],l=a[b[j]].fr,v[b[j]]=i;
			else if (j==1) flag=0;
		}
		if (!flag) continue;
		for (int j=1,l=i+1;j<=m;j++)
		if (a[b[j]].fr>=i+1)
		{
			flag=1;
			for (int k=a[b[j]].fr,h=a[b[j]].sc;k>=l;k--)
			{
				h+=c[k];
				if (h<0) { flag=0;break;}
			}
			if (flag) ans[++cnt]=b[j],l=a[b[j]].fr,v[b[j]]=i;
			else if (j==n) flag=0;
		}
		if (!flag) continue;
		printf("%d\n",i>0?i:1);
		for (int j=1;j<=cnt;j++) printf("%d ",ans[j]);
		for (int j=1;j<=m;j++) if (v[j]!=i) printf("%d ",j);
		return 0;
	}
	puts("-1\n");
	return 0;
}