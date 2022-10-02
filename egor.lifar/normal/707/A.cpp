#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>


using namespace std;


int n, m;


int main() {
	cin >> n >> m;
	bool b = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			string c;
			cin >> c;
			if (c != "W" && c != "G" && c != "B") {
				b = 0;
			}
		}
	}
	if (b) {
		cout << "#Black&White" << endl;
	} else {
		cout << "#Color" << endl;
	}
    return 0;
}