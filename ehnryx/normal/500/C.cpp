#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define End return 0; }
#define lame cin.tie(0);LAME
#define of ios::sync_with_stdio(0);
#define story int main() {
#define The

The story of lame:

	int stkpos;
	int stk[501];
	int weight[501];
	int book[1001];
	bitset<501> seen;
	int n, read;
	cin >> n >> read;
	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}
	stkpos = 0;
	for (int i = 0; i < read; i++) {
		cin >> book[i];
		--book[i];
		if (!seen[book[i]]) {
			seen[book[i]] = true;
			stk[stkpos++] = book[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (!seen[i])
			stk[stkpos++] = i;
	}

	// do the thing
	int ans = 0;
	for (int i = 0; i < read; i++) {
		int j = 0;
		while (stk[j] != book[i])
			j++;
		--j;
		while (j >= 0) {
			ans += weight[stk[j]];
			stk[j+1] = stk[j];
			j--;
		}
		stk[0] = book[i];
	}

	cout << ans << endl;

The End