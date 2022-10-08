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

const int size = 21 * 1000 * 1000;
int mx[size];

int main() {
	int a, n;

	//freopen("problem_d.in", "r", stdin);
	//freopen("problem_d.out", "w", stdout);
	
	cin >> a >> n;
	for (int i = 1; i <= (a + n); i++)
		mx[i] = 1;
	for (int i = 2; i * i <= (a + n); i++)
	{
		int mult = i * i;
		for (int j = 1; j * mult <= (a + n); j++)
			mx[j * mult] = mult;
	}
	long long sum = 0;
	for (int i = a; i < a + n; i++)
		sum += i / mx[i];
	cout << sum << endl;

	return 0;
}