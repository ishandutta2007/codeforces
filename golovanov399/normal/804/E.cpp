#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
    inline int pidorand() {
        return ((rand() & 32767) << 15) | (rand() & 32767);
    }
    #define rand pidorand
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

bool check(int n, const vector<pair<int, int>>& a) {
	vector<vector<char>> used(n, vector<char>(n, 0));
	if (a.size() != n * (n - 1) / 2) {
		return false;
	}
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		p[i] = i;
	}
	auto lol = p;
	for (auto q : a) {
		swap(p[q.first], p[q.second]);
		if (q.first > q.second) {
			swap(q.first, q.second);
		} else if (q.first == q.second) {
			return false;
		}
		if (used[q.first][q.second]) {
			return false;
		}
		used[q.first][q.second] = 1;
	}
	return p == lol;
}

void add(vector<pair<int, int>>& ans, int s1, int s2) {
	s1 *= 4;
	s2 *= 4;
	for (int i = 0; i < 4; ++i) {
		ans.push_back({s1 + i, s2 + i});
	}
	for (int i = 0; i < 4; ++i) {
		ans.push_back({s1 + i, s2 + (i ^ 1)});
	}
	for (int i = 0; i < 4; ++i) {
		ans.push_back({s1 + i, s2 + (i ^ 2)});
	}
	for (int i = 0; i < 4; ++i) {
		ans.push_back({s1 + i, s2 + (i ^ 3)});
	}
}

void add4(vector<pair<int, int>>& ans, int s) {
	s *= 4;
	// 1 <--> 2
	// 1 <--> 3
	// 2 <--> 4
	// 1 <--> 4
	// 2 <--> 3
	// 3 <--> 4
	ans.push_back({s + 0, s + 1});
	ans.push_back({s + 0, s + 2});
	ans.push_back({s + 1, s + 3});
	ans.push_back({s + 0, s + 3});
	ans.push_back({s + 1, s + 2});
	ans.push_back({s + 2, s + 3});
}

vector<pair<int, int>> make4(int n) {
	vector<pair<int, int>> ans;
	for (int i = 0; i < n / 4; ++i) {
		add4(ans, i);
	}
	for (int i = 0; i < n / 4; ++i) {
		for (int j = 0; j < i; ++j) {
			add(ans, j, i);
		}
	}
	return ans;
}

int main(){
	int n = nxt();
	vector<pair<int, int>> ans;
	if (n % 4 == 0) {
		ans = make4(n);
	} else if (n % 4 == 1) {
		auto tmp = make4(n - 1);
		for (auto p : tmp) {
			int x = p.first, y = p.second;
			if (x > y) {
				swap(x, y);
			}
			if (y == x + 1 && x % 2 == 0) {
				ans.push_back({n - 1, x});
				ans.push_back({x, y});
				ans.push_back({n - 1, y});
			} else {
				ans.push_back(p);
			}
		}
	} else {
		printf("NO\n");
		return 0;
	}

	// assert(check(n, ans));
	printf("YES\n");
	for (auto p : ans) {
		if (p.first > p.second) {
			swap(p.first, p.second);
		}
		printf("%d %d\n", p.first + 1, p.second + 1);
	}

	return 0;
}