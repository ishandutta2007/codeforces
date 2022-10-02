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
#include <unordered_map>


using namespace std;


int n;
string a, b;
double c[666];


int main() {
	cin >> n >> a >> b;
	double sum = 0;
	for (int i = 0; i < n; i++) {
		c[(int)b[i]]+= 1LL * (i + 1); 
		sum += 1LL * (n - i) * c[(int)a[i]];
	}
	//cout << sum << endl;
	for (int i = 0; i < 666; i++) {
		c[i] = 0LL;
	}
	for (int i = n - 1; i >= 0; i--) {
		sum += 1LL * (i + 1) * c[(int)a[i]];
		c[(int)b[i]]+= 1LL * (n - i); 
	}
//	cout << sum - 4 << endl;
	double sum1 = 0;
	for (int i = 1; i <= n; i++) {
		sum1 += 1LL * (n - i + 1) * (n - i + 1);
	}
	//cout << sum1 << endl;
	printf("%.11lf\n", sum / sum1);
    return 0;
}