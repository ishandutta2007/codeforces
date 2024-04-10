#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int 

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {
		int n, k, d;
		vector <int> a;
		cin >> n >> k >> d;
		a.resize(n);
		int answer = d;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n - d + 1; i++) {
			vector <bool> used(k + 1);
			int ans = 0;
			for (int j = i; j < i + d; j++) {
				ans += 1 - used[a[j]];
				used[a[j]] = true;
			}
			answer = min(answer, ans);
		}
		cout << answer << endl;
	}
	return 0;
}