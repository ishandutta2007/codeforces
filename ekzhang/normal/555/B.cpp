#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> pll;
#define MAXN 200000

int N, M;
pair<pll, int> range[MAXN - 1];
pair<LL, int> bridge[MAXN];
priority_queue<pair<LL, int>, vector<pair<LL, int> >, 
		greater<pair<LL, int> > > rends;
int ans[MAXN - 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("555B.in", "r", stdin);

	cin >> N >> M;
	LL prevL, prevR;
	cin >> prevL >> prevR;
	for (int i = 0; i < N - 1; i++) {
		LL L, R;
		cin >> L >> R;
		range[i] = {{L - prevR, R - prevL}, i};
		prevL = L;
		prevR = R;
	}
	for (int i = 0; i < M; i++) {
		cin >> bridge[i].first;
		bridge[i].second = i;
	}

	sort(range, range + N - 1);
	sort(bridge, bridge + M);
	int ind = 0;
	for (int i = 0; i < M; i++) {
		while (ind < N - 1 && bridge[i].first >= range[ind].first.first) {
			rends.push(make_pair(range[ind].first.second, range[ind].second));
			ind++;
		}
		if (!rends.empty()) {
			pair<LL, int> e = rends.top();
			rends.pop();
			if (e.first >= bridge[i].first) {
				ans[e.second] = bridge[i].second + 1;
			}
			else {
				// can't find a spot for this bridge
				cout << "No" << endl;
				return 0;
			}
		}
	}

	if (ind < N - 1 || !rends.empty()) {
		// still have bridges left :(
		cout << "No" << endl;
		return 0;
	}
	
	cout << "Yes" << '\n';
	cout << ans[0];
	for (int i = 1; i < N - 1; i++) {
		cout << ' ' << ans[i];
	}

	cout << endl;
	return 0;
}