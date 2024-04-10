#include<bits/stdc++.h>
using namespace std;
struct node{
	int val,id;
	node(int V=0,int I=0){val=V,id=I;}
	bool operator < (node ano) const {return val<ano.val;}
}a[200005];
pair<int,int> zyz[10000005];
int n,buc[10000005],sp[10000005];
#define mp make_pair
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		sp[i]=true;
		a[i]=node(x,i);
	}
	if(n<=8000)
	{
		for(int i=1;i<=n;++i)	for(int j=i+1;j<=n;++j)	zyz[a[i].val+a[j].val]=mp(i,j);
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(zyz[a[i].val+a[j].val].first)
				{
					int x=zyz[a[i].val+a[j].val].first,y=zyz[a[i].val+a[j].val].second,z=i,w=j;
					if(x!=y && x!=z && x!=w && y!=z && y!=w && w!=z)
					{
						puts("YES");
						printf("%d %d %d %d",x,y,z,w);
						return 0;
					}
				}
			}
		}
		puts("NO");
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;++i)
	{
		int p=a[i].val-a[i-1].val;
		if(!buc[p])	buc[p]=i;
		else if(buc[p]!=i-1)
		{
			puts("YES");
			printf("%d %d %d %d\n",a[buc[p]-1].id,a[i].id,a[buc[p]].id,a[i-1].id);
			return 0;
		}
	}
	puts("NO");
	return 0;
}