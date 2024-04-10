#include <iostream>
#include <algorithm>
#define int long long

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int extgcd(int a, int b, int& x, int& y)
{
	if (a == 0) { x = 0; y = 1; return b; }
	int x1, y1;
	int d = extgcd(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

bool eq_solve(int a, int b, int c, int& x0, int& y0, int& g)
{
	g = extgcd(abs(a), abs(b), x0, y0);
	if (c % g != 0) return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0) x0 *= -1;
	if (b < 0) y0 *= -1;
	return true;
}

int div_up(int a, int b)
{
    if (b < 0) a *= -1, b *= -1;
    if (a % b == 0) return a / b;
        else if (a < 0) return a / b;
            else return (a + b - 1) / b;
}

int div_down(int a, int b)
{
    if (b < 0) a *= -1, b *= -1;
    if (a % b == 0) return a / b;
        else if (a > 0) return a / b;
            else return (a - b + 1) / b;
}

int calc(int a1, int b1, int a2, int b2, int L, int R)
{
    L = max(L, max(b1, b2));
    if (L > R) return 0;
    int a = a1, b = -a2, c = b2 - b1, x0, y0, g;
    if (!eq_solve(a, b, c, x0, y0, g)) return 0;
    int mul = a2 * g;
    x0 -= (x0 / mul) * mul;
    int beg = a1 * x0 + b1, inc = lcm(a1, a2);
    int min_K = div_up(L - beg, inc),
        max_K = div_down(R - beg, inc);
    return max_K - min_K + 1;
}

main()
{
    int a1, a2, b1, b2, L, R;
    cin >> a1 >> b1 >> a2 >> b2 >> L >> R;
    cout << calc(a1, b1, a2, b2, L, R) << endl;
}