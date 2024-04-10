#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

const int N = 100000;

struct data{int x, y;};

int n, x[N], t[N], v, b[N], g[N];
struct data a[N];

int cmp(const void *x, const void *y){
	struct data a = *(data *)x;
	struct data b = *(data *)y;
	if(a.x == b.x)
		return a.y - b.y;
	return a.x - b.x;
}

int find(int x){
	int l = 0, r = n - 1;
	while(l != r){
		int m = (l + r + 1) >> 1;
		if(g[m] <= x)
			l = m;
		else
			r = m - 1;
	}
	return l;
}

int work(){
	g[0] = INT_MIN;
	for(int i = 1; i != n; ++ i)
		g[i] = INT_MAX;
	int res = 0;
	for(int i = 0; i != n; ++ i){
		if(b[i])
			continue;
		int tmp = find(a[i].y) + 1;
		if(a[i].y < g[tmp])
			g[tmp] = a[i].y;
		if(tmp > res)
			res = tmp;
	}
	return res;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i != n; ++ i)
		scanf("%d%d", x + i, t + i);
	scanf("%d", &v);
	for(int i = 0; i != n; ++ i)
		a[i].x = v * t[i] - x[i],
		a[i].y = v * t[i] + x[i];
	qsort(a, n, sizeof(data), cmp);
	for(int i = 0; i != n; ++ i)
		b[i] = a[i].x < 0 || a[i].y < 0;
	int tmp = work();
	memset(b, 0, sizeof(b));
	printf("%d %d\n", tmp, work());
	return 0;
}