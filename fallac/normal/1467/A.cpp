#include <bits/stdc++.h>
using namespace std;
#define MAX 310
int arrp[MAX], arrm[MAX];
int main(void) {
	int T;
	cin >> T;
	while (T-- > 0) {
		int N;
		cin >> N;
		int i, a = 10;
		if (N == 1) cout << 9;
		else if (N == 2) cout << 98;
		else {
			cout << 98;
			a = 8;
			for (i = 1; i <= N - 2; i++) {
				a++;
				if (a >= 10) a = 0;
				cout << a;
			}
		}
		cout << endl;
	}

}