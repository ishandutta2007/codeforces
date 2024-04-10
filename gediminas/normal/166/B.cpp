/*input
4
-10 -10
-10 10
10 10
10 -10
3
0 -10
1 5
2 2
*/
#include <bits/stdc++.h>

using namespace std;

struct Point {
	long long x, y;
	Point(const long long &x, const long long &y): x(x), y(y) {}
	Point() {}
	long long distanceSq(const Point &p) {
		return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
	}
	bool operator!=(const Point &p) {
		return x != p.x or y != p.y;
	}
};
struct Line {
	Point a, b;
	Line(const Point &a, const Point &b);
	bool doIntersect(const Line &o) const;
};
struct Vector2 {
	long long x, y;
	Vector2(const Point &A, const Point &B) {
		x = B.x - A.x;
		y = B.y - A.y;
	}
	Vector2(const long long &x, const long long &y): x(x), y(y) {}
	Vector2(const Line &l) {
		x = l.b.x - l.a.x;
		y = l.b.y - l.a.y;
	}
	long long product(const Vector2 &b) const {
		return x * b.y - y * b.x;
	}
	Vector2 operator+(const Vector2 &a) const {
		return Vector2(x + a.x, y + a.y);
	}
	Vector2 operator-(const Vector2 &a) const {
		return Vector2(x - a.x, y - a.y);
	}
	long double operator*(const Vector2 &a)const {
		return x * a.x + y * a.y;
	}
	Vector2 operator*(const long double &a)const {
		return Vector2(a * x, a * y);
	}
	long double abs() const {
		return sqrt(x * x + y * y);
	}
	long long absSq() const {
		return x * x + y * y;
	}
};
Line::Line(const Point &a, const Point &b): a(a), b(b) {}
bool Line::doIntersect(const Line &o) const {
	long long x_up = Vector2(a, o.a).product(Vector2(o.a, o.b));
	long long x_down = Vector2(a, b).product(Vector2(o.a, o.b));
	long long y_up = Vector2(a, b).product(Vector2(a, o.a));
	long long y_down = Vector2(o.a, o.b).product(Vector2(a, b));

	if (x_up == 0 or y_up == 0)
		return false;

	if (((x_up > 0) xor (x_down > 0)) or ((y_up > 0) xor (y_down > 0)))
		return false;

	x_up = llabs(x_up), x_down = llabs(x_down), y_up = llabs(y_up), y_down = llabs(y_down);
	return x_up < x_down and y_up < y_down;
}

template<class T>
T secondElement(stack<T> &s) {
	int first = s.top();
	s.pop();
	int second = s.top();
	s.push(first);
	return second;
}

// 0 - vienoje tiesje, 1 - pagal, 2 - prie laikrodio rodykl
int orientation(const Point &a, const Point &b, const Point &c) {
	long long temp = Vector2(a, b).product(Vector2(b, c));

	if (temp == 0)
		return 0;

	return temp > 0 ? 2 : 1;
}

vector<Point> A;

bool compare(const Point &p1, const Point &p2) {
	int o = orientation(A[0], p1, p2);

	if (o == 0)
		return A[0].distanceSq(p2) >= A[0].distanceSq(p1);

	return o == 1;
}

int main () {
	int n;
	cin >> n;
	A = vector<Point>(n);

	for (Point &p : A)
		cin >> p.x >> p.y;

	int miny = 0;

	for (unsigned i = 1; i < A.size(); i++) {
		if (A[i].y < A[miny].y or
				(A[i].y == A[miny].y and A[i].x < A[miny].x))
			miny = i;
	}

	swap(A[0], A[miny]);

	sort(A.begin() + 1 , A.end(), compare);

	cin >> n;
	bool ar = true;

	while (n--) {
		Point p;
		cin >> p.x >> p.y;
		int mi = 0, ma = A.size() - 1;

		while (mi < ma) {
			int vid = (mi + ma + 1 ) / 2;

			if (compare(A[vid], p))
				mi = vid;
			else
				ma = vid - 1;
		}

		ar = ar and (orientation(A[mi], A[(mi + 1) % A.size()],  p) == 1)
			 and A[(mi + 1) % A.size()] != p and A[mi] != p and p.y > A[0].y;
	}

	cout << (ar ? "YES" : "NO");

	return 0;
}