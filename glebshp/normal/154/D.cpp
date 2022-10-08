#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
const double pi = acos(-1.0);

void end_with_first(long long pa)
{
	cout << "FIRST" << endl;
	cout << pa << endl;
	exit(0);
}

void end_with_second()
{
	cout << "SECOND" << endl;
	exit(0);
}

void end_with_draw()
{
	cout << "DRAW" << endl;
	exit(0);
}

int main() {
	long long ps1, ps2, a, b;

	//freopen("problem_d.in", "r", stdin);
	//freopen("problem_d.out", "w", stdout);
	
	cin >> ps1 >> ps2 >> a >> b;
	if (ps1 + a <= ps2 && ps1 + b >= ps2)
		end_with_first(ps2);
	if (a <= 0 && b >= 0)
		end_with_draw();
	bool flag = false;
	if (ps2 < ps1)
	{
		flag = true;
		swap(ps1, ps2);
		a *= -1;
		b *= -1;
		swap(a, b);
	}
	if (a < 0)
		end_with_draw();
	long long d = ps2 - ps1;
	if (d % (a + b) == 0)
		end_with_second();
	if (d % (a + b) >= a && d % (a + b) <= b)
	{
		long long hd = (d / (a + b)) * (a + b);
		if (!flag)
			end_with_first(ps2 - hd);
		else
			end_with_first(ps1 + hd);
	}
	end_with_draw();

	return 0;
}