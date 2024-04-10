#include<cstdio>
#include<cstring>
using namespace std;
const int max=30;
int a[310000][32],b[310000][32];
int sum=0;
struct trie_tree{
	int d,son[2],tot;
	trie_tree() {son[0]=son[1]=-1;tot=0;}
}tr[11000000];int ans[310000],d[32];
void trie_insert(int id)
{
	int temp=0;
	for(int i=max;i>=1;i--)
	{
		int e=b[id][i];
		if(tr[temp].son[e]!=-1) temp=tr[temp].son[e],tr[temp].tot++;
		else
		{
			tr[temp].son[e]=++sum;
			temp=sum;tr[sum].d=e;tr[sum].tot++;
		}
	}
}
int trie_find(int id)
{
	int temp=0,sum2=0;
	for(int i=max;i>=1;i--)
	{
		int e=a[id][i];
		if(tr[temp].son[e]!=-1)
		{
			int temp2=tr[temp].son[e];
			if(tr[temp2].tot==1)
			{
				tr[temp].son[e]=-1;
				tr[temp2].tot=0;
			}
			else tr[temp2].tot--;
			temp=temp2;
		}
		else
		{
			sum2+=d[i];int temp2=tr[temp].son[1-e];
			if(tr[temp2].tot==1)
			{
				tr[temp].son[1-e]=-1;
				tr[temp2].tot=0;
			}
			else tr[temp2].tot--;
			temp=temp2;
		}
	}
	return sum2;
}
int main()
{
	int n;scanf("%d",&n);
	d[1]=1;for(int i=2;i<=max;i++) d[i]=d[i-1]*2;
	for(int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		for(int j=1;j<=max;j++)
		{
			a[i][j]=x%2;x/=2;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		for(int j=1;j<=max;j++)
		{
			b[i][j]=x%2;x/=2;
		}
		trie_insert(i);
	}
	for(int i=1;i<=n;i++)
	{
		ans[i]=trie_find(i);
	}
	for(int i=1;i<n;i++) printf("%d ",ans[i]);printf("%d\n",ans[n]);
	return 0;
}