#include<iostream>
using namespace std;

const int MAXP = 1e5;

int N, M, X, Y, Z;
int P;
int A[MAXP];
int B[MAXP];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> M >> X >> Y >> Z >> P;
	for(int i = 0; i < P; i++) cin >> A[i] >> B[i];
	X %= 4, Y %= 2, Z %= 4;
	for(int i = 0; i < X; i++) {
		for(int n = 0; n < P; n++) {
			int a = A[n];
			int b = B[n];
			A[n] = b;
			B[n] = N + 1 - a;
		}
		swap(N, M);
	}
	for(int i = 0; i < Y; i++) {
		for(int n = 0; n < P; n++) {
			B[n] = M + 1 - B[n];
		}
	}
	for(int i = 0; i < Z; i++) {
		for(int n = 0; n < P; n++) {
			int a = A[n];
			int b = B[n];
			A[n] = M + 1 - b;
			B[n] = a;
		}
		swap(N, M);
	}
	for(int i = 0; i < P; i++) {
		cout << A[i] << ' ' << B[i] << '\n';
	}
	return 0;
}