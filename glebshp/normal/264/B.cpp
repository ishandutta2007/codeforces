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

int ans[size];

int main() {
	int n;

	//freopen("problem_b.in", "r", stdin);
	//freopen("problem_b.out", "w", stdout);
	
	scanf("%d", &n);
	int num;
	int mans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		if (num == 1) {
			mans = 1;
			continue;
		}
		int h = 0;
		for (int j = 1; j * j <= num; j++) {
			if (num % j == 0) {
				if (j != 1)
					h = max(ans[j], h);
				h = max(ans[num / j], h);
			}
		}
		h++;
		for (int j = 1; j * j <= num; j++) {
			if (num % j == 0) {
				ans[j] = h;
				ans[num / j] = h;
			}
		}
	}

	for (int i = 2; i < size; i++)
		mans = max(mans, ans[i]);

	cout << mans << endl;

	return 0;
}