#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>

const int MN = 2e5+10;
const int MQ = 5e5+10;

int N, Q, b[MN*2], d[MN*2], l[MN*2], c[MN*2][26], f[MQ*2], X, ctr, pre[MN*2], post[MN*2];
char s[MN];
std::vector<int> dw[MN*2], a[MN];
struct Query
{
	public:
		int n, i;
};
std::vector<Query> q[MN];

int append(int p, char x)
{
	if(~c[p][x])
	{
		int q=c[p][x];
		if(d[q]==d[p]+1) return q;
		else
		{
			++X;
			memcpy(c[X], c[q], sizeof*c);
			d[X]=d[p]+1, l[X]=l[q];
			l[q]=X;
			for(;~p&&c[p][x]==q;p=l[p]) c[p][x]=l[q];
			return X;
		}
	}
	int n=++X;
	d[n]=d[p]+1;
	for(;~p&&!~c[p][x];p=l[p]) c[p][x]=n;
	if(!~p) l[n]=0;
	else
	{
		int q=c[p][x];
		if(d[q]==d[p]+1) l[n]=q;
		else
		{
			++X;
			memcpy(c[X], c[q], sizeof*c);
			d[X]=d[p]+1, l[X]=l[q];
			l[n]=l[q]=X;
			for(;~p&&c[p][x]==q;p=l[p]) c[p][x]=l[q];
		}
	}
	return n;
}
void dfs(int n=0)
{
	pre[n]=ctr++;
	for(int x:dw[n])
		dfs(x);
	post[n]=ctr;
}
void upd(int n, int x)
{
	for(++n;n<=X;n+=-n&n)
		b[n-1]+=x;
}
int qry(int n)
{
	int f=0;
	for(++n;n;n-=-n&n)
		f+=b[n-1];
	return f;
}
int qry(int l, int r){return qry(r-1)-qry(l-1);}
int main()
{
	scanf("%d%d", &N, &Q);
	memset(c, -1, sizeof c);
	l[0]=-1;
	for(int i=0,j,n;i<N;++i)
	{
		scanf(" %s", s);
		for(j=n=0;s[j];++j)
		{
			n = append(n, s[j]-'a');
			a[i].push_back(n);
		}
	}
	for(int i=1;i<=X;++i) dw[l[i]].push_back(i);
	dfs();
	++X;
	assert(ctr==X);
	for(int i=0,l,r,k;i<Q;++i)
	{
		scanf("%d%d%d", &l, &r, &k), --l, --k;
		q[l].push_back({a[k].back(), i*2});
		q[r].push_back({a[k].back(), i*2+1});
	}
	for(int i=0;i<=N;++i)
	{
		for(auto x:q[i])
			f[x.i]=qry(pre[x.n], post[x.n]);
		if(i<N)
			for(int x:a[i])
				upd(pre[x], 1);
	}
	for(int i=0;i<Q;++i)
		printf("%d\n", f[i*2+1]-f[i*2]);
	return 0;
}