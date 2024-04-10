#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read() {LL x; scanf("%lld", &x); return x;}
void read(char *s) {scanf("%s", s);}
void no() {printf("-1"); exit(0);}

#define maxn 1200
map<int, int> ma;
char s[maxn];
int main() {
	int n, d = 0;
	scanf("%d", &n);
	while(n -- ){
		int x;
		scanf("%s %d", s, &x);
		if(*s == 'R'){
			int y = (int)ma.size() - d;
			ma[x] = y;
		}
		if(*s == 'L'){
			d += 1;
			ma[x] = - d;
		}
		if(*s == '?'){
			int p = ma[x] + d;
			printf("%d\n", min(p, (int)ma.size() - 1 - p));
		}
	}
//	for(auto p: ma){
//		printf("%d %d\n", p.first, p.second);
//	}
}