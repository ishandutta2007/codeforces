#include <bits/stdc++.h>
#define ST first
#define ND second
#define PB push_back

using namespace std;
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

struct Point {
	int x, y;
};

const int nax = 6000 + 10;
int n;
Point p[nax];
int cnt[4][4];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> p[i].x >> p[i].y;
	}
	ll ans = 0;
	for(int i = 1; i <= n; ++i) {
		int x = p[i].x, y = p[i].y;
		for(int j = 1; j <= n; ++j) {
			p[j].x -= x;
			p[j].y -= y;
		}
		for(int a = 0; a < 4; ++a) {
			for(int b = 0; b < 4; ++b) {
				cnt[a][b] = 0;
			}
		}
		for(int j = 1; j <= n; ++j) {
			if(i == j) continue;
			cnt[((p[j].x%4)+4)%4][((p[j].y%4)+4)%4]++;
		}
		for(int a1 = 0; a1 < 4; ++a1) {
			for(int b1 = 0; b1 < 4; ++b1) {
					for(int a2 = 0; a2 < 4; ++a2) {
						for(int b2 = 0; b2 < 4; ++b2) {
								int w1 = (a1 * b2 - a2 * b1) % 4;
								if(w1 < 0) w1 += 4;
								int w2 = __gcd(a1, b1) + __gcd(a2, b2) + __gcd(a1 - a2, b1 - b2);
								w2 %= 4;
								if(w2 < 0) w2 += 4;
								if(w1 == w2) {
									if(a1 == a2 && b1 == b2) {
										ans += (ll)cnt[a1][b1] * (cnt[a1][b1] - 1);
									} else {
										 ans += (ll)cnt[a1][b1] * cnt[a2][b2];
									}
								}
						}
					}
					
			}
		}
		
	}
	cout << ans / 6;
}