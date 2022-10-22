#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	int siz;
	int s0,s1;
}Trie[7000000];
int n,a[200005],b[200005],BIT[30],cnt=1,ans=1000000000;
int main()
{
	BIT[0]=1;
	for(int i=1;i<30;i++) BIT[i]=BIT[i-1]*2;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
		int now=1;
		for(int j=29;j>=0;j--)
		{
			if(a[i]<BIT[j])
			{
				if(Trie[now].s0==0) Trie[now].s0=++cnt;
				now=Trie[now].s0;
			}
			else
			{
				a[i]-=BIT[j];
				if(Trie[now].s1==0) Trie[now].s1=++cnt;
				now=Trie[now].s1;
			}
		}
		Trie[now].siz=1;
	}
	for(int i=cnt;i>=1;i--)
	{
		Trie[i].siz+=Trie[Trie[i].s0].siz+Trie[Trie[i].s1].siz;
	}
	for(int i=1;i<=n;i++)
	{
		int now=1,num=0;
		for(int j=29;j>=0;j--)
		{
			if(b[i]<BIT[j])
			{
				if(Trie[Trie[now].s1].siz>1) num+=Trie[Trie[now].s1].siz-1;
				now=Trie[now].s0;
			}
			else
			{
				b[i]-=BIT[j];
				if(Trie[Trie[now].s0].siz>1) num+=Trie[Trie[now].s0].siz-1;
				now=Trie[now].s1;
			}
		}
		ans=min(ans,num);
	}
	printf("%d\n",ans);
}