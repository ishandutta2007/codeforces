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


int n;
int t[100000];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &t[i]);
	}
	int a = 0;
	int b = 0;
	int l = 0;
	int r = n - 1;
	int sum = 0;
	int sum1 = 0;
	while (l <= r) {	
		if (l == r) {
			if (sum <= sum1) {
				a++;
				break;
			}
			b++;
			break;
		}
		if (sum + t[l] < sum1 + t[r]) {
			sum += t[l];
			l++;
			a++;
		} else {
			if (sum + t[l] == sum1 + t[r]) {
				sum += t[l];
				sum1 += t[r];
				l++;
				a++;
				b++;
				r--;
			} else {
				sum1 += t[r];
				b++;
				r--;
			}
		}
	}
	cout << a << ' ' << b << endl;
	return 0;
}