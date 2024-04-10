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

const int size = 1000;
int way[size][size];
int n, d;
int x[size], y[size];
int a[size];

int main() {
	//freopen("problem_b.in", "r", stdin);
	//freopen("problem_b.out", "w", stdout);
	
	cin >> n >> d;
	for (int i = 0; i < n - 2; i++)
		cin >> a[i + 1];
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			way[i][j] = max(0, (abs(x[i] - x[j]) + abs(y[i] - y[j])) * d - a[j]);
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				way[i][j] = min(way[i][j], way[i][k] + way[k][j]);

	cout << way[0][n - 1] << endl;
	

	return 0;
}