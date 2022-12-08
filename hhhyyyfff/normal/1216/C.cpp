#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

//------------------------------------OI----------------------------------------

struct Rec {
	int x1, y1, x2, y2;
	
	Rec() { scanf("%d%d%d%d", &x1, &y1, &x2, &y2); }
	Rec(int _x1, int _y1, int _x2, int _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
	Rec cross(Rec x) { return Rec(max(x.x1, x1), max(x.y1, y1), min(x.x2, x2), min(x.y2, y2)); }
	long long S() { return x1 < x2 && y1 < y2 ? (long long)(x2 - x1) * (y2 - y1) : 0; }
};
Rec wht, bl1, bl2;

int main() {
	puts(wht.cross(bl1).S() + wht.cross(bl2).S() - wht.cross(bl1).cross(bl2).S() < wht.S() ? "YES" : "NO");
	return 0;
}