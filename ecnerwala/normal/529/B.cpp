#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

const int MAXN = 2000;
int N;
ll W[MAXN];
ll H[MAXN];

ll solve(ll height) {
	int numdown = N / 2;
	vector<ll> gains;
	ll width = 0;
	for(int i = 0; i < N; i++) {
		ll w = W[i], h = H[i];
		if(w > height && h > height) {
			return INF;
		} else if(w > height) {
			width += w;
		} else if(h > height) {
			numdown --;
			width += h;
		} else {
			width += w;
			if(h < w) gains.push_back(w - h);
		}
	}

	if(numdown < 0) return INF;
	sort(gains.begin(), gains.end());
	while(numdown && !gains.empty()) {
		numdown --;
		width -= gains.back();
		gains.pop_back();
	}

	return width * height;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> W[i] >> H[i];
	}

	ll res = INF;
	for(int i = 0; i < 1500; i++) {
		ll v = solve(i);
		res = min(res, v);
	}
	cout << res << '\n';
	return 0;
}