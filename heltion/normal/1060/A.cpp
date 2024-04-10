#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read() {LL x; scanf("%lld", &x); return x;}
void read(char *s) {scanf("%s", s);}
void no() {printf("no"); exit(0);}

#define maxn 120
char s[maxn];
int main() {
	int n, sum = 0;
	scanf("%d %s", &n, s);
	for(int i = 0; i < n; i += 1)
		if(s[i] == '8') sum += 1;
	printf("%d", min(sum, n / 11));
}