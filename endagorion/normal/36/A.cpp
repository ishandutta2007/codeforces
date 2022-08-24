#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;


fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

int main() {
	fout.precision(10);
	fout << fixed;

	int prev = -1, per = -1;
	int N;
	string s;
	bool ok = true;
	fin >> N >> s;
	for (int i = 0; i < N; ++i) {
		if (s[i] == '1') {
			if (prev != -1) {
				if (per != -1) {
					if (i - prev != per) {
						ok = false;
					}
				}
				per = i - prev;
			}
			prev = i;
		} 
	}

	if (ok) {
		fout << "YES\n";
	} else {
		fout << "NO\n";
	}

	return 0;
}