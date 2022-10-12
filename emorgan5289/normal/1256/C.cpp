#include <fstream>
#include <iostream>

using namespace std;

int N, M, D, C, pos, lens[5000], data[5000] = {};

int main() {
	ifstream fin("test.in");
	cin >> N >> M >> D;
	pos = 0;
	int sumC = 0;
	for (int i = 0; i < M; i++) {
		cin >> lens[i];
		sumC += lens[i];
	}
	for (int i = 0; i < M; i++) {
		int d = min(D-1, N-pos-sumC);
		pos += d;
		for (int j = pos; j < pos+lens[i]; j++) {
			data[j] = i+1;
		}
		pos += lens[i];
		sumC -= lens[i];
	}
	if (pos+D-1 < N) {
		cout << "NO" << endl;
		// for (int i = 0; i < N-1; i++)
		// 	cout << data[i] << " ";
		// cout << data[N-1] << endl;
	} else {
		cout << "YES" << endl;
		for (int i = 0; i < N-1; i++)
			cout << data[i] << " ";
		cout << data[N-1] << endl;
	}
}