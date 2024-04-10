#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i]; v[i]--;
	}
	vector<char> have(n, false);
	int ktr = n-1;
	for (int i = 0; i < n; i++) {
		have[v[i]] = true;
		while (ktr >= 0 && have[ktr]) {
			cout << ktr+1 << " ";
			ktr--;
		}
		cout << "\n";
	}
	return 0;
}