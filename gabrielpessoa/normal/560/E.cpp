#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int ms = 2005, mv = 2e5+5;
const ll mod = 1e9+7;

int h, w, n;
ii black[ms];
ll ans[ms];
ll fat[mv], ifat[mv];

ll invert(ll a) {
	ll ans = 1, b = mod - 2;
	while(b) {
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

ll comb(int x, int y) {
	return fat[x+y] * ifat[x] % mod * ifat[y] % mod;
}

int main(){
	cin >> h >> w >> n;
	for(int i = 0; i < n; i++) {
		cin >> black[i].first >> black[i].second;
		black[i].first--;
		black[i].second--;
	}
	sort(black, black+n);
	fat[0] = 1, ifat[0] = 1;
	for(int i = 1; i < mv; i++) {
		fat[i] = (fat[i-1] * i) % mod;
		ifat[i] = invert(fat[i]);
	}
	//cout << fat[2] << ' ' << ifat[2] << endl;
	black[n] = ii(h-1, w-1);
	for(int i = 0; i <= n; i++) {
		int x = black[i].first, y = black[i].second;
		ans[i] = comb(x, y);
		for(int j = 0; j < i; j++) {
			int a = black[j].first, b = black[j].second;
			if(b <= y) {
				ans[i] -= ans[j] * comb(x-a, y-b) % mod;
			}
		}
		ans[i] = ((ans[i] % mod) + mod) % mod;
		//cout << x << ' ' << y << ' ' << ans[i] << endl;
	}
	cout << ans[n] << endl;
	return 0;
}