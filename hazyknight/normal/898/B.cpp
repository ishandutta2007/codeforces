#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

void exgcd(long long a,long long b,long long &x,long long &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return;
	}
	exgcd(b,a % b,y,x);
	y -= a / b * x;
}

long long gcd(long long a,long long b)
{
	return b ? gcd(b,a % b) : a;
}

long long a,b,x,y,n;

int main()
{
	cin >> n >> a >> b;
	if (n % gcd(a,b) != 0)
	{
		cout << "NO" << endl;
		return 0;
	}
	exgcd(a,b,x,y);
	x *= n / gcd(a,b);
	y *= n / gcd(a,b);
	bool flag = false;
	if (y < 0)
		swap(x,y),swap(a,b),flag = true;
	if (x < 0)
	{
		long long cnt = (-x % b == 0 ? -x / b : -x / b + 1);
		y -= cnt * a;
		x += cnt * b;
	}
	if (y < 0)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	if (flag)
		cout << y << ' ' << x << endl;
	else
		cout << x << ' ' << y << endl;
	return 0;
}