#include <iostream>
#include <cstdio>

#include <vector>
#include <bitset>
#include <algorithm>
#include <array>

#include <cassert>

using namespace std;

using vi = vector<int>;
#define pb push_back
#define sz size()
#define bg begin()
#define en end()
int qry(const vi& a, const vi& b, int c)
{
	if(a.empty()||b.empty()) return 0;
	printf("%lu\n", a.sz);
	for(int x : a)
		printf("%d ", x);
	printf("\n%lu\n", b.sz);
	for(int x : b)
		printf("%d ", x);
	printf("\n%d\n", c);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}
const int MN = 500 + 10;
int N;
int s[MN];
int o[MN];
vi T;
vi X;
int p[MN];
int main(void)
{
	scanf("%d", &N);
	for(int i = 1;i < N;i++)
		o[i-1] = i+1, T.pb(i+1);
	for(int i = 2;i <= N;i++)
		s[i] = qry(T, {1}, i);
	sort(o, o+N-1, [](const int& a, const int& b){return s[a]<s[b];});
	for(int i = 0, k, l, m, h;i < N-1;i++)
	{
		k = qry(X, {1}, o[i]);
		for(;k--;)
		{
			l = 0, h = X.sz;
			for(;h-l>1;)
			{
				m = l + ((h-l)>>1);
				if(qry(vi(X.bg+l, X.bg+m), {1}, o[i]) > 0) h = m;
				else l = m;
			}
			p[X[l]] = o[i];
			X.erase(X.bg+l);
		}
		X.pb(o[i]);
	}
	for(int i : X)
		p[i] = 1;
	printf("ANSWER\n");
	for(int i = 2;i <= N;i++)
		printf("%d %d\n", p[i], i);
	return 0;
}