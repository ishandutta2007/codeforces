#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll find(ll n, ll index, ll power) {
	if (index == 0)
		return 0;
	ll mid, head, temp;
	power /= 2;
	mid = power;
	head = n/2 + n%2;
	temp = n;
	int count = 0; //
	while (mid != index) {
		power /= 2;
		if (++count > 50) 
			return head; //
		if (mid > index) {
			mid -= power;
			head -= temp%2;
			temp /= 2;
			head -= temp/2;
		}
		else {
			mid += power;
			temp /= 2;
			head += temp%2;
			head += temp/2;
		}
	}
	return head;
}

int main() {
	ll n, left, right;
	ll first, second, power;
	cin >> n >> left >> right;
/*	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}*/
	for (power = 1ll; power <= n; power = power << 1)
		;
	first = find(n, left-1, power);
	second = find(n, right, power);
//	cout << "first: " << first << endl;
//	cout << "second: " << second << endl;
	cout << second - first << endl;
	return 0;
}