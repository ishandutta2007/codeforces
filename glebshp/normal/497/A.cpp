#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
#include <deque>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define taskname "task_a"

const double pi = acos(-1.0);
const int size = 2000;

char field[size][size];
bool good[size];
int n, m;

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%d", &n, &m);

	int cnt = 0;

	for (int i = 0; i < n; i++)
		scanf("%s", field[i]);
	for (int i = 0; i < n; i++)
		good[i] = false;
	for (int i = 0; i < m; i++) {
		bool flag = true;
		for (int j = 0; j < n - 1; j++) {
			if (good[j])
				continue;
			if (field[j][i] > field[j + 1][i])
				flag = false;
		}

		if (flag) {
			for (int j = 0; j < n - 1; j++)
				if (field[j][i] < field[j + 1][i])
					good[j] = true;
		} else {
			cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}