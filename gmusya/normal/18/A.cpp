#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct vec {
	int x, y;
	void read() {
		cin >> x >> y;
	}
	bool operator == (vec a) {
		return (x == a.x && y == a.y);
	}
	vec operator - (vec a) {
		return { x - a.x, y - a.y };
	}
	int mod() {
		return x * x + y * y;
	}
};

bool check(vec A, vec B, vec C) {
	if (A == B || A == C || B == C) return false;
	vector <int> s;
	s.push_back((A - B).mod());
	s.push_back((B - C).mod());
	s.push_back((C - A).mod());
	sort(s.begin(), s.end());
	return (s[0] + s[1] == s[2]);
}

int main() {
	vec A, B, C;
	A.read(), B.read(), C.read();
	if (check(A, B, C)) {
		cout << "RIGHT";
		return 0;
	}
	vec D = { A.x, A.y + 1 };
	if (check(D, B, C)) {
		cout << "ALMOST";
		return 0;
	}
	D = { A.x, A.y - 1 };
	if (check(D, B, C)) {
		cout << "ALMOST";
		return 0;
	}
	D = { A.x + 1, A.y };
	if (check(D, B, C)) {
		cout << "ALMOST";
		return 0;
	}
	D = { A.x - 1, A.y };
	if (check(D, B, C)) {
		cout << "ALMOST";
		return 0;
	}
	D = { B.x, B.y + 1 };
	if (check(A, D, C)) {
		cout << "ALMOST";
		return 0;
	}
	D = { B.x, B.y - 1 };
	if (check(A, D, C)) {
		cout << "ALMOST";
		return 0;
	}
	D = { B.x + 1, B.y };
	if (check(A, D, C)) {
		cout << "ALMOST";
		return 0;
	}
	D = { B.x - 1, B.y };
	if (check(A, D, C)) {
		cout << "ALMOST";
		return 0;
	}
	D = { C.x, C.y + 1 };
	if (check(A, B, D)) {
		cout << "ALMOST";
		return 0;
	}
	D = { C.x, C.y - 1 };
	if (check(A, B, D)) {
		cout << "ALMOST";
		return 0;
	}
	D = { C.x + 1, C.y };
	if (check(A, B, D)) {
		cout << "ALMOST";
		return 0;
	}
	D = { C.x - 1, C.y };
	if (check(A, B, D)) {
		cout << "ALMOST";
		return 0;
	}
	cout << "NEITHER";
	return 0;
}