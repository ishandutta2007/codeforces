#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

const int nax = 300 * 1000 + 10;
int n;
vi a;
int x;
ll inv;
ll ans[50][2];

void rec(vi v, int bit) {
	if((int)v.size() == 0 || bit == -1) {
		return;
	}
	vi A = {}, B = {};
	//cout << bit << ": ";
	//for(int y : v) cout << y << " ";
	//cout << "\n";
	int cnt1 = 0, cnt0 = 0;
	ll cur = 0, rest = 0;
	for(int i = 0; i < (int)v.size(); ++i) {
		if(v[i] & (1 << bit)) {
			cnt1++;
			A.PB(v[i]);
			rest += cnt0;
		} else {
			cur += cnt1;
			cnt0++;
			B.PB(v[i]);
		}
	}
	//ll rest = ((ll)((int)v.size()) * ((int)v.size() - 1) / 2) - cur;
	ans[bit][0] += cur;
	ans[bit][1] += rest;
	rec(A, bit - 1);
	rec(B, bit - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	rec(a, 31);
	for(int i = 31; i >= 0; --i) {
		//cout << i << ": " << ans[i][0] << " " << ans[i][1] << "\n";
		if(ans[i][0] <= ans[i][1]) {
			inv += ans[i][0];
		} else {
			x += (1 << i);
			inv += ans[i][1];
		}
	}
	cout << inv << " " << x;
	
}