#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>


using namespace std;


int n;
int d[100011];
bool used[100011];


int main() {
	int curpos = 1;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		scanf("%d", &d[i]);
	}
	while (!used[curpos]) {
		used[curpos] = 1;
		if (s[curpos - 1] == '>') {
			curpos += d[curpos - 1];
		} else {
			curpos -= d[curpos - 1];
		}
		if (curpos > n || curpos < 1) {
			cout << "FINITE" << endl;
			return 0;
		}
	}
	cout << "INFINITE" << endl;
	return 0;
}