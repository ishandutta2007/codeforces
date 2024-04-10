#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

const int N = 200001;

struct point{int x, y;};

struct point make_point(int a, int b){
	struct point p = {a, b};
	return p;
}

int cmp(struct point a, struct point b){
	if(a.x == b.x)
		return a.y - b.y;
	return a.x - b.x;
}

struct point fromto(struct point a, struct point b){
	return make_point(b.x - a.x, b.y - a.y);
}

long long product(struct point a, struct point b){
	return (long long)a.x * b.y - (long long)a.y * b.x;
}

int n, m, p[N], s[N], c[N][2];
struct point k[N], null;

void update(int &x){
	s[x] = s[c[x][0]] + 1 + s[c[x][1]];
}

void rotate(int &x, int t){
	int y = c[x][t];
	c[x][t] = c[y][1 - t];
	c[y][1 - t] = x;
	update(x);
	update(y);
	x = y;
}

void insert(int &x, struct point a){
	if(!x){
		x = ++ m;
		k[x] = a;
		p[x] = rand();
	}else{
		int t = cmp(k[x], a) < 0;
		insert(c[x][t], a);
		if(p[c[x][t]] < p[x])
			rotate(x, t);
	}
	update(x);
}

void remove(int &x, struct point a){
	if(cmp(k[x], a) != 0){
		int t = cmp(k[x], a) < 0;
		remove(c[x][t], a);
	}else{
		if(!(c[x][0] + c[x][1])){
			x = 0;
			return;
		}
		rotate(x, p[c[x][0]] > p[c[x][1]]);
		remove(x, a);
	}
	update(x);
}

int count(int &x, struct point a){
	if(!x)
		return 0;
	if(cmp(k[x], a) <= 0)
		return s[c[x][0]] + 1 + count(c[x][1], a);
	return count(c[x][0], a);
}

struct point find(int &x, int r){
	if(!x)
		return null;
	if(r <= s[c[x][0]])
		return find(c[x][0], r);
	if(r <= s[c[x][0]] + 1)
		return k[x];
	return find(c[x][1], r - s[c[x][0]] - 1);
}

int check(struct point a, struct point b, struct point c){
	return product(fromto(a, b), fromto(b, c)) > 0;
}

int is_inside(int &r, struct point z){
	struct point x = find(r, count(r, z));
	if(cmp(x, null) == 0)
		return 0;
	if(cmp(x, z) == 0)
		return 1;
	struct point y = find(r, count(r, z) + 1);
	if(cmp(y, null) == 0)
		return 0;
	return !check(x, z, y);
}

void update_ch(int &r, struct point z){
	insert(r, z);
	while(1){
		int rk = count(r, z);
		if(rk < 3)
			break;
		point x = find(r, rk - 2);
		point y = find(r, rk - 1);
		if(check(x, y, z))
			break;
		remove(r, y);
	}
	while(1){
		int rk = count(r, z);
		if(s[r] - rk + 1 < 3)
			break;
		point x = find(r, rk + 2);
		point y = find(r, rk + 1);
		if(check(z, y, x))
			break;
		remove(r, y);
	}
}

int main(){
	s[0] = 0;
	p[0] = INT_MAX;
	memset(c, 0, sizeof(c));
	null = make_point(INT_MAX, INT_MAX);

	int lch = 0, uch = 0;
	scanf("%d", &n);
	for(int i = 0; i != n; ++ i){
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		if(t == 1){
			if(!is_inside(lch, make_point(x, y)))
				update_ch(lch, make_point(x, y));
			if(!is_inside(uch, make_point(-x, -y)))
				update_ch(uch, make_point(-x, -y));
		}else
			printf(is_inside(lch, make_point(x, y))	&& \
			is_inside(uch, make_point(-x, -y))? "YES\n": "NO\n");
	}
	return 0;
}