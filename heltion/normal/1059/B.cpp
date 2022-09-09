#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read() {LL x; scanf("%lld", &x); return x;}
void read(char *s) {scanf("%s", s);}
void no() {printf("NO"); exit(0);}
#define maxn 1200
char s[maxn][maxn], p[maxn][maxn];
int n, m;
bool check(int i, int j){
	if(i >= 0 && i < n && j >= 0 && j < m && s[i][j] == '#') return true;
	return false;
}
int main() {
	n = read(), m = read();
	for(int i = 0; i < n; i += 1) read(s[i]);
	for(int i = 0; i < n; i += 1)
		for(int j = 0; j < m; j += 1)
			p[i][j] = '.';
	for(int i = 0; i < n; i += 1)
		for(int j = 0; j < m; j += 1)
			if( check(i - 1, j - 1)
				&& check(i - 1, j)
				&& check(i - 1, j + 1)
				&& check(i, j - 1)
				&& check(i, j + 1)
				&& check(i + 1, j - 1)
				&& check(i + 1, j)
				&& check(i + 1, j + 1))
					p[i - 1][j - 1]
					= p[i - 1][j]
					= p[i - 1][j + 1]
					= p[i][j - 1]
					= p[i][j + 1]
					= p[i + 1][j - 1]
					= p[i + 1][j]
					= p[i + 1][j + 1]
					= '#';
	for(int i = 0; i < n; i += 1)
		if(strcmp(s[i], p[i])) no();
	printf("YES");
}