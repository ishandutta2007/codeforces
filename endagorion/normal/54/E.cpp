#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#ifdef ONLINE_JUDGE

#define fin cin
#define fout cout

#else

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

#endif

struct TPoint {
	long long x, y;

	TPoint(long long _x = 0, long long _y = 0)
		: x(_x)
		, y(_y)
	{
	}
};

long long dist2(const TPoint &a, const TPoint &b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
	fout.precision(10);
	fout << fixed;

	int N;
	fin >> N;

	vector<TPoint> points(N);
	for (int i = 0; i < N; ++i) {
		fin >> points[i].x >> points[i].y;
	}

	vector<long double> traps(N);
	traps[0] = 0.0;
	for (int i = 1; i < N; ++i) {
		traps[i] = traps[i - 1] + 0.5 * (points[i].x - points[i - 1].x) * (points[i].y + points[i - 1].y);
	}

	long double S = traps[N - 1] + 0.5 * (points[0].x - points[N - 1].x) * (points[0].y + points[N - 1].y);

	if (S < 0) {
		S = -S;
		for (int i = 0; i < N; ++i) {
			traps[i] = -traps[i];
			points[i].x = -points[i].x;
		}
	}

	int curMin = 0, curMax = 0;
	long long A = points[1].x - points[0].x, B = points[1].y - points[0].y;
	for (int i = 1; i < N; ++i) {
		long long Q = A * points[i].x + B * points[i].y;
		if (Q < A * points[curMin].x + B * points[curMin].y) {
			curMin = i;
		}
		if (Q > A * points[curMax].x + B * points[curMax].y) {
			curMax = i;
		}
	}

	long double ans = 1e15;
	for (int i = 0; i < N; ++i) {
		int ii = (i + 1) % N;
		A = points[ii].x - points[i].x;
		B = points[ii].y - points[i].y;
		while (A * points[(curMin + 1) % N].x + B * points[(curMin + 1) % N].y <= A * points[curMin].x + B * points[curMin].y) {
			curMin = (curMin + 1) % N;
		}

		while (A * points[(curMax + 1) % N].x + B * points[(curMax + 1) % N].y >= A * points[curMax].x + B * points[curMax].y) {
			curMax = (curMax + 1) % N;
		}
		long long d = A * points[curMax].x + B * points[curMax].y - A * points[ii].x - B * points[ii].y;
		long long D = dist2(points[ii], points[curMax]);
		long double exc = traps[curMax] - traps[ii] - 0.5 * (points[curMax].x - points[ii].x) * (points[curMax].y + points[ii].y);
		while (exc < 0) {
			exc += S;
		}
		ans = min(ans, 0.5 * d * sqrt(1.0 * D * (A * A + B * B) - 1.0 * d * d) / (A * A + B * B) - exc);
		d = -(A * points[curMin].x + B * points[curMin].y - A * points[i].x - B * points[i].y);
		D = dist2(points[i], points[curMin]);
		exc = traps[i] - traps[curMin] - 0.5 * (points[i].x - points[curMin].x) * (points[i].y + points[curMin].y);
		while (exc < 0) {
			exc += S;
		}
		ans = min(ans, 0.5 * d * sqrt(1.0 * D * (A * A + B * B) - 1.0 * d * d) / (A * A + B * B) - exc);
	}

	fout << ans << '\n';

	return 0;
}