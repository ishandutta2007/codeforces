#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define pre(a) cout << fixed; cout.precision(a);
#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;

int n;
ll h[1000010];
ll ans[1000010];
priority_queue<int> pQ;

int main() {
	fast;

	cin >> n;

	for(int i=1; i<=n; i++) {
		cin >> h[i];
	}

	ans[1] = h[1];

	for(int i=2; i<=n; i++) {
		ll cnt = h[i] - (ans[1] + i - 1 - (int) pQ.size());

		if(cnt >= 0) {
			while(cnt) {
				if(pQ.empty()) {
					if(cnt >= i) {
						ans[1] += cnt / i;
						cnt -= i * (cnt / i);
					}
					else {
						cnt--;
						pQ.em(2);
						ans[1]++;
					}

					continue;
				}

				int j = pQ.top();
				pQ.pop();

				if(cnt >= i + 1 - j) cnt -= i + 1 - j;
				else {
					j += cnt;
					pQ.em(j);
					cnt = 0;
				}
			}
		}
		else {
			pQ.em(i);
		}
	}

	for(int i=2; i<=n; i++) {
		ans[i] = 1;
	}

	while(pQ.size()) {
		int i = pQ.top();
		ans[i] = 0;
		pQ.pop();
	}

	for(int i=1; i<=n; i++) {
		ans[i] += ans[i-1];

		cout << ans[i] << " ";
	}
}