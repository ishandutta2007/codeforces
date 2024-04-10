#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


int n;
string a, b;
int k, k1;


int main() {
	cin >> a >> b;
	n = a.size();
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			if (a[i] == '4') {
				k++;
			} else {
				k1++;
			}
		}
	}
	cout << min(k, k1) + abs(k - k1) << endl;
	return 0;
}