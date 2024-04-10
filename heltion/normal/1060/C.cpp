#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read() {LL x; scanf("%lld", &x); return x;}
void read(char *s) {scanf("%s", s);}
void no() {printf("no"); exit(0);}

#define maxn 2400
LL a[maxn], b[maxn];
LL sa[maxn], sb[maxn];
struct node{
	LL x;
	LL len;
	bool operator < (const node& rhs){
		return x > rhs.x;
	}
}k[maxn];
LL p[maxn];
int main() {
	int n = read(), m = read();
	for(int i = 1; i <= n; i += 1) sa[i] = sa[i - 1] + (a[i] = read());
	for(int i = 1; i <= m; i += 1) sb[i] = sb[i - 1] + (b[i] = read());
	for(int i = 0; i <= m; i += 1) p[i] = 1LL << 60;
	for(int i = 0; i <= m; i += 1)
		for(int j = i; j <= m; j += 1){
			p[j - i] = min(p[j - i], sb[j] - sb[i]);
		}
	LL ans = 0, x = read();
	int tot = 0;
	
	for(int i = m; i >= 0; i -= 1)
		if(i == m || p[i] < p[i + 1]) k[tot ++ ] = (node){p[i], i};
		
	
	sort(k, k + tot);
	//for(int i = 0; i < tot; i += 1){
	//	printf("x : %lld len : %lld\n", k[i].x, k[i].len);
	//}
	for(int i = 0; i <= n; i += 1)
		for(int j = i + 1; j <= n; j += 1){
			LL y = sa[j] - sa[i];
			int q = lower_bound(k, k + tot, (node){x / y, 0}) - k;
			//printf("q : %d\n", q);
			if(q != tot){
				ans = max(ans, k[q].len * (j - i));
			}
		}
	printf("%lld", ans);
}