#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

struct node {
	int next[50];
	bool win1, win2;
};

int n, k, sz=1;
node trie[200000];

void dfs(int v) {
	bool flag=false, win2=false, flag2=false;
	for (int i=0; i<50; i++) if (trie[v].next[i]) {
		flag2=true;
		dfs(trie[v].next[i]);
		if (!trie[trie[v].next[i]].win1) flag=true;
		if (!trie[trie[v].next[i]].win2) win2=true;
	}
	trie[v].win1=flag;
	if (!flag2) win2=true;
	trie[v].win2=win2;
}

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		for (int i=0, cur=0; i<s.length(); i++) {
			if (trie[cur].next[s[i]-'a']) cur=trie[cur].next[s[i]-'a'];
			else {
				trie[cur].next[s[i]-'a']=sz++;
				cur=sz-1;
			}
		}
	}
	dfs(0);
	if (!trie[0].win1) cout << "Second";
	else {
		if (trie[0].win2) cout << "First";
		else if (!(k%2)) cout << "Second";
		else cout << "First";
	}
	return 0;
}