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

const int size = 1000 * 200;

int num[size];

int main() {
	int a, b, m, r;

	//freopen("problem_b.in", "r", stdin);
	//freopen("problem_b.out", "w", stdout);
	
	cin >> a >> b >> m >> r;
	for (int i = 0; i < m; i++)
		num[i] = -1;
	int mv = 0;
	while (num[r] == -1)
	{
		num[r] = mv++;
		r = (a * r + b) % m;
	}
	cout << mv - num[r] << endl;

	return 0;
}