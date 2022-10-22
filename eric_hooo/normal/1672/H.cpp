#include <bits/stdc++.h>
using namespace std;

const int B = 500;

int n, q;
char s[200010];
int L[200010], R[200010], seq[200010], ans[200010];

namespace DS {
	deque <int> a;
	deque <int> b;
	int cnt[4];
	void Init() {
		memset(cnt, 0, sizeof(cnt)), a.clear(), b.clear();
		a = {s[0] == '0' ? 0 : 3}, b = {1};
		cnt[a[0]]++;
	}
	void PushFront(int x) {
		if (x != a.front() % 2) cnt[a.front()]--, a.front() ^= 1, cnt[a.front()]++, b.front()++;
		else a.push_front(x ? 3 : 0), cnt[a.front()]++, b.push_front(1);
	}
	void PushBack(int x) {
		if (x != a.back() / 2) cnt[a.back()]--, a.back() ^= 2, cnt[a.back()]++, b.back()++;
		else a.push_back(x ? 3 : 0), cnt[a.back()]++, b.push_back(1);
	}
	void PopFront() {
		if (b.front() == 1) b.pop_front(), cnt[a.front()]--, a.pop_front();
		else b.front()--, cnt[a.front()]--, a.front() ^= 1, cnt[a.front()]++;
	}
	void PopBack() {
		if (b.back() == 1) b.pop_back(), cnt[a.back()]--, a.pop_back();
		else b.back()--, cnt[a.back()]--, a.back() ^= 2, cnt[a.back()]++;
	}
	int GetAns() {
		if (cnt[0] == cnt[3]) {
			int ans = abs(cnt[1] - cnt[2]);
			if (cnt[1] == cnt[2]) ans += 2;
			return ans;
		}
		int ans = abs(cnt[0] - cnt[3]) + abs(cnt[1] - cnt[2]);
		int beg = cnt[0] > cnt[3] ? 0 : 1;
		if (cnt[1] == cnt[2] && beg != a.front() % 2) ans += 2;
		return ans;
	}
}

namespace RNG {
	int l, r;
	void Init() {l = 1, r = 1, DS :: Init();}
	void Move(int L, int R) {
		while (l > L) DS :: PushFront(s[--l] - '0');
		while (r < R) DS :: PushBack(s[++r] - '0');
		while (l < L) DS :: PopFront(), l++;
		while (r > R) DS :: PopBack(), r--;
	}
	int GetAns() {return DS :: a.size() + DS :: GetAns() >> 1;}
}

int main() {
	scanf("%d%d", &n, &q);
	scanf("%s", s + 1);
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &L[i], &R[i]);
		seq[i] = i;
	}
	sort(seq, seq + q, [&](int x, int y) -> bool {return L[x] / B != L[y] / B ? L[x] < L[y] : R[x] < R[y];});
	RNG :: Init();
	for (int i = 0; i < q; i++) {
		int id = seq[i];
		RNG :: Move(L[id], R[id]);
		ans[id] = RNG :: GetAns();
	}
	for (int i = 0; i < q; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}