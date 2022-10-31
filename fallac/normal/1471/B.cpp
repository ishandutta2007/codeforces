#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
#define MAX 1010101
lld arr1[MAX], arr2[MAX];
int main(void) {
	lld T;
	cin >> T;
	while (T-- > 0) {
		lld N, x;
		cin >> N >> x;
		lld i;
		lld sum = 0;
		for (i = 0; i < N; i++) {
			cin >> arr1[i];
			arr2[i] = arr1[i];
			sum += arr1[i];
		}
		bool c = false;
		while (1) {
			for (i = 0; i < N; i++) {
				if (arr2[i] % x == 0) {
					arr2[i] /= x;
					sum += arr1[i];
				}
				else {
					c = true;
					break;
				}
			}
			if (c) break;
		}
		cout << sum << endl;
	}
}