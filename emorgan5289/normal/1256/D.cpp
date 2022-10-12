#include <fstream>
#include <iostream>
#include <deque>

using namespace std;

long long Q, N, K, pos;
string S, out;

int main() {
	ifstream fin("test.in");
	cin >> Q;
	for (int q = 0; q < Q; q++) {
		cin >> N >> K >> S;
		pos = 0;
		out = "";
		// cout << S << endl;
		for (int i = 0; i < N; i++) {
			char c = S[i];
			if (c == '0') {
				if (K >= i-pos) {
					K -= (i-pos);
					pos += 1;
					out += '0';
				} else {
					long long d = i-pos-K;
					for (int j = 0; j < d; j++) {
						pos += 1;
						out += '1';
					}
					pos += 1;
					out += '0';
					K = 0;
				}
			}
			// cout << i << " " << pos << " " << out << " " << K << endl;
		}
		for (int i = pos; i < N; i++)
			out += '1';
		cout << out << endl;
	}
}