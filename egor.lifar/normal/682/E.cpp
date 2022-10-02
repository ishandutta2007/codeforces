#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <cstdio>
#include <cstring>	
#include <ctime>
#include <stack>
#include <deque>
#include <cassert>
#include <cstdlib>
#include <set>
#include <map>
#include <list>


using namespace std;


struct point{
	long long x, y;
};


bool operator <(point A, point B) {
	return make_pair(A.x, A.y) < make_pair(B.x, B.y);
}


bool operator ==(point A, point B) {
	return make_pair(A.x, A.y) == make_pair(B.x, B.y);
}


struct Vector {
	long long x, y;
	Vector(point a, point b) {
		x = b.x - a.x;
		y = b.y - a.y;
	}
};


Vector neg(Vector x) {
	x.x = -x.x;
	x.y = -x.y;
	return x;
}


point add(point p, Vector a) {
	p.x += a.x;
	p.y += a.y;
	return p;
}


long long operator ^(Vector a, Vector b) {
	return abs(a.x * b.y - a.y * b.x);
}


vector<point> p;


long long res(int x, int y, int z) {
	return Vector(p[x], p[y]) ^ Vector(p[x], p[z]);
}


int n;
long long s;


int main() {
	scanf("%d %I64d", &n, &s);
	p = vector<point>(n);
	for (int i = 0; i < n; i++) {
		scanf("%I64d %I64d", &p[i].x, &p[i].y);
	}
	sort(p.begin(), p.end());
	p.resize(unique(p.begin(), p.end()) - p.begin());
	if ((int)p.size() < 3) {
		while ((int)p.size() < 3) {
			p.push_back(p[0]);
		}
		for (int i = 0; i < 3; i++) {
			printf("%I64d %I64d\n", p[i].x, p[i].y);
		}
		return 0;
	}
	random_shuffle(p.begin(), p.end());
	int a = 0, b = 1, c = 2;
	while (1) {
		bool better = false;
		for (int i = 0; i < n; i++) {
			if (res(a, b, c) < res(a, b, i)) {
				better = true;
				c = i;
			}
			if (res(a, b, c) < res(a, i, c)) {
				better = true;
				b = i;
			}
			if (res(a, b, c) < res(i, b, c)) {
				better = true;
				a = i;
			}
		}
		if (!better) {
			break;
		}
	}
	point r1, r2, r3;
	r1 = add(p[a], Vector(p[b], p[c]));
	r2 = add(p[a], neg(Vector(p[b], p[c])));
	r3 = add(p[b], Vector(p[a], p[c]));
	printf("%I64d %I64d\n", r1.x, r1.y);
	printf("%I64d %I64d\n", r2.x, r2.y);
	printf("%I64d %I64d\n", r3.x, r3.y);
	return 0;
}