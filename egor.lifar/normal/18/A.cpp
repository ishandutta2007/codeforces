#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set> 


using namespace std;


int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


bool proverka(int ax, int ay, int bx, int by, int cx, int cy) {
	return (ax == bx && ay == by) || (ax == cx && ay == cy) || (bx == cx && bx == cy);
}


bool pryamoy(int ax, int ay, int bx, int by, int cx, int cy) {
	if (proverka(ax, ay, bx, by, cx, cy)) {
		return false;
	}
	int x1, y1, x2, y2;
	x1 = ax - bx;
	y1 = ay - by;
	x2 = cx - bx;
	y2 = cy - by;
	return (x1 * x2 + y1 * y2 == 0);
}


int main(){
	int ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	if (pryamoy(ax, ay, bx, by, cx, cy) || pryamoy(bx, by, ax, ay, cx, cy) || pryamoy(ax, ay, cx, cy, bx, by)) {
		cout << "RIGHT" << endl;
		return 0;
	}
	for (int i = 0; i < 4; i++) {
		if (pryamoy(ax + dx[i], ay + dy[i], bx, by, cx, cy) || pryamoy(bx, by, ax + dx[i], ay + dy[i], cx, cy) || pryamoy(ax + dx[i], ay + dy[i], cx, cy, bx, by)) {
			cout << "ALMOST" << endl;
			return 0;
		}
		if (pryamoy(ax, ay, bx + dx[i], by + dy[i], cx, cy) || pryamoy(bx + dx[i], by + dy[i], ax, ay, cx, cy) || pryamoy(ax, ay, cx, cy, bx + dx[i], by + dy[i])) {
			cout << "ALMOST" << endl;
			return 0;
		}
		if (pryamoy(ax, ay, bx, by, cx + dx[i], cy + dy[i]) || pryamoy(bx, by, ax, ay, cx + dx[i], cy + dy[i]) || pryamoy(ax, ay, cx + dx[i], cy + dy[i], bx, by)) {
			cout << "ALMOST" << endl;
			return 0;
		}
	}
	cout << "NEITHER" << endl;
	return 0;
}