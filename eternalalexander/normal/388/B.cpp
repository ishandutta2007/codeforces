#include <bits/stdc++.h>

int G[1005][1005],A[1005],tl,k;

int newnode() { return ++tl; }
void add(int x,int y) {
	G[x][y] = G[y][x] = 1;
}

std::pair<int,int> build(int k) {
	if (k == 1) {
		return {2,0};
	}
	auto p = build(k/2);
	int sta = p.first, len = p.second;
	int a = newnode(), b = newnode(), c = newnode();
	add(a,b); add(a,c); add(b,sta); add(c,sta);
	len += 2; sta = a;
	if (k & 1) {
		for (int i = 1; i < len; ++ i) A[i] = newnode();
		for (int i = 1; i + 1 < len; ++ i) add(A[i],A[i+1]);
		add(a,A[1]); add(A[len - 1],2);
	}
	return {sta,len};
}

int main() {
	scanf("%d",&k);
	tl = 2;
	add(1,build(k).first);
	printf("%d\n",tl);
	for (int i = 1; i <= tl; ++ i) {
		for (int j = 1; j <= tl; ++ j) {
			if (G[i][j]) printf("Y");
			else printf("N");
		} puts("");
	}
	return 0;
}