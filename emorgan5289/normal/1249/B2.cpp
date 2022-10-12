#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Q, N, P[200000], out[200000];
vector<int> mem;

int main() {
	ifstream fin("test.in");
	cin >> Q;
	for (int q = 0; q < Q; q++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> P[i];
			P[i]--;
			out[i] = 0;
		}
		for (int i = 0; i < N; i++) {
			if (out[i]) continue;
			mem.clear();
			int cur = P[i];
			mem.push_back(i);
			while (cur != i) {
				mem.push_back(cur);
				cur = P[cur];
			}
			for (int x : mem)
				out[x] = mem.size();
		}
		for (int i = 0; i < N-1; i++) {
			cout << out[i] << " ";
		}
		cout << out[N-1] << endl;
	}
}