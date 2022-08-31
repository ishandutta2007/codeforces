#include<bits/stdc++.h>
using namespace std;

const int MAXN = 600;
const int MAXM = 600;
int N, M;
map<int, int> mp[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int a; cin >> a;
			mp[i][a] = j;
		}
	}
	int v = 0;
	for (int i = 1; i <= N; i++) {
		v ^= mp[i].begin()->first;
	}
	if (v == 0) {
		for (int i = 1; i <= N; i++) {
			if (mp[i].size() >= 2) {
				v ^= mp[i].begin()->first;
				mp[i].erase(mp[i].begin());
				v ^= mp[i].begin()->first;
				assert(v != 0);
				break;
			}
		}
	}
	if (v == 0) {
		cout << "NIE\n";
	} else {
		cout << "TAK\n";
		for (int i = 1; i <= N; i++) {
			cout << mp[i].begin()->second << " \n"[i==N];
		}
	}

	return 0;
}