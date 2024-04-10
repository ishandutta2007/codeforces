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


using namespace std;


int n, k;
long long c[200000];
long long d[200000];
int a, b;


int main(){
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		d[i] = (i > 0 ? d[i - 1]: 0);
		d[i] += c[i];
	}
	int j = n - k;
	for (int i = n - 2 * k; i >= 0; i--) {
		if (d[i + 2 * k - 1] - d[i + k - 1] >= d[j + k - 1] - d[j - 1]) {
			j = i + k;
		}
		if (a == 0 && b == 0) {
			a = i;
			b = j;
		} else {
			if (d[i + k - 1] - (i > 0 ? d[i - 1]: 0) + d[j + k - 1] - d[j - 1] >= d[a + k - 1] - (a > 0 ? d[a - 1]: 0) + d[b + k - 1] - d[b - 1]) {
				a = i;
				b = j;
			}
		}
	}
	cout << a + 1 << ' ' << b + 1 << endl;
    return 0;
}