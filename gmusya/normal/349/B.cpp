#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(9);
	for (int i = 0; i < 9; i++)
		cin >> a[i];
	int mi = 0;
	for (int i = 0; i < 9; i++)
		if (a[mi] >= a[i])
			mi = i;
	string ans;
	while (n >= a[mi]) {
		ans += '1' + mi;
		n -= a[mi];
	}
	if (ans.size() == 0) {
		cout << "-1";
		return 0;
	}
	for (int i = 0; i < ans.size(); i++) {
		bool tf = false;
		for (int j = 8; j > mi; j--) 
			if (n - (a[j] - a[mi]) >= 0) {
				ans[i] = '1' + j;
				tf = true;
				n -= (a[j] - a[mi]);
				break;
			}
		if (!tf)
			break;
	}
	cout << ans;
	return 0;
}