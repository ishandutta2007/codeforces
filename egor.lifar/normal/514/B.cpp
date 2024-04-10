#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>


using namespace std;


struct point{
	int x, y;
	point(){}
	point(int _x, int _y) {
		x = _x;
		y = _y;
	}
};

int n;
point t;
point p[100000];
bool used[100000];


int vec(point a, point b) {
	return a.x * b.y - a.y * b.x;
}


int main() {
	cin >> n >> t.x >> t.y;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			ans++;
			for (int j = 0; j < n; j++) {
				if (vec(point(p[j].x - t.x, p[j].y - t.y), point(p[i].x - t.x, p[i].y - t.y)) == 0) {
					used[j] = true;
				} 
			}
		}
	}
	cout << ans << endl;
    return 0;
}