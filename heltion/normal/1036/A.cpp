#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read(){LL x; scanf("%lld", &x); return x;}
void read(char *s){scanf("%s", s);}
void no(){printf("No"); exit(0);}

#define maxn 

int main(){
	LL n = read(), k = read();
	printf("%lld", (k + n - 1)/ n);
}