#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

struct Node{
	int s, t;
	bool operator < (const Node &A) const{
		return t < A.t;
	}
}a[100010];

int p[200100];
int tot;
int T[200100];
int maxj;

void add(int x, int v){
	while (x <= maxj){
		T[x] = (T[x] + v) % mod;
		x += x & -x;
	}
}

int sum(int x){
	int res = 0;
	while (x){
		res = (res + T[x]) % mod;
		x -= x & -x;
	}
	return res;
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	p[tot++] = 0, p[tot++] = n;
	for (int i = 0; i < m; i++){
		scanf("%d%d", &a[i].s, &a[i].t);
		p[tot++] = a[i].s, p[tot++] = a[i].t;
	}
	sort(p, p + tot);
	tot = unique(p, p + tot) - p;
	maxj = tot;
	for (int i = 0; i < m; i++){
		a[i].s = lower_bound(p, p + tot, a[i].s) - p + 1;
		a[i].t = lower_bound(p, p + tot, a[i].t) - p + 1;
	}
	add(1, 1);
	sort(a, a + m);
	for (int i = 0; i < m; i++){
		int last = (sum(a[i].t - 1) - sum(a[i].s - 1) + mod) % mod;
		add(a[i].t, last);
	}
	printf("%d\n", (sum(maxj) - sum(maxj - 1) + mod) % mod);
	return 0;
}