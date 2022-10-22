#include <bits/stdc++.h>
   
using namespace std;

#define int long long

int fact[20];

int get(int cnt[]) {
	int sum = 0;
	for (int i = 0; i <= 9; ++i) sum += cnt[i];
	int ans = fact[sum];
	for (int i = 0; i <= 9; ++i) ans /= fact[cnt[i]];
	return ans;
}
	
int solve(int cnt[]) {
	int ans = 0;
	for (int i = 1; i <= 9; ++i) {
		if (!cnt[i]) continue;
		--cnt[i];
	 	ans += get(cnt);
	 	++cnt[i];
	}
	return ans;
}

int a[10];
int all[10];
int ans = 0;

void rec(int c) {
 	if (c == 10) {
		ans += solve(a);
		return;
 	}

 	if (!all[c]) {
 	    a[c] = 0;
 	    rec(c + 1);
 	}
 	else {
 		for (int i = 1; i <= all[c]; ++i) {
 	 		a[c] = i;
 	 		rec(c + 1);
 		}
 	}
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);

    fact[0] = 1;
    for (int i = 1; i <= 18; ++i) {
    	fact[i] = fact[i - 1] * i;
    }

    string s;
    cin >> s;
	for (char c : s) ++all[c - '0'];
	rec(0);
	cout << ans << '\n';

    return 0;
}