#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

mt19937_64 gen((unsigned long long)new char ^ time(0));
uniform_int_distribution<ll> rnd(1, 1e10);

const int B = 20;

struct Data
{
	ll a[B], sp;
	Data(void){ memset(a,0,sizeof(a)); sp = 0;}
	void init(void)
	{
		sp = gen();
		for(int i=0; i<B; ++i)
			a[i] = rnd(gen);
	}
	Data operator + (const Data &oth) const
	{
		Data res;
		for(int i=0; i<B; ++i)
			res.a[i] = a[i] + oth.a[i];
		res.sp = sp ^ oth.sp;
		return res;
	}
	Data operator - (const Data &oth) const
	{
		Data res;
		for(int i=0; i<B; ++i)
			res.a[i] = a[i] - oth.a[i];
		res.sp = sp ^ oth.sp;
		return res;
	}
	bool chk(int k) const
	{
		if(k % 2 == 0 && sp != 0) return 0;
		for(int i=0; i<B; ++i)
			if(a[i] % k != 0) return 0;
		return 1;
	}
};

struct BIT
{
	Data tree[MAXN];
	int n;
	#define lowbit(x) ((x)&-(x))
	void add(int x,Data k)
	{
		while(x<=n)
			tree[x] = tree[x] + k, x += lowbit(x);
	}
	Data query(int x)
	{
		Data res;
		while(x)
			res = res + tree[x], x ^= lowbit(x);
		return res;
	}
	Data query(int l,int r)
	{
		return query(r) - query(l-1);
	}
}tree;

Data a[MAXN];
map<int,Data> bak;

void update(int x,int k)
{
	if(!bak.count(k))
		bak[k].init();
	auto cur = bak[k];
	
	tree.add(x, cur - a[x]);
	a[x] = cur;
}

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	tree.n = n;
	for(int i=1; i<=n; ++i)
	{
		int k;
		scanf("%d",&k);
		update(i, k);
	}
	
	while(Q--)
	{
		int type;
		scanf("%d",&type);
		if(type == 1)
		{
			int x,k;
			scanf("%d%d",&x,&k);
			update(x,k);
		}
		else
		{
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			if(tree.query(l,r).chk(k))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}