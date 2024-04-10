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

map <int, int> grandi;

void calcgrandi(int n, int mask) {
	if (grandi.find(mask) != grandi.end()) {
		return;
	}
	vector <bool> mex(n + 2);
	int nmask;
	for (int i = 0; i < n; i++)
		if (!((mask >> i) & 1)) {
			nmask = mask;
			for (int j = 1; (i + 1) * j <= n; j++) {
				nmask |= (1 << ((i + 1) * j - 1));
			}
			calcgrandi(n, nmask);
			mex[grandi[nmask]] = true;
		}
	int p = 0;
	while (mex[p])
		p++;
	grandi[mask] = p;
	//cerr << grandi[mask] << endl;
}

const int size = 40 * 1000;

set <long long> vals;
bool used[size];
int mygrandi[30];

int main() {
		mygrandi[1] = 1;
	mygrandi[2] = 2;
	mygrandi[3] = 1;
	mygrandi[4] = 4;
	mygrandi[5] = 3;
	mygrandi[6] = 2;
	mygrandi[7] = 1;
	mygrandi[8] = 5;
	mygrandi[9] = 6;
	mygrandi[10] = 2;
	mygrandi[11] = 1;
	mygrandi[12] = 8;
	mygrandi[13] = 7;
	mygrandi[14] = 5;
	mygrandi[15] = 9;
	mygrandi[16] = 8;
	mygrandi[17] = 7;
	mygrandi[18] = 3;
	mygrandi[19] = 4;
	mygrandi[20] = 7;
	mygrandi[21] = 4;
	mygrandi[22] = 2;
	mygrandi[23] = 1;
	mygrandi[24] = 10;
	mygrandi[25] = 9;
	mygrandi[26] = 3;
	mygrandi[27] = 6;
	mygrandi[28] = 11;
	mygrandi[29] = 12;


	int n;

	//freopen("problem_d.in", "r", stdin);
	//freopen("problem_d.out", "w", stdout);
	
	cin >> n;
	used[1] = true;
	int ans = 1;
	for (int i = 2; i < size; i++) {
		if (i > n)
			break;
		if (!used[i]) {
			long long p = i;
			int cc = 0;

			while (p <= n) {
				cc++;
				if (p < size)
					used[p] = true;
				else
					vals.insert(p);
				p *= i;
			}
			ans ^= mygrandi[cc];
		}
	}

	if (n >= size)
		ans ^= (n - size + 1 - vals.size()) % 2;

	if (ans) {
		cout << "Vasya" << endl;
	} else {
		cout << "Petya" << endl;
	}
	//cout << ans << endl;
	/*
	
	for (int i = 1; i <= 29; i++) {
		grandi.clear();
		calcgrandi(i, 0);
		cout << "mygrandi[" << i << "] = " << grandi[0] << ";" << endl;
		cerr << i << endl;
	}
	*/

	return 0;
}