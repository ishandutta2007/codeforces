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
const long long mdl = 1000 * 1000 * 1000 + 7;

int main() {
	string st1, st2;
	int k;
	/*
	freopen("problem_b.in", "w", stdout);
	for (int i = 0; i < 1000; i++)
		cout << 'a';
	cout << endl;
	for (int i = 0; i < 1000; i++)
		cout << 'a';
	cout << endl;
	cout << 100000 << endl;
	return 0;
	*/

	//freopen("problem_b.in", "r", stdin);
	//freopen("problem_b.out", "w", stdout);
	
	cin >> st1 >> st2 >> k;
	int n = st1.length();
	
	long long one = 1, other = 0, none, nother;
	for (int i = 0; i < k; i++)
	{
		none = other * (n - 1) % mdl;
		nother = (one + other * (n - 2)) % mdl;
		one = none;
		other = nother;
	}
	long long ans = 0;
	if (st1 == st2)
		ans = ans + one;
	for (int i = 0; i < n - 1; i++)
	{
		st2 = st2 + st2[0];
		st2.erase(st2.begin());
		if (st1 == st2)
			ans = ans + other;
	}
	cout << ans % mdl << endl;

	return 0;
}