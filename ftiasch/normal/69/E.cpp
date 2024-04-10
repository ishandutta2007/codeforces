#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>

using namespace std;

const int N = 100000 + 1;
int n, m, a[N], p[N], k[N], t[N], o[N], c[N][2], s = 0;

int max(int a, int b){
	return a < b? b: a;
}

void update(int x){
	o[x] = max(o[c[x][0]], o[c[x][1]]);
	if(t[x] == 1)
		o[x] = max(o[x], k[x]);
}

void rotate(int &x, int t){
	int y = c[x][t];
	c[x][t] = c[y][1 - t];
	c[y][1 - t] = x;
	update(x);
	update(y);
	x = y;
}

void insert(int &x, int a){
	if(!x){
		x = ++ s;
		p[x] = rand();
		k[x] = o[x] = a;
		t[x] = 1;
	}else if(k[x] == a)
			t[x] ++;
	else{
		int t = a < k[x];
		insert(c[x][t], a);
		if(p[c[x][t]] < p[x])
			rotate(x, t);
	}
	update(x);
}

void remove(int &x, int a){
	if(k[x] == a)
		t[x] --;
	else{
		int t = a < k[x];
		remove(c[x][t], a);
	}
	update(x);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++ i)
		scanf("%d", a + i);
	p[0] = INT_MAX;
	t[0] = 0;
	o[0] = INT_MIN;
	memset(t, 0, sizeof(t));
	memset(c, 0, sizeof(c));
	int r = 0;
	for(int i = 1; i <= m; ++ i)
		insert(r, a[i]);
	if(o[r] == INT_MIN)
		printf("Nothing\n");
	else
		printf("%d\n", o[r]);
	for(int i = m + 1; i <= n; ++ i){
		insert(r, a[i]);
		remove(r, a[i - m]);
		if(o[r] == INT_MIN)
			printf("Nothing\n");
		else
			printf("%d\n", o[r]);
	}
	return 0;
}