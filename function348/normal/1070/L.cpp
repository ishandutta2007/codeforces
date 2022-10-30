#include<cstdio>
#include<iostream>
#include<set>
#include<queue>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
#include<bitset>
#define fr first
#define sc second
#define MP make_pair
using namespace std;
void upmax(int &a,int b) { if (a<b) a=b;}
void upmin(int &a,int b) { if (a>b) a=b;}
typedef long long LL;
typedef pair<int,int> PII;
//---------------------------------
#define next nxt
struct Edge{int y,z,ne;};
const int N=2020,inf=1<<30;
bitset<N> a[N];
int x[N],d[N];
int n,m,cas;
int main()
{
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) a[i].reset();
		for (int i=1;i<=n;i++) d[i]=0;
		for (int i=1;i<=m;i++)
		{
			int x,y;scanf("%d%d",&x,&y);
			a[x][y]=1;a[y][x]=1;
			d[x]++;d[y]++;
		}
		int flag=0;
		for (int i=1;i<=n;i++)
			if (d[i]%2==1) 
			{
				a[i][0]=1;a[i][i]=1;
				flag=1;
			}
		if (!flag)
		{
			puts("1");
			for (int i=1;i<=n;i++) printf("1 ");cout<<endl;
			continue;
		}
		for (int i=1;i<=n;i++)
		{
			int k=-1;
			for (int j=i;j<=n;j++)
			if (a[j][i]==1) { k=j;break;}
			if (k==-1) continue;
			if (i!=k) swap(a[i],a[k]);
			for (int j=i+1;j<=n;j++)
			if (a[j][i]==1) a[j]^=a[i];
		}
		for (int i=n;i>=1;i--)
		{
			if (a[i][i]==0) continue;
			x[i]=a[i][0];
			for (int j=i+1;j<=n;j++) 
			if (a[i][j]) x[i]^=x[j];
		}
		printf("2\n");
		for (int i=1;i<=n;i++) printf("%d ",x[i]+1);
		cout<<endl;
	}
	return 0;
}