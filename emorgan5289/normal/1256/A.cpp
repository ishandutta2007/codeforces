#include <fstream>
#include <iostream>

using namespace std;

long Q, A, B, N, S;

int main() {
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> A >> B >> N >> S;
		int r;
		if (S/N > A)
			r = S - A*N;
		else
			r = S%N;
		if (r <= B)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}