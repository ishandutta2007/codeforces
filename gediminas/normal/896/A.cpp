/*input
10
4 1825
3 75
3 530
4 1829
4 1651
3 187
4 584
4 255
4 774
2 474
*/
#include <bits/stdc++.h>

using namespace std;

string a = "What are you doing at the end of the world? Are you busy? Will you save us?";
string b = "What are you doing while sending \"\"? Are you busy? Will you send \"\"?";
string c = "What are you doing while sending \"";
string d = "\"? Are you busy? Will you send \"";
string e = "\"?";
long long din[100001] = {};

char find(long long n, long long k) {
	assert(k >= 0);

	if (k >= din[n])
		return '.';

	if (n == 0) {
		if (k > a.size())
			return '.';

		return a[k];
	}

	if (k < c.size())
		return c[k];

	if (k < c.size() + din[n - 1])
		return find(n - 1, k - c.size());

	if (k < c.size() + din[n - 1] + d.size())
		return d[k - c.size() - din[n - 1]];

	if (k < c.size() + din[n - 1] + d.size() + din[n - 1])
		return find(n - 1, k - c.size() - din[n - 1] - d.size());

	return e[k - c.size() - din[n - 1] - d.size() - din[n - 1]];
}

int main () {
	din[0] = a.size();

	for (int i = 1; i <= 100000; i++) {
		din[i] = min(1000000000000000001ll, din[i - 1] * 2 + b.size());
		assert(din[i] > 0);
	}

	int q;
	cin >> q;

	while (q--) {
		long long n, k;
		cin >> n >> k;

		cout << find(n, k - 1);
	}

	return 0;
}