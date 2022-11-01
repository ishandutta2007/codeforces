#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

unsigned hash_f(unsigned x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}
struct chash {
    int operator()(int x) const { return hash_f(x); }
};

gp_hash_table<int, int, chash> dp[30010];

int n, d, ar[30010], x;

int solve(int pos, int last) {
	if(pos > 30000 || last == 0) return 0;
	auto p = dp[pos].find(last);
	if(p != dp[pos].end()) return (*p).second;
	
	int x = ar[pos] + solve(pos + last + 1, last + 1);
	x = max(x, ar[pos] + solve(pos + last, last));
	x = max(x, ar[pos] + solve(pos + last - 1, last - 1));
	
	return dp[pos][last] = x;
}

int main() {
	scanf("%d %d", &n, &d);
	for(int i = 0; i < n; i++) {
		scanf("%d", &x);
		ar[x]++;
	}
	printf("%d\n", solve(d, d));
	return 0;
}