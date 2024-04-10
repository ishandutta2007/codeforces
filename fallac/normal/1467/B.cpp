#include <bits/stdc++.h>
using namespace std;
#define MAX 303030
int arr[MAX], h[MAX], v[MAX], N;
int f(int x) {
	int i;
	int cnt = 0;
	for (i = max(2, x - 1); i <= min(N - 1, x + 1); i++) {
		if (arr[i] < arr[i + 1] && arr[i] < arr[i - 1]) cnt++;
		if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1]) cnt++;
	}
	return cnt;
}
int main(void) {
	int T;
	cin >> T;
	while (T-- > 0) {
		cin >> N;
		int i, a = 10;
		int cnt = 0;
		for (i = 1; i <= N; i++) cin >> arr[i];
		for (i = 1; i <= N; i++) h[i] = v[i] = 0;
		for (i = 2; i < N; i++) {
			if (arr[i] < arr[i + 1] && arr[i] < arr[i - 1]) h[i] = 1;
			if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1]) v[i] = 1;
		}
		for (i = 1; i <= N; i++) {
			if (h[i] + v[i]) cnt++;
		}
		int c = 0;
		for (i = 2; i < N; i++) {
			int t = arr[i];
			int n = f(i);
			arr[i] = arr[i - 1];
			c = max(c, n - f(i));
			arr[i] = arr[i + 1];
			c = max(c, n - f(i));
			arr[i] = t;
		}
		cout << max(0, cnt - c) << endl;
	}

}