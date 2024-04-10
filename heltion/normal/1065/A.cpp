#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read() {LL x; scanf("%lld", &x); return x;}
void read(char *s) {scanf("%s", s);}
void no() {printf("no"); exit(0);}

#define maxn 

int main(){
	int t =  read();
	while(t --){
		LL s = read(), a = read(), b = read(), c = read();
		printf("%lld\n", s / c + s / c / a * b);
	}
}