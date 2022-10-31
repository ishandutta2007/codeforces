#include <bits/stdc++.h>
using namespace std;
#define MAX 2020202
int arr[MAX];
int dy[MAX];
int main() {
	int T;
	cin >> T;
	while (T-- > 0) {
		int N;
		cin >> N;
		int i;
		int ans = 0;
		for (i = 1; i <= N; i++) arr[i] = dy[i] = 0;
		for (i = 1; i <= N; i++) {
			cin >> arr[i];
			if (arr[i] + i > N) {
				ans = max(ans, arr[i] + dy[i]);
			}
			else {
				dy[arr[i] + i] = max(dy[arr[i] + i], dy[i] + arr[i]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}