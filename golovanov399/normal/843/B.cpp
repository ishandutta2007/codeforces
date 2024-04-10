#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	inline int aimteh_rand() {
		return pidorand() ^ (pidorand() + 2281488);
	}
	#define rand aimteh_rand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

pair<int, int> ask(int x) {
	cout << "? " << x << endl;
	pair<int, int> res;
	cin >> res.first >> res.second;
	return res;
}

void find_straight(int x, int pos) {
	while (pos > -1) {
		auto p = ask(pos);
		if (p.first >= x) {
			cout << "! " << p.first << endl;
			exit(0);
		}
		pos = p.second;
	}
	cout << "! " << -1 << endl;
}

#define random_shuffle govno_zalupa_penis_her

template <typename T>
void random_shuffle(T beg, T end) {
	while (beg != end) {
		auto it = beg + rand() % (end - beg);
		swap(*beg, *it);
		++beg;
	}
}

int main() {
	int n, start, need;
	cin >> n >> start >> need;

	vector<pair<int, int>> resps;
	int cnt = min(n, 1000);
	vector<int> perm(n);
	for (int i = 0; i < n; ++i) {
		perm[i] = i;
	}
	random_shuffle(all(perm));

	perm.resize(cnt);
	for (int x : perm) {
		resps.push_back(ask(x + 1));
	}

	int pos = start;
	int last_val = ask(start).first;

	for (int i = 0; i < cnt; ++i) {
		if (resps[i].first > last_val && resps[i].first < need) {
			pos = perm[i] + 1;
			last_val = resps[i].first;
		}
	}

	find_straight(need, pos);

	return 0;
}