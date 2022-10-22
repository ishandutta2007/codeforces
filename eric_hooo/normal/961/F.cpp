#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int P = 3323232323;

char s[1000010];
int H[1000010], pw[1000010];
int n;
vector <int> ans;

int GetHash(int l, int r) {
	return (H[r] - 1ll * H[l - 1] * pw[r - l + 1] % mod + mod) % mod;
}

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	pw[0] = 1;
	for (int i = 1; i <= n; i++) {
		H[i] = (1ll * H[i - 1] * P + s[i]) % mod;
		pw[i] = 1ll * pw[i - 1] * P % mod;
	}
	int l = n + 1 >> 1, r = n + 2 >> 1, cur = 233;
	while (l >= 1) {
		auto Check = [](int l, int r, int k) -> bool {
			return k >= r - l + 1 ? 0 : k == -1 ? 1 : GetHash(l, l + k - 1) == GetHash(r - k + 1, r);
		};
		while (!Check(l, r, cur)) cur -= 2;
		ans.push_back(cur);
		cur += 2, l--, r++;
	}
	reverse(ans.begin(), ans.end());
	for (auto it : ans) {
		printf("%d ", it);
	}
	printf("\n");
	return 0;
}