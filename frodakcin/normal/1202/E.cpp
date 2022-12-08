#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
 
using ll = long long;
const int MS = 2e5 + 100;
 
char t[MS];
int T;
char s[MS];
int a[MS];
int N;
ll f;
 
#define IT iterator
std::map<char, int> c[MS];
int l[MS];
int v[MS];
int X;
char ch[MS];
 
void trie_ins(char * s, int L)
{
	int p = 0, n;
	for(int i = 0;i < L;i++)
	{
		std::map<char, int>::IT it = c[p].find(s[i]);
		if(it == c[p].end())
			c[p].insert({s[i], n=++X});
		else 
			n = it->second;
		p = n;
	}
	v[n]++;
}
int q[2][MS];
void trie_bfs(void)
{
	for(int i = 0, n, p, j = 1;i < j;++i)
	{
		n = q[0][i], p = q[1][i];
		if(!n) l[n] = -1;
		else
		{
			std::map<char, int>::IT it;
			for(;~p && (it=c[p].find(ch[n])) == c[p].end();p = l[p]);
			if(!~p) l[n] = 0;
			else l[n] = it->second;
		}
		if(n) v[n] += v[l[n]];
		for(std::pair<char, int> x : c[n])
			q[0][j] = x.second, q[1][j] = l[n], ++j, ch[x.second] = x.first;
	}
}
int sfx[MS];
 
int main(void)
{
	scanf(" %s%d", t, &N);
	for(;t[T];++T);
	for(int i = 0;i < N;i++)
	{
		scanf(" %s", s+a[i]);
		for(a[i+1] = a[i];s[a[i+1]];++a[i+1]);
	}
	for(int i = 0;i < N;i++)
		trie_ins(s+a[i], a[i+1]-a[i]);
	trie_bfs();
	for(int i = 0, n = 0;i < T-1;i++)
	{
		std::map<char, int>::IT it;
		for(;~n && (it=c[n].find(t[i])) == c[n].end();n=l[n]);
		if(!~n) n = 0;
		else n = it->second;
		sfx[i] = v[n];
	}
	for(int i = 0;i <= X;i++)
		c[i].clear(), v[i] = 0;
	X = 0;
	std::reverse(t, t+T);
	for(int i = 0;i < N;i++)
		std::reverse(s+a[i], s+a[i+1]);
	for(int i = 0;i < N;i++)
		trie_ins(s+a[i], a[i+1]-a[i]);
	trie_bfs();
	for(int i = 0, n = 0;i < T-1;i++)
	{
		std::map<char, int>::IT it;
		for(;~n && (it=c[n].find(t[i])) == c[n].end();n=l[n]);
		if(!~n) n = 0;
		else n = it->second;
		f += static_cast<ll>(sfx[T-i-2])*v[n];
	}
	printf("%lld\n", f);
	return 0;
}