#include <cstdio>
#include <vector>
#include <map>
#include <utility>

const int MN = 4e5 + 100;
int N, Q;

int d[MN*2], l[MN*2];
std::map<char, int> c[MN*2];
std::vector<int> lc[MN*2];
int X;

int append(int p, char x)
{
	std::map<char, int>::iterator it;
	if((it=c[p].find(x))!=c[p].end())
		return it->second;
	int n = ++X;
	d[n] = d[p]+1;
	for(;~p && (it=c[p].find(x))==c[p].end();p = l[p])
		c[p].insert({x, n});
	if(!~p)
		l[n] = 0;
	else
	{
		int q = it->second;
		if(d[q]==d[p]+1)
			l[n] = q;
		else
		{
			++X;
			d[X] = d[p]+1;
			l[X] = l[q];
			c[X] = c[q];
			l[q] = X;
			for(;~p && (it=c[p].find(x))->second == q;p = l[p])
				it->second = X;
			l[n] = X;
		}
	}
	return n;
}
char b[MN];
int q[MN], n[MN];

int f[MN];
std::vector<int> y[MN], a[MN];
char s[MN];
int e[MN];

int R;
int v[MN*2], o[MN*2][2];
void dfs(int n = 0)
{
	o[n][0] = R++;
	for(int x : lc[n])
		dfs(x);
	o[n][1] = R;
}
void upd(int n, int v)
{
	for(++n;n<=R;n+=-n&n)
		::v[n]+=v;
}
int qry(int n)
{
	int r = 0;
	for(;n;n-=-n&n)
		r += v[n];
	return r;
}

void fin(int n = 0)
{
	std::map<char, int>::iterator it;
	upd(o[::n[n]][0], 1);
	for(int x : y[n])
	{
		int n = 0;
		for(int i = e[x];i < e[x+1];++i)
			if((it=c[n].find(s[i]))==c[n].end())
			{
				n = -1;
				break;
			}
			else
				n = it->second;
		f[x] = !~n?0:qry(o[n][1])-qry(o[n][0]);
	}
	for(int x : a[n])
		fin(x);
	upd(o[::n[n]][0], -1);
}

int main(void)
{
	l[0] = -1;
	scanf("%d", &N);
	for(int i = 1, j, t;i <= N;i++)
	{
		scanf("%d", &t);
		if(t==1) j = 0;
		else scanf("%d", &j);
		scanf(" %c", b+i);
		a[j].push_back(i);
	}
	for(int i = 0, n = 0, j = 1;i < j;n = q[++i])
		for(int x : a[n])
			q[j++] = x, ::n[x]=append(::n[n], b[x]);
	for(int i = 1;i <= X;i++)
		lc[l[i]].push_back(i);
	dfs();
	//for(int i = 1;i <= N;i++) printf("string %d -> node %d (link %d)\n", i, n[i], l[n[i]]);
	scanf("%d", &Q);
	for(int i = 0, j;i < Q;i++)
	{
		scanf("%d %s", &j, s+e[i]);
		for(e[i+1] = e[i];s[e[i+1]];++e[i+1]);
		y[j].push_back(i);
	}
	fin();
	for(int i = 0;i < Q;i++)
		printf("%d\n", f[i]);
	return 0;
}