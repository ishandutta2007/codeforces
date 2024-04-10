#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>

#define ll long long
#define dl double long
#define eps 1e-12
#define fsp fixed << setprecision(12)

using namespace std;

struct point {
	dl x, y;
};

int main() {
	point A, B;
	dl R, r;
	cin >> R >> A.x >> A.y >> B.x >> B.y;
	if ((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y) + eps >= R*R) {
		cout << fsp << A.x << " " << A.y << " " << R;
		return 0;
	}
	if (abs(A.x - B.x) < eps && abs(A.y - B.y) < eps) {
		cout << fsp << A.x << " " << A.y + (R / 2) << " " << R / 2;
		return 0;
	}
	r = (R + sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y))) / 2;
	dl lef = 1e-5;
	dl rig = 1e5;
	while (abs(lef - rig) > eps) {
		dl m = (lef + rig) / 2;
		dl temp_x = (A.x - B.x) * m;
		dl temp_y = (A.y - B.y) * m;
		if (temp_x * temp_x + temp_y * temp_y > r*r)
			rig = m;
		else
			lef = m;
	}
	cout << fsp << B.x + (A.x - B.x) * lef << " " << B.y + (A.y - B.y) * lef << " " << r;
	return 0;
}