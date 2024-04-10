#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e18;

const int S = 1 << 20;
struct seg_node {
	ll sumMonster;
	ll bestProfit;
} seg[2*S];

void updateNode(int i) {
	if (i < S) {
		int l = 2*i+0, r = 2*i+1;
		seg[i].sumMonster = seg[l].sumMonster + seg[r].sumMonster;
		seg[i].bestProfit = max(seg[l].bestProfit, seg[l].sumMonster + seg[r].bestProfit);
	}
}
void updateAll(int i) {
	for (int a = i; a; a /= 2) updateNode(a);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M, P; cin >> N >> M >> P;
	vector<pair<int, ll>> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i].first >> A[i].second;
	}

	vector<pair<int, ll>> B(M);
	for (int j = 0; j < M; j++) {
		cin >> B[j].first >> B[j].second;
	}

	vector<pair<pair<int, int>, ll>> MONSTERS(P);
	for (auto& it : MONSTERS) {
		cin >> it.first.first >> it.first.second >> it.second;
	}

	for (int i = S; i < 2*S; i++) {
		seg[i] = {0, -INF};
	}
	for (auto it : B) {
		int y = it.first;
		seg[y+S].bestProfit = max(seg[y+S].bestProfit, -it.second);
	}
	for (int i = S-1; i; i--) {
		updateNode(i);
	}

	sort(A.begin(), A.end());
	sort(MONSTERS.begin(), MONSTERS.end());
	auto monsterIt = MONSTERS.begin();
	ll ans = -INF;
	for (auto it : A) {
		for (; monsterIt != MONSTERS.end() && monsterIt->first.first < it.first; monsterIt++) {
			int y = monsterIt->first.second;
			ll v = monsterIt->second;
			seg[y+S].sumMonster += v;
			updateAll(y+S);
		}
		ll cnd = seg[1].bestProfit - it.second;
		ans = max(ans, cnd);
	}
	cout << ans << '\n';

	return 0;
}