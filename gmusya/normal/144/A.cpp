#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int minid = 0, maxid = 0;
	for (int i = 0; i < n; i++) {
		if (a[minid] >= a[i])
			minid = i;
		if (a[maxid] < a[i])
			maxid = i;
	}
	cout << maxid + n - 1 - minid - (maxid > minid);
	return 0;
}