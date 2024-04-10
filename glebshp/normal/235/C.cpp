#pragma comment(linker, "/STACK:1000000000")
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

const int size = 2000 * 1000 + 100;

int tot, last;
int len[size];
int way[size][26];
char str[size];
int used[size];
int link[size];
int rcs[size];
bool was[size];

int n;

char query[size];

void add_automaton(int c) {
	for (int i = 0; i < 26; i++)
		way[tot][i] = -1;
	len[tot] = len[last] + 1;
	
	int p = last;
	last = tot;
	while (way[p][c] == -1) {
		way[p][c] = tot;
		p = link[p];
	}
	if (way[p][c] == tot) {
		link[tot++] = 0;
		return;
	}

	if (len[way[p][c]] == len[p] + 1)
		link[tot++] = way[p][c];
	else {
		int h = way[p][c];
		tot++;
		for (int i = 0; i < 26; i++)
			way[tot][i] = way[h][i];
		link[tot] = link[h];
		len[tot] = len[p] + 1;
		link[tot - 1] = tot;
		link[h] = tot;
		while (way[p][c] == h) {
			way[p][c] = tot;
			p = link[p];
		}
		tot++;
	}
}

void dfs(int v) {
	was[v] = true;
	for (int i = 0; i < 26; i++)
		if (way[v][i] != -1 && !was[way[v][i]])
			dfs(way[v][i]);
	
	for (int i = 0; i < 26; i++)
		if (way[v][i] != -1)
			rcs[v] += rcs[way[v][i]];
}

void build_automaton() {
	last = 0;
	tot = 1;
	for (int i = 0; i < 26; i++)
		way[last][i] = -1;
	len[0] = 0;
	link[0] = 0;

	for (int i = 0; i < n; i++)
		add_automaton(str[i] - 'a');

	while (last != 0) {
		rcs[last] = 1;
		last = link[last];
	}

	dfs(0);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	scanf("%s", str);
	n = strlen(str);
	
	build_automaton();

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%s", query);
		int ql = strlen(query);
		int p = 0;
		int sh = 0;
		int la = 0;
		for (int j = 0; j < ql; j++) {
			if (way[p][query[j] - 'a'] == -1) {
				la = j;
				break;
			}
			else {
				p = way[p][query[j] - 'a'];
				sh++;
			}
		}

		int ans = 0;

		for (int j = 0; j < ql; j++) {
			if (sh == ql && used[p] == i + 1)
				break;
			if (sh == ql) {
				used[p] = i + 1;
				ans += rcs[p];
			}
			if (sh > 0)
				sh--;
			if (sh == len[link[p]])
				p = link[p];
			while (la != j && way[p][query[la] - 'a'] != -1) {
				p = way[p][query[la] - 'a'];
				la = (la + 1) % ql;
				sh++;
			}

			if (la == j && way[p][query[j] - 'a'] != -1) {
				p = way[p][query[j] -'a'];
				la = (la + 1) % ql;
				sh++;
			}
		}

		printf("%d\n", ans);

	}

    return 0;
}