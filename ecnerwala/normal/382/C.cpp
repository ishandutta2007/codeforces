#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2e5;

int N;
ll A[MAXN];
ll D[MAXN];

int main() {
	cin >> N;
	for(int i = 0; i < N; i ++) {
		cin >> A[i];
	}
	sort(A, A + N);
	if(N == 1) {
		cout << -1 << '\n';
	} else if(A[0] == A[N - 1]) {
		cout << 1 << '\n';
		cout << A[0] << '\n';
	} else if(N == 2) {
		if((A[0] + A[1]) % 2 == 0){
			cout << 3 << '\n';
			cout << 2 * A[0] - A[1] << ' ';
			cout << (A[1] + A[0]) / 2 << ' ';
			cout << 2 * A[1] - A[0] << '\n';
		} else {
			cout << 2 << '\n';
			cout << 2 * A[0] - A[1] << ' ';
			cout << 2 * A[1] - A[0] << '\n';
		}
	} else {
		for(int i = 0; i + 1 < N; i++) {
			D[i] = A[i + 1] - A[i];
		}
		sort(D, D + N - 1);
		if(D[N - 2] == D[0]) {
			cout << 2 << '\n';
			cout << 2 * A[0] - A[1] << ' ';
			cout << 2 * A[N - 1] - A[N - 2] << '\n';
		} else {
			bool good = 2 * D[0] == D[N - 2];
			for(int i = 0; i < N - 2; i++) {
				if(D[i] != D[0]) good = false;
			}
			if(good) {
				cout << 1 << '\n';
				for(int i = 0; i < N - 1; i ++) {
					if(A[i + 1] - A[i] == D[N - 2]) {
						cout << (A[i] + A[i + 1]) / 2 << '\n';

					}
				}
			} else {
				cout << 0 << '\n';
			}
		}
	}
}