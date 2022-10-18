#include <iostream>
#include <vector>

using namespace std;

int arr[505][505];

int main() {
	int n, k;
	scanf("%d%d", &n, &k); --k;
	int cur = n * n, ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = n - 1; j >= k; --j) {
			arr[i][j] = cur--;
		}
		ans += arr[i][k];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = k - 1; j >= 0; --j) {
			arr[i][j] = cur--;
		}
	}
	
	printf("%d\n", ans);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}