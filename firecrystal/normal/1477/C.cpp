// Skyqwq
#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>

#define double long double
#define x first
#define y second
using namespace std;

typedef long long LL;

const int N = 5005;

const double eps = 1e-5;

typedef pair<double, double> Point;

double PI = acos(-1);
double t = PI / 2;

double dot(Point a, Point b){
   return a.x * b.x + a.y * b.y;
}

double get_length(Point a){
    return sqrt(dot(a, a));
}

Point dec(Point a, Point b) {
	return make_pair(a.x - b.x, a.y - b.y);
}

double get_angle(Point a, Point b) {
    return acos(dot(a, b) / get_length(a) / get_length(b));
}

int n, p[N];

Point a[N];

double inline get(int i, int j, int k) {
	return get_angle(dec(a[i], a[j]), dec(a[k], a[j]));
}

int cmp(double x, double y)  // 
{
    if (fabs(x - y) < eps) return 0;
    if (x < y) return -1;
    return 1;
}

bool vis[N];

double inline d(int i, int j) {
	return get_length(dec(a[i], a[j]));
}

int main() {
	srand(time(0));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].y;
	int u = 1, b = -1;
	p[1] = 1;
	vis[1] = true;
	bool ok = true;
	double re = 0;
	for (int i = 2; i <= n; i++)
		if (b == -1 || d(1, i) > re) re = d(1, i), b = i;
	vis[b] = true;
	for (int i = 3; i <= n; i++) {
		int c = -1;
		for (int j = 1; j <= n; j++) {
			if (!vis[j]) {
				if ( (c == -1 || d(b, j) > d(b, c))) {
					c = j;
				}
			}
		}
		if (c == -1) {
			ok = false;
			break;
		}
		vis[c] = true;
		p[i - 1] = b;
		u = b, b = c;
	}
	p[n] = b;
	if (!ok) puts("-1");
	else for (int i = 1; i <= n; i++) printf("%d ", p[i]);
	return 0;
}