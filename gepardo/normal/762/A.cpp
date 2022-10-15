#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

vector<int64_t> front, back;

int main() {
	int64_t n, k; cin >> n >> k;
	for (int64_t i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			int64_t j = n / i;
			front.push_back(i);
			if (i != j) {
				back.push_back(j);
			}
		}
	}
	int64_t cnt = front.size() + back.size();
	if (k <= (int64_t)front.size()) {
		cout << front[k-1] << endl;
	} else if (k <= cnt) {
		cout << back[cnt-k] << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}