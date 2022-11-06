#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read(){LL x; scanf("%lld", &x); return x;}
void read(char *s){scanf("%s", s);}
void no(){printf("NO"); exit(0);}

#define maxn 120000
#define maxm

char s[maxn];
int c[maxn];
int main(){
	int n = read(), k = read(), ans = n + 1;
	read(s);
	for(int i = 0; i < n; i += 1) c[s[i] - 'A'] += 1;
	for(int i = 0; i < k; i += 1) ans = min(ans, c[i]);
	printf("%d", ans * k);
}