#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <algorithm>

#define fsp fixed << setprecision(9)

typedef double long dl;

using namespace std;

struct vec {
	dl x, y;
	void read() {
		cin >> x >> y;
	}
};

int main() {
	vec o1, o2;
	dl r1, r2;
	o1.read();
	cin >> r1;
	o2.read();
	cin >> r2;
	if (r1 > r2) {
		swap(o1, o2);
		swap(r1, r2);
	}
	dl mod = sqrt((o1.x - o2.x) * (o1.x - o2.x) + (o1.y - o2.y) * (o1.y - o2.y));;
	if (mod - (r1 + r2) > 0) {
		mod -= r1 + r2;
		cout << fsp << mod / 2;
		return 0;
	}
	mod = r2 - (mod + r1);
	mod /= 2;
	cout << fsp << max((dl) 0, mod);
	return 0;
}