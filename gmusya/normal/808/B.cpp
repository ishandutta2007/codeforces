#include <iostream>
#include <vector>
#include <iomanip>

#define dl double long
#define fsp fixed << setprecision(10)
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector <dl> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	dl sum = 0, cur_sum = 0;
	for (int i = 0; i < k; i++)
		cur_sum += a[i];
	sum += cur_sum;
	for (int i = k; i < n; i++) {
		cur_sum += a[i] - a[i - k];
		sum += cur_sum;
	}
	cout << fsp << sum / (n - k + 1);
	return 0;
}