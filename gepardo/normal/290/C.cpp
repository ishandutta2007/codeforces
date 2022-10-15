#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;


int main()
{
	long double tux; cin >> tux;
	long double foo = 0, bar = 0, baz = 0, quz = 1;
	for (; tux != 0; tux--)
	{
		int pur; cin >> pur;
		foo += pur;
		bar++;
		if (max(foo * quz, bar * baz) == (foo * quz))
			baz = foo, quz = bar;
	}
	cout << setprecision(10) << baz / quz;
}