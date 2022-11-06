#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read(){LL x; scanf("%lld", &x); return x;}
void read(char *s){scanf("%s", s);}
void no(){printf("No"); exit(0);}

#define maxn 540000
#define maxm

LL a[maxn];
int main(){
	LL ans = 0, mx = 1E10;
	int flag = 0;
	int n = read();
	for(int i = 0; i < n; i += 1){
		a[i] = read();
		ans += abs(a[i]);
		mx = min(mx, abs(a[i]));
		if(a[i] <= 0) flag |= 1;
		if(a[i] >= 0) flag |= 2;
	}
	if(n == 1) printf("%lld", a[0]);
	else printf("%lld", flag == 3 ? ans : ans - 2 * mx);
}