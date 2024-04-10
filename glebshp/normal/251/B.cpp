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
const int size = 200;

int n, k;
int pet[size], back[size], mash[size], tmp[size];
bool forsteps[size];
bool backsteps[size];

bool comp() {
	for (int i = 0; i < n; i++)
		if (mash[i] != tmp[i])
			return false;

	return true;
}

void movefor() {
	int h[size];

	for (int i = 0; i < n; i++)
		h[pet[i]] = tmp[i];

	for (int i = 0; i < n; i++)
		tmp[i] = h[i];
}

void moveback() {
	int h[size];

	for (int i = 0; i < n; i++)
		h[back[i]] = tmp[i];

	for (int i = 0; i < n; i++)
		tmp[i] = h[i];
}

void finish_yes() {
	cout << "YES" << endl;

	exit(0);
}

void finish_no() {
	cout << "NO" << endl;

	exit(0);
}

int main() {
	//freopen("problem_b.in", "r", stdin);
	//freopen("problem_b.out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> pet[i];
		pet[i]--;
		back[pet[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> mash[i];
		mash[i]--;
	}

	for (int i = 0; i < n; i++)
		tmp[i] = i;

	if (comp())
		finish_no();

	for (int i = 0; i < k; i++) {
		movefor();
		forsteps[i] = comp();
	}

	for (int i = 0; i < n; i++)
		tmp[i] = i;

	for (int i = 0; i < k; i++) {
		moveback();
		backsteps[i] = comp();
	}

	if (forsteps[0] && (k == 1 || (!backsteps[0] && k % 2 == 1)))
		finish_yes();

	if (backsteps[0] && (k == 1 || (!forsteps[0] && k % 2 == 1)))
		finish_yes();

	if (!forsteps[0]) {
		for (int i = 1; i < k; i++) {
			if (forsteps[i]) {
				if ((i + 1) % 2 == k % 2)
					finish_yes();

				break;
			}
		}
	}

	if (!backsteps[0]) {
		for (int i = 1; i < k; i++) {
			if (backsteps[i]) {
				if ((i + 1) % 2 == k % 2)
					finish_yes();

				break;
			}
		}
	}

	finish_no();

	return 0;
}