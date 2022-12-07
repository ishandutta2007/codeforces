#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second

const int N = 1005;
int n, i, j, a, b, c;
int deg [N];
bool del [N];
vector <int> e [N];
vector <int> vec;

int ask (int a, int b)
	{
	printf ("? %d %d\n", a, b);
	fflush(stdout);
	int res;
	scanf ("%d", &res);
	return res;
	}

void answer (int a)
	{
	printf ("! %d\n", a);
	fflush(stdout);
	exit(0);
	}

int main ()
	{
	scanf ("%d", &n);
	
	for (i=1; i<n; i++)
		{
		scanf ("%d%d", &a, &b);
		deg[a]++;
		deg[b]++;
		e[a].push_back(b);
		e[b].push_back(a);
		}
	
	for (i=1; i<=n; i++)
		if (deg[i] == 1)
			{
			del[i] = true;
			vec.push_back(i);
			}
	
	while (vec.size() >= 2)
		{
		a = vec.back();
		vec.pop_back();
		b = vec.back();
		vec.pop_back();
		c = ask(a, b);

		if (c == a || c == b)
			answer(c);
		
		for (int v : e[a])
			if (--deg[v] == 1 && del[v] == false)
				{
				del[v] = true;
				vec.push_back(v);
				}
		for (int v : e[b])
			if (--deg[v] == 1 && del[v] == false)
				{
				del[v] = true;
				vec.push_back(v);
				}
		}
	
	assert(vec.size() == 1);
	answer(vec[0]);
	
	return 0;
	}