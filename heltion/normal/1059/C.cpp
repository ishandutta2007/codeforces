#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read() {LL x; scanf("%lld", &x); return x;}
void read(char *s) {scanf("%s", s);}
void no() {printf("NO"); exit(0);}
int b = 1;
void DFS(int u){
	if(u > 3){
		for(int i = 1; i <= u; i += 1) if(i & 1) printf("%d ", b);
		b *= 2;
		DFS(u / 2);
	}
	else if(u == 3){
		printf("%d %d %d ", b, b, 3 * b);
	}
	else if(u == 2){
		printf("%d %d ", b, 2 * b);
	}
	else if(u == 1) printf("%d ", b);
}
int main() {
	int n = read();
	DFS(n);
}