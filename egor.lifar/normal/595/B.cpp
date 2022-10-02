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
#include <vector>


using namespace std;


#define M 1000000007


int n, k;
int a[100101];
int b[100101];


int main() {
	cin >> n >> k;
	for (int i = 0; i < n / k; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n / k; i++) {
		scanf("%d", &b[i]);
	}
	int ans = 1;
	for (int i = 0; i < n / k; i++) {
		int s = ((int)round(pow(10.0, 1.0 * k)) - 1) / a[i] + 1;
		//cout << pow(10.0, 1.0 * k) - 1 << endl;
		//cout << s << endl;
			int g = (1LL * (int)round(pow(10.0, k - 1)) * b[i]) % (1LL * a[i]);
			//cout << g << endl;
			if ((int)round(pow(10, k - 1)) - 1 >= (a[i] - g) % a[i]) { 
				s -= 1 + max(0, ((int)round(pow(10.0, k - 1)) - 1 - (a[i] - g) % a[i]) / a[i]);
			}
		//	cout << max(0, ((int)round(pow(10.0, k - j - 1)) - 1 - (a[i] - g) % a[i]) / a[i]) << endl;
		//cout << s << endl;
		ans = (1LL * ans * s) % M;
	}
	cout << ans << endl;
	return 0;
}