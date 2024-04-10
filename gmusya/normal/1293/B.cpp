#include <iostream>
#include <vector>
#include <iomanip>

#define dl double long
#define fsp fixed << setprecision(10)

using namespace std;

int main() {
	dl n;
	cin >> n;
	dl ans = 0;
	for (dl i = 1; i <= n; i++)
		ans += 1 / i;
	cout << fsp << ans;
	return 0;
}