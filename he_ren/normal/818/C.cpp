#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAXD = 1e5 + 5;
const int MAXN = 1e5 + 5;
using namespace std;

inline int max(int a,int b){ return a>b? a: b;}
inline int min(int a,int b){ return a<b? a: b;}

struct Node
{
	int x1,y1,x2,y2,id, a,b,c,d;
}a[MAXD];

int t[MAXN];
bool can[MAXD];
inline void print(int d)
{
	for(int i=1; i<=d; ++i) printf("%d ",can[i]);
	putchar('\n');
}

int main(void)
{
	int d,n,m;
	scanf("%d%d%d",&d,&n,&m);
	for(int i=1; i<=d; ++i)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		a[i] = (Node){ x1,y1,x2,y2,i, min(x1,x2), max(x1,x2), min(y1,y2), max(y1,y2)};
	}
	int c1,c2,c3,c4;
	scanf("%d%d%d%d",&c1,&c2,&c3,&c4);
	
	memset(can,1,sizeof(can));
	
	memset(t,0,sizeof(t));
	for(int i=1; i<=d; ++i)
		++t[a[i].a];
	for(int i=1; i<=n; ++i)
		t[i]+=t[i-1];
	for(int i=1; i<=d; ++i)
		can[i] &= (t[a[i].b-1]-(a[i].a<a[i].b) == c1);
	//print(d);
	
	memset(t,0,sizeof(t));
	for(int i=1; i<=d; ++i)
		++t[a[i].b];
	for(int i=1; i<=n; ++i)
		t[i]+=t[i-1];
	for(int i=1; i<=d; ++i)
		can[i] &= (d-t[a[i].a]-(a[i].a<a[i].b) == c2);
	//print(d);
	
	memset(t,0,sizeof(t));
	for(int i=1; i<=d; ++i)
		++t[a[i].c];
	for(int i=1; i<=m; ++i)
		t[i]+=t[i-1];
	for(int i=1; i<=d; ++i)
		can[i] &= (t[a[i].d-1]-(a[i].c<a[i].d) == c3);
	//print(d);
	
	memset(t,0,sizeof(t));
	for(int i=1; i<=d; ++i)
		++t[a[i].d];
	for(int i=1; i<=m; ++i)
		t[i]+=t[i-1];
	for(int i=1; i<=d; ++i)
		can[i] &= (d-t[a[i].c]-(a[i].c<a[i].d) == c4);
	//print(d);
	
	for(int i=1; i<=d; ++i)
		if(can[i])
		{
			printf("%d",i);
			return 0;
		}
	printf("-1");
	return 0;
}