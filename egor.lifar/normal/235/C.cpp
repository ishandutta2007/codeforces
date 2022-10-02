#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>


using namespace std;


#define next next1


int next[2000001][26], len[2000001], link[2000001];
int size, last;



void init(){
	size = 0;
	last = 0;
	len[0] = 0;
	link[0] = -1;
	for (int i = 0; i < 26; i++) {
		next[0][i] = -1;
	}
	++size;
}


void add(char c) {
	int cur = size++;
	for (int i = 0; i < 26; i++) {
		next[cur][i] = -1;
	}
	len[cur] = len[last] + 1;
	int p;
	for (p = last; p != -1 && next[p][c - 'a'] == -1; p = link[p]) {
		next[p][c - 'a'] = cur;
	}
	if (p == -1) {
		link[cur] = 0;
	} else {
		int q = next[p][c - 'a'];
		if (len[p] + 1 == len[q]) {
			link[cur] = q;
		} else {
			int clone = size++;
			len[clone] = len[p] + 1;
			for (int i = 0; i < 26; i++) {
				next[clone][i] = next[q][i];
			}
			link[clone] = link[q];
			while (p != -1 && next[p][c - 'a'] == q) {
				next[p][c - 'a'] = clone;
				p = link[p];
			}
			link[q] = link[cur] = clone;
		}
	}
	last = cur;
}


bool t[2000102];
bool kh[2000102];
int sum[2000102];
int lf = 0;
int n;
vector<int> v;


void dfs(int u) {
	sum[u] = t[u];
	kh[u] = 1;
	for (int i = 0; i < 26; i++) {
		if (next[u][i] != -1) {
			if (!kh[next[u][i]]) {
				dfs(next[u][i]);
			}
			sum[u] += sum[next[u][i]];
		}
	}
}


int used[2000102];
char q[2000001];


int main() {
	string s;
	cin >> s;
	n = (int)s.size();
	init();
	for (int i = 0; i < n; i++) {
		add(s[i]);
	}
	int f = last;
	while (f != -1) {
		t[f] = 1;
		f = link[f];
	}
	dfs(0);
	int m;
	cin >> m;
	link[0] = 0;
	for (int i = 0; i < m; i++) {
		scanf("%s", q);
		int k = strlen(q);
		int p = 0;
		int lenn = 0;
		int cur = 0;
		for (int j = 0; j < k; j++) {
			if (next[p][q[j] - 'a'] == -1) {
				cur = j;
				break;
			}
			else {
				p = next[p][q[j] - 'a'];
				lenn++;
			}
		}
		int ans = 0;
		for (int j = 0; j < k; j++) {
			if (lenn == k && used[p] == i + 1) {
				break;
			}
			if (lenn == k) {
				used[p] = i + 1;
				ans += sum[p];
			}
			if (lenn > 0) {
				lenn--;
			}
			if (lenn == len[link[p]]) {
				p = link[p];
			}
			while (cur != j && next[p][q[cur] - 'a'] != -1) {
				p = next[p][q[cur] - 'a'];
				cur = (cur + 1) % k;
				lenn++;
			}
			if (cur == j && next[p][q[j] - 'a'] != -1) {
				p = next[p][q[j] - 'a'];
				cur = (cur + 1) % k;
				lenn++;
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}