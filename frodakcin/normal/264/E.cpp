#include <iostream>
#include <cstdio>

#include <set>
#include <functional>
#include <stack>

#include <cassert>

using namespace std;

const int MN = 1e5 + 100;
const int MM = 2e5 + 10000;

template<class T> bool mx(T& a, const T& b) {return a < b ? a = b, 1 : 0;}

template<int MS> struct ST
{
	int s;
	int v[MS];
	void init(int n, int l, int r)
	{
		v[n] = 0;
		if(r-l>1)
		{
			int m = l + (r-l>>1);
			init(n<<1, l, m);
			init(n<<1|1, m, r);
		}
	}
	void init(int s)
	{
		init(1, 0, this->s = s);
	}
	void upd(int n, int l, int r, int q, int x)
	{
		if(r-l>1)
		{
			int m = l + (r-l>>1);
			if(q < m) upd(n<<1, l, m, q, x);
			else upd(n<<1|1, m, r, q, x);
			v[n] = max(v[n<<1], v[n<<1|1]);
		}
		else
			v[n] = x;
	}
	void upd(int q, int x) {return upd(1, 0, s, q, x);}
	int qry(int n, int l, int r, int q)
	{
		if(q <= l) return v[n];
		int m = l + (r-l>>1);
		int f = qry(n<<1|1, m, r, q);
		if(q < m) mx(f, qry(n<<1, l, m, q));
		return f;
	}
	int qry(int q) {return qry(1, 0, s, q);}
};

ST<MM<<2> t[2];

int N, M;
int p[MM], h[MM];
const auto cmpp = [](const int& a, const int& b) ->bool {return p[a] < p[b];};
const auto cmph = [](const int& a, const int& b) ->bool {return h[a] < h[b];};
using si = set<int, function<bool(const int&, const int&)> >;

si s[2];

int del(int i)
{
	s[0].erase(i), s[1].erase(i);
	t[0].upd(p[i], 0), t[1].upd(h[i], 0);
	return i;
}
void add0(int i)
{
	s[0].insert(i), s[1].insert(i);
	//assert(*s[0].begin()==i);
	int w = 1+t[1].qry(h[i]);
	t[0].upd(p[i], w), t[1].upd(h[i], w);
}
void add1(int i)
{
	s[0].insert(i), s[1].insert(i);
	//assert(*s[1].begin()==i);
	int w = 1+t[0].qry(p[i]);
	t[0].upd(p[i], w), t[1].upd(h[i], w);
}
using stk = stack<int>;
stk k;
int main(void)
{
	s[0] = si(cmpp), s[1] = si(cmph);
	scanf("%d%d", &N, &M);
	t[0].init(N+10), t[1].init(M+100);
	for(int i = 0;i < M;i++)
	{
		int o;
		scanf("%d", &o);
		if(o==1)
		{
			scanf("%d%d", p + i, h + i), h[i] += M-i;
			for(int z;!s[1].empty()&&h[z=*s[1].begin()]<h[i];)
				k.push(del(z));
			add1(i);
			for(;!k.empty();k.pop())
				add1(k.top());
		}
		else
		{
			int x;
			scanf("%d", &x);
			for(int j = 0;j < x;j++)
				k.push(del(*s[0].begin()));
			k.pop();
			for(;!k.empty();k.pop())
				add0(k.top());
		}
		printf("%d\n", t[0].qry(0));
		//assert(t[0].qry(0) == t[1].qry(0));
	}
	return 0;
}