#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int n, k, leaf, len;
	cin >> n >> k;
	
	if ((n-1)%k == 1)
		len = 2*((n-1)/k) + 1;
	else
		len = 2*((n-2)/k) + 2;
	cout << len << endl;

	queue<int> next;
	for (int i = 0; i < k; i++)
		next.push(1);
	for (int curr = 2; curr <= n; curr++) {
		leaf = next.front();
		next.pop();
		cout << leaf << " " << curr << endl;
		next.push(curr);
	}

	return 0;
}