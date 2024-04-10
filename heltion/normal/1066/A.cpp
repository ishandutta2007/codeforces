#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read() {LL x; scanf("%lld", &x); return x;}
void read(char *s) {scanf("%s", s);}
void no() {printf("no"); exit(0);}

int main() {
	int t = read();
	while(t --){
		LL L = read(), v = read(), l = read(), r = read();
		printf("%lld\n", L / v - r / v + max(l - 1, 0LL) / v);
	}
}