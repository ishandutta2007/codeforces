#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e6;

int N;
char S[MAXN];
int nxt[MAXN][4];
char T[MAXN];

int code(char c) {
	if(c == 'N') return 0;
	else if(c == 'S') return 1;
	else if(c == 'E') return 2;
	else if(c == 'W') return 3;
	else assert(false);
	return -1;
}

bool go() {
	reverse(S, S + N);

	memset(nxt[0], 0, sizeof(nxt[0]));

	for(int i = 0; i < N; i++) {
		int v = code(S[i]) ^ 1;
		int prv = nxt[i][v];
		nxt[i][v] = i + 1;
		memcpy(nxt[i + 1], nxt[prv], sizeof(nxt[i + 1]));
	}

	int cur = 0;
	for(int i = 0; i < N; i++) {
		cur = nxt[cur][code(T[i])];
	}
	return !cur;
}

int main() {
	scanf("%d %s %s", &N, S, T);
	N--;
	if(go()) printf("YES\n");
	else printf("NO\n");
	return 0;
}