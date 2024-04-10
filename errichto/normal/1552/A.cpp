#include <bits/stdc++.h>
using namespace std;
int main() {
    long long h = 0;
    for(int i = 1; i <= 5000; ++i) {
        for(int j = i + 1; j <= 4000; ++j) {
            h += __gcd(i, j);
        }
    }
    cerr << h << endl;
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		string s2 = s;
		sort(s2.begin(), s2.end());
		int answer = 0;
		for(int i = 0; i < n; ++i) {
			answer += (s[i] != s2[i]);
		}
		// for(int i = 0; i < n; ++i) {
			// for(int j = i + 1; j < n; ++j) {
				// if(s[i] > s[j]) {
					// answer.insert(s[i]);
					// answer.insert(s[j]);
				// }
			// }
		// }
		printf("%d\n", answer);
	}
}