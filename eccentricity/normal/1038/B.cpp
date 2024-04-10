#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read(){LL x; scanf("%lld", &x); return x;}
void read(char *s){scanf("%s", s);}
void no(){printf("No"); exit(0);}

#define maxn 120000
#define maxm


int main(){
	LL n = read();
	LL s = n * (n + 1) / 2;
	for(int i = 2; i <= n; i += 1){
		if(s % i == 0){
			printf("Yes\n1 %d\n%lld ", i, n - 1);
			for(int j = 1; j <= n; j += 1) if(j != i) printf("%d ", j);
			return 0;
		}
	}
	no();
}