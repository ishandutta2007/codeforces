#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int k;
	int n, m, cap;
	cin >> n >> m >> cap;
	int count = 0;
	int arr[n+2];
	memset(arr, -1, sizeof(arr));
	for (int i = 0; i < m && count < n; i++) {
		cin >> k;
		double unrounded = (double)n*k/cap;
		if (k <= cap/2) unrounded -= (double)n/cap;
		int j = min(n, max(1, (int)lround(unrounded)));
		if (arr[j] == -1) {
			arr[j] = k;
			count++;
		} else if (k < arr[j]) {
			lesser:
			while (j > 1 && k <= arr[j]) {
				j--;
			}
			if (arr[j] == -1) {
				count++;
			}
			arr[j] = k;
		} else if (k > arr[j]) {
			greater:
			while (j < n && k >= arr[j] && arr[j] != -1) {
				j++;
			}
			if (arr[j] == -1) {
				count++;
			}
			arr[j] = k;
		} else {
			int left, right;
			left = right = 0;
			for (int id = 1; id < j; id++)
				if (arr[id] == -1) 
					left++;
			for (int id = n; id > j; id--)
				if (arr[id] == -1)
					right++;
			if (left == 0)
				goto greater;
			if (right == 0) 
				goto lesser;
			if ((k-1)*right == (cap-k)*left) {
				goto greater;
			}
			else if ((k-1)*right < (cap-k)*left) 
				goto lesser;
			else
				goto greater;
		}
		cout << j << endl;
	}

	cerr << "ARRAY: " << nl;
	for (int i = 1; i <= n; i++)
		cerr << arr[i] << " ";
	cerr << endl;

	return 0;
}