#include<cstdio>
const int MAXN = 5e5 + 5;
const int MAXC = 1e6 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int a[MAXN],fst[MAXC],nxt[MAXN];

int t[MAXN<<2];
#define ls(u) ((u)<<1)
#define rs(u) ((u)<<1 | 1)

inline void push_up(int u){ t[u]=t[ls(u)]+t[rs(u)];}

void update(int u,int l,int r,int p,int k)
{
	if(l==r){ t[u]=k; return;}
	
	int mid=(l+r)>>1;
	if(mid>=p) update(ls(u),l,mid,p,k);
	else update(rs(u),mid+1,r,p,k);
	push_up(u);
}

int query(int u,int l,int r,int k)
{
	if(l==r) return l;
	
	int mid=(l+r)>>1;
	if(t[ls(u)]>k) return query(ls(u),l,mid, k);
	else return query(rs(u),mid+1,r, k-t[ls(u)]);
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	int c=0;
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]), chk_max(c,a[i]);
	
	for(int i=0; i<=c; ++i) fst[i]=n+1;
	for(int i=n; i>=1; --i)
		nxt[i] = fst[a[i]],
		fst[a[i]]=i;
	
	for(int i=0; i<=c; ++i)
		if(fst[i]<=n) update(1,1,n+1, fst[i],1);
	
	int r=0,l=0;
	for(int i=1; i<=n; ++i)
	{
		int j=query(1,1,n+1, m);
		if(r-l < j-i)
			l=i, r=j;
		if(j>n) break;
		
		update(1,1,n+1, i,0);
		if(nxt[i]<=n) update(1,1,n+1, nxt[i],1);
	}
	
	printf("%d %d",l,r-1);
	return 0;
}