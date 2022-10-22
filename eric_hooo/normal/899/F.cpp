#include <bits/stdc++.h>
using namespace std;

char buf[200010];
string s;

int read(){
	int x = 0;
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ '0'), c = getchar();
	return x;
}

void print(int x){
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

int key(char c){
	return c >= 'a' && c <= 'z' ? c - 'a' : c >= 'A' && c <= 'Z' ? c - 'A' + 26 : c - '0' + 26 + 26;
}

int T[200010];
int T1[200010][70];
int n, m;

void add(int x, int v){
	while (x <= n + 5){
		T[x] += v;
		x += x & -x;
	}
}

void add1(int x, int v, int p){
	while (x <= n + 5){
		T1[x][p] += v;
		x += x & -x;
	}
}

int sum1(int x, int p){
	int res = 0;
	while (x){
		res += T1[x][p];
		x -= x & -x;
	}
	return res;
}

int sum(int x){
	int res = 0;
	while (x){
		res += T[x];
		x -= x & -x;
	}
	return res;
}

int main(){
	n = read(), m = read();
	scanf("%s", buf), s = buf;
	s = " " + s;
	for (int i = 1; i <= n; i++){
		add(i, 1), add1(i, 1, key(s[i]));
	}
	for (int i = 0; i < m; i++){
		int L = read(), R = read(); char c = getchar();
		int l = 1, r = n;
		while (l < r){
			int mid = (l + r) >> 1;
			if (sum(mid) < L) l = mid + 1;
			else r = mid;
		}
		L = l - 1;
		while (sum(L) < R){
			int l = L, r = n + 5;
			int x = sum1(L, key(c));
			while (l < r){
				int mid = (l + r) >> 1;
				if (sum1(mid, key(c)) <= x) l = mid + 1;
				else r = mid;
			}
			if (sum(l) >= R || l > n) break;
			L = l, add1(L, -1, key(c)), add(L, -1), R--;
		}
		l = 1, r = n;
		while (l < r){
			int mid = (l + r) >> 1;
			if (sum(mid) < R) l = mid + 1;
			else r = mid;
		}
		if (sum(l) - sum(l - 1) == 1 && s[l] == c) add(l, -1), add1(l, -1, key(c));
	}
	for (int i = 1; i <= n; i++){
		if (sum(i) - sum(i - 1) == 1) putchar(s[i]);
	}
	printf("\n");
	return 0;
}