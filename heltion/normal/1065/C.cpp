#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read() {LL x; scanf("%lld", &x); return x;}
void read(char *s) {scanf("%s", s);}
void no() {printf("no"); exit(0);}

#define maxn 240000
LL h[maxn], c[maxn];
int main(){
	LL n = read(), minh = maxn;
	LL k = read(), ans = 0, s = 0;
	for(int i = 0; i < n; i += 1) c[h[i] = read()] += 1, minh = min(minh, h[i]);
	for(int i = maxn - 2; i >= 1; i -= 1) c[i] += c[i + 1];
	for(int i = maxn - 2; i > minh; i -= 1){
		if(s + c[i] > k){
			ans += 1;
			s = c[i];
		}
		else s += c[i];
	}
	if(s) ans += 1;
	printf("%lld", ans);
}