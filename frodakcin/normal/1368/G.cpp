#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>

const int MN = 2e5+10;
using ll = long long;

int N, M, pre[MN], post[MN], p[MN], ctr, id[MN], map[MN/2];
bool col[MN];
char s[MN];
std::vector<int> a[MN];
ll f;

char get(int i, int j){return s[j+i*M];}
int loc(int i, int j){return j+i*M;}

int c[1<<18], v[1<<18], z[1<<18];
void build(int n, int l, int r)
{
	c[n]=r-l;
	if(r-l>1)
	{
		int m=l+(r-l)/2;
		build(n<<1, l, m);
		build(n<<1|1, m, r);
	}
}
void down(int n, int l, int r)
{
	if(!z[n]) return;
	if(r-l>1)
	{
		v[n<<1]+=z[n], z[n<<1]+=z[n];
		v[n<<1|1]+=z[n], z[n<<1|1]+=z[n];
	}
	z[n]=0;
}
void upd(int n, int l, int r, int ql, int qr, int d)
{
	if(ql <= l&&r <= qr)
		z[n]+=d, v[n]+=d;
	else
	{
		int m=l+(r-l)/2;
		down(n, l, r);
		if(ql<m) upd(n<<1, l, m, ql, qr, d);
		if(m<qr) upd(n<<1|1, m, r, ql, qr, d);
		if(v[n<<1] == v[n<<1|1])
			v[n]=v[n<<1], c[n]=c[n<<1]+c[n<<1|1];
		else
		{
			int x=n<<1|(v[n<<1]>v[n<<1|1]);
			v[n]=v[x], c[n]=c[x];
		}
	}
}
//qry = full range query; don't need func
void dfs(int n)
{
	pre[n]=ctr++;
	map[id[n]]=n;
	//printf("%d: %d\n", n, id[n]);
	for(auto x:a[n])
		if(x!=p[n])
			dfs(x);
	post[n]=ctr;
}
void dfs2(int n)
{
	//printf("%d: %d\n", n, id[n]);
	int k=map[id[n]];
	assert(k!=n&&id[k]==id[n]);
	if(id[k])
	{
		upd(1, 1, ctr, pre[k], post[k], 1);
		if(!v[1]) f+=c[1];
	}
	for(auto x:a[n])
		if(x!=p[n])
			dfs2(x);
	if(id[k]) upd(1, 1, ctr, pre[k], post[k], -1);
}
int main(void)
{
	scanf("%d%d", &N, &M);
	for(int i=0;i<N;++i)
		scanf(" %s", s+i*M);
	memset(p, -1, sizeof p);
	for(int i=0,k=0,x,y=0;i<N;++i)
		for(int j=0;j<M;++j, ++k)
		{
			x=-1;
			if(s[k]=='U') id[k] = id[k+M] = ++y;
			if(s[k]=='L') id[k] = id[k+1] = ++y;
			if(s[k]=='U' && i+2<N)
				x=loc(i+2, j);
			if(s[k]=='D' && i>=2)
				x=loc(i-2, j);
			if(s[k]=='L' && j+2<M)
				x=loc(i, j+2);
			if(s[k]=='R' && j>=2)
				x=loc(i, j-2);
			if(~x)
			{
				a[x].push_back(k);
				p[k]=x;
			}
			col[k]=i+j&1;
			//printf("%d, %d - %d\n", i, j, id[k]);
		}
	for(int i=0,x;i<N*M;++i)
		if(!~p[i])
		{
			x=N*M|col[i];
			a[x].push_back(i);
			p[i]=x;
		}
	//printf("HERE\n");
	dfs(N*M);
	assert(ctr == N*M/2+1);
	build(1, 1, ctr);
	f=0;
	dfs2(N*M+1);
	printf("%lld\n", (ll)N*M*N*M/4-f);
	return 0;
}