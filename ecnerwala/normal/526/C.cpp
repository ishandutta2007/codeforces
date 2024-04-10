#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll C, Hr, Hb, Wr, Wb;
	cin >> C >> Hr >> Hb >> Wr >> Wb;
	ll res = 0;
	ll cnt = max(C / Wr / Wb - 1, 0ll);
	C -= Wr * Wb * cnt;
	res += cnt * max(Wb * Hr, Wr * Hb);
	if(Wr < Wb) {
		swap(Wr, Wb);
		swap(Hr, Hb);
	}
	assert(Wr >= Wb);
	// Wb is small
	ll v = 0;
	for(ll i = 0; i * Wr <= C; i++) {
		v = max(v, i * Hr + (C - i * Wr) / Wb * Hb);
	}
	res += v;
	cout << res << '\n';
	return 0;
}