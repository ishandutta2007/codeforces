#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>


using namespace std;


int n;



int main() {
	cin >> n;
	int a = 1234567;
	int b = 123456;
	int c = 1234;
	for (int i = 0; i <= n / a; i++) {
		for (int j = 0; j <= (n - i * a) / b; j++) {
			int ans = n - i * a - j * b;
			if (ans % c == 0) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
    return 0;
}