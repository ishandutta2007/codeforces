#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXB = 320;
const int mod = 1e9 + 7;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

int base1, base2, pw1[MAXN], pw2[MAXN];
void hash_init(void)
{
	base1 = (rand()%mod + 114514) %mod;
	base2 = (rand()%mod + 1919810) %mod;
	pw1[0] = pw2[0] = 1;
	for(int i=1; i<MAXN; ++i)
		pw1[i] = (ll)pw1[i-1] * base1 %mod,
		pw2[i] = (ll)pw2[i-1] * base2 %mod;
}

struct Hash_Node
{
	int val1[MAXB],val2[MAXB],len;
	void init(void){ len=0;}
	void push_back(int x)
	{
		val1[len+1] = ((ll)val1[len]*base1 + x) %mod;
		val2[len+1] = ((ll)val2[len]*base2 + x) %mod;
		++len;
	}
	pii query(int l,int r)
	{
		int res1 = val1[r] - (ll)val1[l-1]*pw1[r-l+1] %mod;
		int res2 = val2[r] - (ll)val2[l-1]*pw2[r-l+1] %mod;
		return make_pair(res1<0? res1+mod: res1, res2<0? res2+mod: res2);
	}
};

int n;
int a[MAXN];

struct Block
{
	int l,r;
	bool ok;
	Hash_Node lef,rig;
	inline void init(int l_,int r_){ l=l_; r=r_; build();}
	void build(void)
	{
		static int sta[MAXB],top;
		top=0; ok=1;
		for(int i=l; i<=r; ++i)
		{
			if(a[i]>0 || sta[top]<=0) sta[++top] = a[i];
			else
			{
				if(sta[top]+a[i]){ ok=0; return;}
				--top;
			}
		}
		
		lef.init(); rig.init();
		
		for(int i=1; i<=top && sta[i]<0; ++i) lef.push_back(-sta[i]);
		for(int i=top; i>=1 && sta[i]>0; --i) rig.push_back(sta[i]);
	}
}blk[MAXB];
int tot=0, inb[MAXN];
void block_init(void)
{
	tot = sqrt(n);
	for(int i=1; i<=tot; ++i)
		blk[i].l = (i-1)*tot + 1,
		blk[i].r = i*tot;
	if(blk[tot].r < n)
	{
		blk[tot+1].l = blk[tot].r+1,
		blk[tot+1].r = n;
		++tot;
	}
	
	for(int i=1; i<=tot; ++i)
	{
		for(int j=blk[i].l; j<=blk[i].r; ++j)
			inb[j] = i;
		blk[i].build();
	}
}

bool ok;
Hash_Node *h[MAXB];
int cur[MAXB], cnt;
void insert(Block& b)
{
	if(!ok) return;
	if(!b.ok){ ok=0; return;}
	
	Hash_Node &now = b.lef;
	int i=1;
	while(i <= now.len && cnt)
	{
		int l = min(now.len-i+1, h[cnt] -> len - cur[cnt] + 1);
		if(now.query(i, i+l-1) != h[cnt] -> query(cur[cnt], cur[cnt]+l-1)){ ok=0; return;}
		
		i+=l; cur[cnt]+=l;
		if(cur[cnt] > h[cnt] -> len) --cnt;
	}
	if(i <= now.len){ ok=0; return;}
	
	if(!b.rig.len) return;
	++cnt;
	h[cnt] = &b.rig;
	cur[cnt] = 1;
}

bool query(int l,int r)
{
	int x=inb[l], y=inb[r];
	if(x==y)
	{
		blk[tot+1].init(l,r);
		return blk[tot+1].ok && !blk[tot+1].lef.len && !blk[tot+1].rig.len;
	}
	blk[tot+1].init(l, blk[x].r);
	blk[tot+2].init(blk[y].l, r);
	
	ok=1; cnt=0;
	insert(blk[tot+1]);
	for(int i=x+1; i<y && ok; ++i)
		insert(blk[i]);
	insert(blk[tot+2]);
	
	return ok && !cnt;	
}

int main(void)
{
	srand(time(0));
	hash_init();
	
	int d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	block_init();
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int oper,x,y;
		scanf("%d%d%d",&oper,&x,&y);
		if(oper==1) a[x]=y, blk[inb[x]].build();
		else
		{
			if(query(x,y)) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}