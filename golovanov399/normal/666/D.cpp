#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

bool ok(const vector<pair<int, int>>& a){
	for (int i = 0; i < 4; i++){
		int j = (i + 1) % 4;
		if (i % 2 == 0){
			if (a[j].second != a[i].second)
				return false;
		} else {
			if (a[j].first != a[i].first)
				return false;
		}
	}
	int r = abs(a[3].second - a[0].second);
	for (int i = 0; i < 3; i++){
		if (i % 2 == 0){
			if (abs(a[i].first - a[i + 1].first) != r)
				return false;
		} else {
			if (abs(a[i].second - a[i + 1].second) != r)
				return false;
		}
	}
	if (a[0].first <= a[1].first || a[1].second <= a[2].second || a[2].first >= a[3].first || a[3].second >= a[0].second)
		return false;
	return r > 0;
}

int med(vector<int> a){
	sort(all(a));
	return (a[0] + a.back()) / 2;
}

void solve(){
	vector<pair<int, int>> a(4);
	for (int i = 0; i < 4; i++){
		a[i].first = nxt();
		a[i].second = nxt();
	}

	vector<int> p(4);
	for (int i = 0; i < 4; i++){
		p[i] = i;
	}

	int ans = 1e9;
	vector<pair<int, int>> qw(4);

	do {
		for (int mask = 0; mask < 16; mask++){
			vector<char> hor(4);
			for (int i = 0; i < 4; i++){
				if (mask & (1 << i))
					hor[i] = true;
			}

			vector<char> stable(4);
			vector<pair<int, int>> pos(4);

			int cnt = 0;
			for (int i = 0; i < 4; i++){
				int j = (i + 1) % 4;
				if (hor[i] != hor[j]){
					cnt++;
					if (i % 2 == 0){
						if (hor[i]){
							stable[j] = 1;
							pos[j] = {a[p[j]].first, a[p[i]].second};
						} else {
							stable[i] = 1;
							pos[i] = {a[p[i]].first, a[p[j]].second};
						}
					} else {
						if (hor[i]){
							stable[i] = 1;
							pos[i] = {a[p[j]].first, a[p[i]].second};
						} else {
							stable[j] = 1;
							pos[j] = {a[p[i]].first, a[p[j]].second};
						}
					}
				}
			}

			// if (p == vector<int>({0, 2, 1, 3})){
			// 	cerr << cnt << "\n";
			// }

			if (cnt == 4){
				if (!ok(pos))
					continue;
				int d = 0;
				for (int i = 0; i < 4; i++){
					d = max(d, abs(pos[i].first - a[p[i]].first) + abs(pos[i].second - a[p[i]].second));
				}
				if (ans > d){
					ans = d;
					for (int i = 0; i < 4; i++){
						qw[p[i]] = pos[i];
					}
				}
			} else
			if (cnt == 2){
				if ((stable[0] && stable[2]) || (stable[1] && stable[3])){
					int i = 0;
					if (!stable[i])
						i++;
					if (abs(pos[i].first - pos[i + 2].first) != abs(pos[i].second - pos[i + 2].second) || pos[i] == pos[i + 2])
						continue;
					if (i == 0){
						if (hor[i])
							continue;
						pos[i + 1] = {pos[i + 2].first, pos[i].second};
						pos[i + 3] = {pos[i].first, pos[i + 2].second};
					} else {
						if (hor[i])
							continue;
						pos[i - 1] = {pos[i + 2].first, pos[i].second};
						pos[i + 1] = {pos[i].first, pos[i + 2].second};
					}
					if (!ok(pos))
						continue;
					bool ook = 1;
					for (int i = 0; i < 4; i++){
						if (pos[i].first != a[p[i]].first && pos[i].second != a[p[i]].second)
							ook = 0;
					}
					if (!ook)
						continue;
					int r = 0;
					for (int i = 0; i < 4; i++){
						r = max(r, abs(pos[i].first - a[p[i]].first) + abs(pos[i].second - a[p[i]].second));
					}
					if (r < ans){
						ans = r;
						for (int i = 0; i < 4; i++)
							qw[p[i]] = pos[i];
					}
				} else {
					int i = 0;
					while (!stable[i] || !stable[(i + 1) % 4])
						i++;
					if (i == 0){
						int r = pos[0].first - pos[1].first;
						if (r <= 0)
							continue;
						pos[2] = {pos[1].first, pos[1].second - r};
						pos[3] = {pos[0].first, pos[0].second - r};
					} else
					if (i == 1){
						int r = pos[1].second - pos[2].second;
						if (r <= 0)
							continue;
						pos[0] = {pos[1].first + r, pos[1].second};
						pos[3] = {pos[2].first + r, pos[2].second};
					} else
					if (i == 2){
						int r = pos[3].first - pos[2].first;
						if (r <= 0)
							continue;
						pos[0] = {pos[3].first, pos[3].second + r};
						pos[1] = {pos[2].first, pos[2].second + r};
					} else {
						int r = pos[0].second - pos[3].second;
						if (r <= 0)
							continue;
						pos[1] = {pos[0].first - r, pos[0].second};
						pos[2] = {pos[3].first - r, pos[3].second};
					}

					if (!ok(pos))
						continue;

					bool ook = 1;
					for (int i = 0; i < 4; i++){
						if (pos[i].first != a[p[i]].first && pos[i].second != a[p[i]].second)
							ook = 0;
					}
					if (!ook)
						continue;
					int r = 0;
					for (int i = 0; i < 4; i++){
						r = max(r, abs(pos[i].first - a[p[i]].first) + abs(pos[i].second - a[p[i]].second));
					}
					if (r < ans){
						ans = r;
						for (int i = 0; i < 4; i++)
							qw[p[i]] = pos[i];
					}
				}
			} else
			if (cnt == 0){
				if (hor[0]){
					if (a[p[0]].second != a[p[1]].second || a[p[2]].second != a[p[3]].second)
						continue;
					int r = a[p[0]].second - a[p[3]].second;
					if (r <= 0)
						continue;
					vector<itn> qq({a[p[0]].first, a[p[1]].first + r, a[p[2]].first + r, a[p[3]].first});
					int x = med(qq);
					pos[0] = {x, a[p[0]].second};
					pos[1] = {x - r, a[p[1]].second};
					pos[2] = {x - r, a[p[2]].second};
					pos[3] = {x, a[p[3]].second};
					if (!ok(pos))
						continue;

					r = 0;
					for (int i = 0; i < 4; i++){
						r = max(r, abs(pos[i].first - a[p[i]].first) + abs(pos[i].second - a[p[i]].second));
					}
					if (r < ans){
						ans = r;
						for (int i = 0; i < 4; i++)
							qw[p[i]] = pos[i];
					}
				} else {
					if (a[p[1]].first != a[p[2]].first || a[p[3]].first != a[p[0]].first)
						continue;
					int r = a[p[0]].first - a[p[1]].first;
					if (r <= 0)
						continue;
					vector<itn> qq({a[p[0]].second, a[p[1]].second, a[p[2]].second + r, a[p[3]].second + r});
					int x = med(qq);
					pos[0] = {a[p[0]].first, x};
					pos[1] = {a[p[1]].first, x};
					pos[2] = {a[p[2]].first, x - r};
					pos[3] = {a[p[3]].first, x - r};
					if (!ok(pos))
						continue;

					r = 0;
					for (int i = 0; i < 4; i++){
						r = max(r, abs(pos[i].first - a[p[i]].first) + abs(pos[i].second - a[p[i]].second));
					}
					if (r < ans){
						ans = r;
						for (int i = 0; i < 4; i++)
							qw[p[i]] = pos[i];
					}
				}
			} else {
				assert(false);
			}
		}
	} while (next_permutation(all(p)));

	if (ans > 1e9 - 10){
		puts("-1");
	} else {
		printf("%d\n", ans);
		for (auto p : qw){
			printf("%d %d\n", p.first, p.second);
		}
	}
}

int main(){

	int T = nxt();
	while (T--){
		solve();
	}

	return 0;
}