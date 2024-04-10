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
pair<int, int> p[100000];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].second >> p[i].first;
	}
	sort(p, p + n);
	int s = p[0].second;
	for (int i = 1; i < n; i++) {
		if (p[i].second < s) {
			cout << "Happy Alex" << endl;
			return 0;
		}
		s = max(s, p[i].second);
	}
	cout << "Poor Alex" << endl;
	return 0;
}