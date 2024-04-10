#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <cstdlib>

typedef long long lint;

using namespace std;

lint gcd(lint a, lint b)
{
	if (a == 0)
		return b;
	return gcd(b%a, a);
}

struct fraction {
	lint up, down;
	fraction(lint _up, lint _down) {
		up = _up, down = _down;
		lint g = gcd(up, down);
		up /= g, down /= g;
	}
	int operator < (const fraction& o) const {
		/* Both are always positive fractions */
		return up*o.down < down*o.up;
	}
};

map <fraction, lint> left2, right2;

int rev(int x)
{
	int ret = 0;
	while (x) {
		ret = 10*ret + (x%10);
		x /= 10;
	}
	return ret;
}

int main()
{
	int maxx, maxy, minlucky;

	scanf("%d %d %d", &maxx, &maxy, &minlucky);
	
	int retx = -1, rety = -1;
	lint minarea = 100001LL*100001LL;

	for (int y = 1; y <= maxy; y++)
		right2[fraction(rev(y), y)] ++;

	lint lucky = 0;
	for (int x = 1; x <= maxx; x++) {
		fraction f = fraction(x, rev(x));
		lucky += right2[f];
		left2[f] ++;
		while (lucky - left2[fraction(rev(maxy), maxy)] >= (lint)minlucky) {
			lucky -= left2[fraction(rev(maxy), maxy)];
			right2[fraction(rev(maxy), maxy)] --;
			maxy --;
		}
		if (lucky >= (lint)minlucky && (lint)x * (lint)maxy < minarea) {
			minarea = (lint)x * (lint)maxy;
			retx = x, rety = maxy;
		}
	}

	if (retx == -1)
		printf("-1\n");
	else
		printf("%d %d\n", retx, rety);

	return 0;
}