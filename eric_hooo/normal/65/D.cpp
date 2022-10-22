#include <bits/stdc++.h>
using namespace std;

const long long P = 10001;

char s[10010];
int n;
int a[4];
set <long long> all;
int ans[4];

long long get_hash() {
	return ((a[0] * P + a[1]) * P + a[2]) * P + a[3];
}

int get_id(char c) {
	return c == 'G' ? 0 : c == 'H' ? 1 : c == 'R' ? 2 : 3;
}

void dfs(int now) {
	if (all.count(get_hash())) return ;
	all.insert(get_hash());
	if (now == n) {
		int minj = min(min(a[0], a[1]), min(a[2], a[3]));
		if (a[0] == minj) ans[0] = 1;
		if (a[1] == minj) ans[1] = 1;
		if (a[2] == minj) ans[2] = 1;
		if (a[3] == minj) ans[3] = 1;
		return ;
	}
	if (s[now] != '?') {
		a[get_id(s[now])]++;
		dfs(now + 1);
		a[get_id(s[now])]--;
		return ;
	}
	int minj = min(min(a[0], a[1]), min(a[2], a[3]));
	if (a[0] == minj) a[0]++, dfs(now + 1), a[0]--;
	if (a[1] == minj) a[1]++, dfs(now + 1), a[1]--;
	if (a[2] == minj) a[2]++, dfs(now + 1), a[2]--;
	if (a[3] == minj) a[3]++, dfs(now + 1), a[3]--;
}

int main () {
	scanf("%d", &n);
	scanf("%s", s);
	dfs(0);
	if (ans[0]) printf("Gryffindor\n");
	if (ans[1]) printf("Hufflepuff\n");
	if (ans[2]) printf("Ravenclaw\n");
	if (ans[3]) printf("Slytherin\n");
	return 0;
}