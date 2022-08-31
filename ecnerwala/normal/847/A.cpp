#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200;
int N;
int L[MAXN];
int R[MAXN];
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> L[i] >> R[i];
	}
	int prv_en = 0;
	for (int i = 1; i <= N; i++) {
		if (L[i] == 0) {
			if (prv_en != 0) {
				R[prv_en] = i;
				L[i] = prv_en;
			}
			prv_en = i;
			while (R[prv_en]) prv_en = R[prv_en];
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << L[i] << ' ' << R[i] << '\n';
	}

	return 0;
}