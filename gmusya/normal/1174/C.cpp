#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> p(n);
	vector <int> ans(n + 2);
	p[0] = 2;
	ans[2] = 1;
	int sizeofp = 1;
	for (int i = 3; i <= n; i++) {
		bool tf = true;
		for (int j = 0; j < sizeofp; j++) if (i % p[j] == 0) {
			tf = false;
			ans[i] = j + 1;
			break;
		}
		if (tf) {
			p[sizeofp] = i;
			sizeofp++;
			ans[i] = sizeofp;
		}
	}
	for (int i = 2; i <= n; i++) cout << ans[i] << " ";
	return 0;
}