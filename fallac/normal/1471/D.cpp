#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
#define MAX 1010101
#define ln '\n'
lld arr[MAX];
vector<lld>prime;
lld parr[MAX];
void init() {
	lld i, j;
	for (i = 2; i <= 1000; i++) {
		if (parr[i] == 0) for (j = 2 * i; j <= 1000; j += i) parr[j] = 1;
		if (parr[i] == 0) prime.push_back(i);
	}
}
lld div(lld x) {
	for (auto i : prime) {
		while ((x % (i*i)) == 0) x /= (i*i);
		if (x < (i*i)) break;
	}
	return x;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	lld T;
	cin >> T;
	init();
	while (T-- > 0) {
		lld N;
		cin >> N;
		lld i;
		lld a;
		for (i = 1; i <= N; i++) {
			cin >> arr[i];
			arr[i] = div(arr[i]);
		}
		sort(arr + 1, arr + N + 1);
		lld one, odd, even;
		lld modd, meven, seven;
		one = odd = even = modd = meven = seven = 0;
		lld last = 0;
		if (arr[1] == 1) one++;
		else last = 1;
		for (i = 2; i <= N; i++) {
			if (arr[i] == 1) one++;
			else if (arr[i] == arr[i - 1]) last++;
			else {
				if (last) {
					if (last % 2) {
						odd++;
						modd = max(modd, last);
					}
					else {
						even++;
						meven = max(meven, last);
						seven += last;
					}
				}
				last = 1;
			}
		}
		if (last) {
			if (last % 2) {
				odd++;
				modd = max(modd, last);
			}
			else {
				even++;
				meven = max(meven, last);
				seven += last;
			}
		}
		lld q, w;
		cin >> q;
		lld ans1, ans2;
		ans1 = max(one, max(modd, meven));
		ans2 = max(one + seven, modd);
		if (N == 1) ans1 = ans2 = 1;
		for (i = 1; i <= q; i++) {
			cin >> w;
			if (w == 0) cout << ans1 << ln;
			else cout << ans2 << ln;
		}
	}
	return 0;
}