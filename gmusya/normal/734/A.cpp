#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <char> a(n);
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		if (a[i] == 'A')
			cnt1++;
		else
			cnt2++;
	}
	if (cnt1 > cnt2)
		cout << "Anton";
	if (cnt1 == cnt2)
		cout << "Friendship";
	if (cnt1 < cnt2)
		cout << "Danik";
	return 0;
}