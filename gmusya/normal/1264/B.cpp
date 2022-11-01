#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a0, a1, a2, a3;
bool tf = false;

void var1(int a, int b, int c, int d) {
	a -= b;
	b -= b;
	if (a < 0)
		return;
	if (a > 1)
		return;
	if (a == 1) {
		if (c + d != 0)
			return;
		tf = true;
		cout << "YES" << endl;
		for (int i = 0; i < a1; i++)
			cout << "0 1 ";
		cout << "0";
		return;
	}
	c -= d;
	d -= d;
	if (c < 0)
		return;
	if (c > 1)
		return;
	tf = true;
	cout << "YES" << endl;
	for (int i = 0; i < a1; i++)
		cout << "0 1 ";
	for (int i = 0; i < a3; i++)
		cout << "2 3 ";
	if (c > 0)
		cout << "2";
}

void var2(int a, int b, int c, int d) {
	b -= a;
	a -= a;
	if (b == 0) {
		if (c + d == 0) {
			tf = true;
			cout << "YES" << endl;
			for (int i = 0; i < a0; i++)
				cout << "1 0 ";
			if (b == 1)
				cout << "1";
		}
		return;
	}
	if (b < 0)
		return;
	if (b > c) {
		if (d != 0)
			return;
		if (b > c + 1)
			return;
		tf = true;
		cout << "YES" << endl;
		for (int i = 0; i < a0; i++)
			cout << "1 0 ";
		for (int i = 0; i < a2; i++)
			cout << "1 2 ";
		if (b - c == 1)
			cout << "1";
	}
	c -= b;
	b -= b;
	if (c < 0)
		return;
	d -= c;
	c -= c;
	if (d < 0)
		return;
	if (d > 1)
		return;
	cout << "YES" << endl;
	tf = true;
	for (int i = 0; i < a0; i++)
		cout << "1 0 ";
	for (int i = 0; i < a1 - a0; i++)
		cout << "1 2 ";
	for (int i = 0; i < a2 - (a1 - a0); i++)
		cout << "3 2 ";
	if (d > 0)
		cout << "3";
}

void var3(int d, int c, int b, int a) {
	b -= a;
	a -= a;
	if (b == 0) {
		if (c + d == 0) {
			tf = true;
			cout << "YES" << endl;
			for (int i = 0; i < a3; i++)
				cout << "2 3 ";
			if (b == 1)
				cout << "2";
		}
		return;
	}
	if (b < 0)
		return;
	if (b > c) {
		if (d != 0)
			return;
		if (b > c + 1)
			return;
		tf = true;
		cout << "YES" << endl;
		for (int i = 0; i < a3; i++)
			cout << "2 3 ";
		for (int i = 0; i < a1; i++)
			cout << "2 1 ";
		if (b - c == 1)
			cout << "2";
	}
	c -= b;
	b -= b;
	if (c < 0)
		return;
	d -= c;
	c -= c;
	if (d < 0)
		return;
	if (d > 1)
		return;
	cout << "YES" << endl;
	tf = true;
	for (int i = 0; i < a3; i++)
		cout << "2 3 ";
	for (int i = 0; i < a2 - a3; i++)
		cout << "2 1 ";
	for (int i = 0; i < a1 - (a2 - a3); i++)
		cout << "0 1 ";
	if (d > 0)
		cout << "0";
}

void var4(int d, int c, int b, int a) {
	a -= b;
	b -= b;
	if (a < 0)
		return;
	if (a > 1)
		return;
	if (a == 1) {
		if (c + d != 0)
			return;
		tf = true;
		cout << "YES" << endl;
		for (int i = 0; i < a2; i++)
			cout << "3 2 ";
		cout << "3";
		return;
	}
	c -= d;
	d -= d;
	if (c < 0)
		return;
	if (c > 1)
		return;
	tf = true;
	cout << "YES" << endl;
	for (int i = 0; i < a2; i++)
		cout << "3 2 ";
	for (int i = 0; i < a0; i++)
		cout << "1 0 ";
	if (c > 0)
		cout << "1";
}

int main() {
	cin >> a0 >> a1 >> a2 >> a3;
	var1(a0, a1, a2, a3);
	if (tf)
		return 0;
	var2(a0, a1, a2, a3);
	if (tf)
		return 0;
	var3(a0, a1, a2, a3);
	if (tf)
		return 0;
	var4(a0, a1, a2, a3);
	if (tf)
		return 0;
	cout << "NO";
	return 0;
}