#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define PI 3.1415926535897932384626433832795

const int MAXLEN = 1000 * 100 + 1; //   
const int K = 27; //  

struct state {
	int length, link;
	int next[K];
	bool terminal;
};

state st[MAXLEN*2-1];
int sz, last;
char buf[MAXLEN];
bool used[MAXLEN * 2];
long long cnt[MAXLEN * 2], cnt2[MAXLEN * 2];
int ts[MAXLEN * 2], tsl;

void init() {
	/*
	//   ,        :
	sz = last = 0;
	for (int i=0; i<MAXLEN*2-1; ++i)
		st[i].terminal = false;
	st[0].length = 0;
	*/
	st[0].link = -1;
	memset (st[0].next, -1, sizeof st[0].next);
	++sz;
}

void sa_extend (char c) {
	int nlast = sz++;
	st[nlast].length = st[last].length + 1;
	memset (st[nlast].next, -1, sizeof st[nlast].next);
	int p;
	for (p=last; p!=-1 && st[p].next[c]==-1; p=st[p].link)
		st[p].next[c] = nlast;
	if (p == -1)
		st[nlast].link = 0;
	else {
		int q = st[p].next[c];
		if (st[p].length + 1 == st[q].length)
			st[nlast].link = q;
		else {
			int clone = sz++;
			st[clone].length = st[p].length + 1;
			memcpy (st[clone].next, st[q].next, sizeof st[clone].next);
			st[clone].link = st[q].link;
			for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
				st[p].next[c] = clone;
			st[q].link = st[nlast].link = clone;
		}
	}
	last = nlast;
}

void mark_terminal() {
	for (int p=last; p!=-1; p=st[p].link)
		st[p].terminal = true;
}

void dfs(int v)
{
	used[v] = true;
	if (st[v].terminal)
		cnt[v] = 1;
	int i;
	for (i = 0; i < K; i++)
	{
		if (st[v].next[i] == -1)
			continue;
		if (!used[st[v].next[i]])
			dfs(st[v].next[i]);
		cnt[v] += cnt[st[v].next[i]];
	}
	ts[tsl++] = v;
}

int main()
{
	int i, len, j;
	long long ans = 0;

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%s", buf);
	len = strlen(buf);
	init();
	for (i = 0; i < len; i++)
		sa_extend(buf[i] - 'a');
	mark_terminal();
	for (i = 0; i < sz; i++)
	{
		used[i] = false;
		cnt[i] = 0;
	}
	dfs(0);
	cnt2[0] = 1;
	for (i = tsl - 1; i >= 0; i--)
		for (j = 0; j < K; j++)
			if (st[ts[i]].next[j] != -1)
				cnt2[st[ts[i]].next[j]] += cnt2[ts[i]];
	for (i = 1; i < sz; i++)
		ans +=  1ll * cnt2[i] * cnt[i] * (cnt[i] + 1) / 2;
	cout << ans << endl;
}