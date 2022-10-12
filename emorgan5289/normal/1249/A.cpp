#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int Q, N, A[100];

int main() {
	ifstream fin("test.in");
	cin >> Q;
	for (int q = 0; q < Q; q++) {
		cin >> N;
		bool flag = true;
		for (int i = 0; i < N; i++)
			cin >> A[i];
		sort(A, A+N);
		for (int i = 0; i < N-1; i++) {
			if (A[i]+1 == A[i+1])
				flag = false;
		}
		cout << (flag ? 1 : 2) << endl;
	}
}