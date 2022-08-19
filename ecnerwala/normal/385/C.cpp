#include<iostream>
#include<cstring>

using namespace std;

const int MAXV = 1e7 + 20;

int fact[MAXV];
int cnt[MAXV];
long long pref[MAXV];

void precomp() {
	memset(fact, -1, sizeof(fact));
	fact[0] = 0;
	fact[1] = 1;
	for(int i = 2; i < MAXV; i++) {
		if(fact[i] == -1) {
			for(int j = i; j < MAXV; j += i) {
				fact[j] = i;
			}
		}
	}
}

void insert(int x) {
	while(x > 1) {
		int p = fact[x];
		cnt[p] ++;
		while(x % p == 0) x /= p;
	}
}

long long query(int l, int r) {
	if(l >= MAXV) return 0;
	if(r >= MAXV) r = MAXV - 1;
	return pref[r] - pref[l - 1];
}


int main() {
	precomp();
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		int x; cin >> x; insert(x);
	}
	pref[0] = 0;
	for(int i = 1; i < MAXV; i++) {
		pref[i] = pref[i - 1] + cnt[i];
	}
	int m; cin >> m;
	for(int i = 0; i < m; i++) {
		int l, r; cin >> l >> r;
		cout << query(l, r) << '\n';
	}
}