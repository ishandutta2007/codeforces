#include <bits/stdc++.h>

int t,n;
char s[5005];
int test(int xd,int yd) {
	if (xd == 0 && yd == 0) return 0;
	int x = 0, y = 0;
	for (int i = 1; i <= n; ++ i) {
		int lx = x, ly = y;
		if (s[i] == 'L') x--;
		if (s[i] == 'R') x++;
		if (s[i] == 'U') y++;
		if (s[i] == 'D') y--;
		if (x == xd && y == yd) { x = lx; y = ly; }
	}
	if (x == 0 && y == 0) return 1;
	return 0;
}

int main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%s",s+1);
		int x = 0, y = 0; n = std::strlen(s+1);
		std::vector<std::pair<int,int> > v;
		for (int i = 1; i <= n; ++ i) {
			if (s[i] == 'L') x--;
			if (s[i] == 'R') x++;
			if (s[i] == 'U') y++;
			if (s[i] == 'D') y--;
			v.push_back({x,y});
		}
		int flag = 0;
		for (auto P:v) {
			int X = P.first, Y = P.second;
			if (test(X,Y)) { printf("%d %d\n",X,Y); flag = 1; break; }
		}
		if (!flag) { puts("0 0"); }
	}
	return 0;
}