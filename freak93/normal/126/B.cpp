#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string s; cin >> s;
	s = " " + s;
	int N = s.size() - 1;
	vector<int> pi(N + 2, 0), apar(N + 2, 0);
	int k = 0;
	for (int i = 2; i <= N; ++i) {
		while (k > 0 && s[k + 1] != s[i])
			k = pi[k];
		if (s[k + 1] == s[i])
			++k;
		if (i != N)
			apar[k]++;
		pi[i] = k;
	}
	
	for (int i = N; i > 0; --i)
		if (apar[i] > 0)
			apar[pi[i]] = apar[i];
	
	while (k > 0) {
		if (apar[k]) {
			for (int i = 0; i < k; ++i)
				cout << s[i + 1];
			return 0;
		}
		k = pi[k];
	}
	cout << "Just a legend";
}