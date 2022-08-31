#include <cstdio>
#include <cstring>

#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	char a, b;
	int n;
	scanf("%c %c%d", &a, &b, &n);
	n %= 4;
	if (n % 2 == 0) {
		puts("undefined");
		return 0;
	}
	bool f = a == '<' && b == '^' ||
	               a == '^' && b == '>' ||
				   a == '>' && b == 'v' ||
				   a == 'v' && b == '<';
	if (n == 1)
		if (f)
			puts("cw");
		else
			puts("ccw");
	else
		if (f)
			puts("ccw");
		else
			puts("cw");
	return 0;
}