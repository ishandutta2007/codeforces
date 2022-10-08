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
const int size = 100 * 1000;

int mas[size];

int main() {
	//freopen("problem_a.in", "r", stdin);
	//freopen("problem_a.out", "w", stdout);
	
	int n;

	cin >> n;
	for (int i = 0; i < 2 * n - 1; i++)
		cin >> mas[i];
	sort(mas, mas + 2 * n - 1);
	int ans = 0;
		
	if (n % 2 == 0) {
		for (int i = 0; i + 1 < 2 * n - 1; i += 2) {
			ans += abs(mas[i] + mas[i + 1]);
		}
		ans += mas[2 * n - 2];
	} else {
		for (int i = 0; i < 2 * n - 1; i++)
			ans += abs(mas[i]);
	}

	cout << ans << endl;

	return 0;
}