#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>


using namespace std;


int n;
int a, b;


int main() {
	cin >> n >> a >> b;
	if (n == 1 && (a + b >= 1)) {
		cout << -1 << endl;
		return 0;
	} 
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	if (n == a + 1 && b == 0) {
		cout << -1 << endl;
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < min(n - a - b, 1); i++) {
		cout << 1 << ' ';
		sum++;
	}
	int g = 1;
 	for (int i = 0; i < b; i++) {
 		cout << sum + 1 << ' ';
 		g = sum + 1;
 		sum += sum + 1;
 	}
 	for (int i = 0; i < max(n - a - b - 1, 0); i++) {
 		cout << 1 << ' ';
 	}
 	for (int i = 0; i < a; i++) {
 		g++;
 		cout << g << ' ';
 	}
 	cout << endl;
    return 0;
}