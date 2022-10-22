#include <iostream>
#include <algorithm>

using namespace std;

int a[50], i, j;
char op[20];

long long s;

long long calc(long long a, long long b, char op) {
	if (op == '+')
		return a + b;
	return a * b;
}

long long rez(long long a, long long b = -1, long long c = -1, long long d= -1) {
    if (d != -1)
    	return min( min (min (rez(a, b, calc(c, d, op[1])), rez(a, c, calc(b, d, op[1]))), 
						 min (rez(a, d, calc(b, c, op[1])), rez(b, c, calc(a, d, op[1])))),
					min (rez(b, d, calc(a, c, op[1])), rez(c, d, calc(a, b, op[1]))));

	if (c != -1)
		return min( min (rez(a, calc(b, c, op[2])), rez(b, calc(a, c, op[2]))), rez(c, calc(a, b, op[2])));
	if (b != -1)
		return calc(a, b, op[3]);
}
						
int main() {
	cin >> a[1] >> a[2] >> a[3] >> a[4];
	cin >> op[1] >> op[2] >> op[3];
	cout << rez(a[1], a[2], a[3], a[4]) << "\n";
}