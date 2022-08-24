#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

#define data hjksdlf
const int N = 1 << 26;
unsigned long long data[N / 3 + 100];
unsigned long long ones = (1 << 17) - 1;

unsigned int get(int pos) {
	return (data[pos / 3] >> (pos % 3 * 17)) & ones;
}

void inc(int pos) {
	unsigned long long x = get(pos) + 1;
	data[pos / 3] = data[pos / 3] & (~(ones << (pos % 3 * 17)));
	data[pos / 3] |= x << (pos % 3 * 17);
}

int getMask(const string& s) {
	int mask = 0;
	for (char c : s) {
		mask ^= 1 << (c - 'a');
	}
	return mask;
}

int main() {
	ios_base::sync_with_stdio(0);
	int n = nxt();
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int mask = getMask(s);
		ans += get(mask);
		inc(mask);
		for (int i = 0; i < 26; ++i) {
			ans += get(mask ^ (1 << i));
		}
	}
	cout << ans << "\n";

	return 0;
}