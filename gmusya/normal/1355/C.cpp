#include <iostream>
#include <vector>

using namespace std;

int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	vector <long long> a(D + D + 1);
	for (int i = A; i <= B; i++) 
		a[i + B]++, a[i + C + 1]--;
	for (int i = 1; i <= D + D; i++)
		a[i] += a[i - 1];
	for (int i = 1; i <= D + D; i++)
		a[i] += a[i - 1];
	long long ans = 0;
	for (int i = C; i <= D; i++)
		ans += a[D + D] - a[i];
	cout << ans;
	return 0;
}