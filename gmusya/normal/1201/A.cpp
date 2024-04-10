#include <iostream>
#include <vector>

using namespace std;

struct answers {
	int a;
	int b;
	int c;
	int d;
	int e;
};

int max(int a, int b, int c, int d, int e) {
	int k = a;
	if (k < b) k = b;
	if (k < c) k = c;
	if (k < d) k = d;
	if (k < e) k = e;
	return k;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector <answers> a(m);
	for (int j = 0; j < m; j++) {
		a[j].a = 0;
		a[j].b = 0;
		a[j].c = 0;
		a[j].d = 0;
		a[j].e = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == 'A') a[j].a++;
			if (c == 'B') a[j].b++;
			if (c == 'C') a[j].c++;
			if (c == 'D') a[j].d++;
			if (c == 'E') a[j].e++;
		}
	}
	vector <int> points(m);
	for (int i = 0; i < m; i++) cin >> points[i];
	int ma = 0;
	for (int i = 0; i < m; i++) {
		int num;
		num = max(a[i].a, a[i].b, a[i].c, a[i].d, a[i].e) * points[i];
		ma += num;
	}
	cout << ma;
	return 0;
}