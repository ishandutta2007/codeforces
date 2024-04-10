#include <bits/stdc++.h>
using namespace std;

const int mod1 = 998244353;
const int mod2 = 1000000007;

const int P1 = 323232323;
const int P2 = 2333;

int Add(int x, int y, int mod) {return x + y >= mod ? x + y - mod : x + y;}

struct Num {
	int x, y;
	Num() {x = y = 0;}
	Num(int X, int Y) {x = X, y = Y;}
	Num(int X) {x = y = X;}
	Num operator + (const Num &A) const {return Num(Add(x, A.x, mod1), Add(y, A.y, mod2));}
	Num operator * (const Num &A) const {return Num(1ll * x * A.x % mod1, 1ll * y * A.y % mod2);}
	bool operator == (const Num &A) const {return x == A.x && y == A.y;}
};

int n;
char s[1 << 19];
Num f[20][1 << 19];
Num pw[20];

void Build(int l, int r, int d) {
	if (l == r) {
		f[d][l] = s[l];
		return ;
	}
	int mid = l + r >> 1;
	Build(l, mid, d - 1), Build(mid + 1, r, d - 1);
	for (int i = l; i <= r; i++) {
		f[d][i] = f[d - 1][i] * pw[d - 1] + f[d - 1][i ^ 1 << d - 1];
	}
}

Num GetHash(int len, int x, int d) {
	return f[d][len ^ x];
}

bool cmp(int x, int y) {
	int len = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (GetHash(len, x, i) == GetHash(len, y, i)) len |= 1 << i;
	}
	return s[x ^ len] < s[y ^ len];
}

int main() {
	pw[0] = Num(P1, P2); for (int i = 1; i < 20; i++) pw[i] = pw[i - 1] * pw[i - 1];
	scanf("%d", &n);
	scanf("%s", s);
	Build(0, (1 << n) - 1, n);
	int ans = 0;
	for (int i = 1; i < (1 << n); i++) {
		if (cmp(i, ans)) ans = i;
	}
	for (int i = 0; i < (1 << n); i++) {
		int j = i ^ ans;
		if (i < j) swap(s[i], s[j]);
	}
	printf("%s\n", s);
	return 0;
}