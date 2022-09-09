#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read() {LL x; scanf("%lld", &x); return x;}
void read(char *s) {scanf("%s", s);}
void no() {printf("-1"); exit(0);}

#define maxn 240000
LL a[maxn]; 
int main() {
	LL n = read(), m = read(), k = read();
	for(int i = 0; i < n; i += 1) a[i] = read();
	LL s = 0;
	for(int i = n - 1; i >= 0; i -= 1){
		if(s < a[i] && m == 0){
			printf("%lld", n - 1 - i);
			return 0;
		}
		if(s < a[i]){
			m -= 1;
			s = k;
		}
		s -= a[i];
	}
	printf("%lld", n);
}