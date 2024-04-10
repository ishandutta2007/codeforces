#include<cstdio>
const int MAXN = 3e5 + 5;
const int MAXM = 3e5 + 5;
const int MAXP = MAXN + MAXM;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int p;
int tree[MAXP],pos[MAXN];
#define lowbit(x) ((x)&-(x))
inline void update(int x,int k)
{
	while(x<=p)
		tree[x]+=k,
		x+=lowbit(x);
}
inline int query(int x)
{
	int res=0;
	while(x)
		res+=tree[x],
		x^=lowbit(x);
	return res;
}

int mx[MAXN],mn[MAXN];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	p=n+m;
	
	for(int i=1; i<=n; ++i)
	{
		mx[i]=mn[i]=i;
		pos[i]=i+m;
		update(i+m,1);
	}
	for(int i=1,now=m+1; i<=m; ++i)
	{
		int x;
		scanf("%d",&x);
		mn[x]=1;
		chk_max(mx[x], query(pos[x]));
		update(pos[x],-1);
		pos[x]=--now;
		update(pos[x],1);
	}
	for(int i=1; i<=n; ++i)
		chk_max(mx[i], query(pos[i]));
	
	for(int i=1; i<=n; ++i)
		printf("%d %d\n",mn[i],mx[i]);
	return 0;
}