#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read(){LL x; scanf("%lld", &x); return x;}
void read(char *s){scanf("%s", s);}
void no(){printf("No"); exit(0);}

#define maxn 

int main(){
	int q = read();
	while(q --){
		LL n = read(), m = read(), k = read();
		if(k < max(n, m)){
			printf("-1\n");
			continue;
		}
		if((k - max(n, m)) % 2 == 0){
			printf("%lld\n", k - ((n + m) & 1));
			continue;
		}
		printf("%lld\n", k - 1 - (int)((n + m) % 2 == 0));
	}
}