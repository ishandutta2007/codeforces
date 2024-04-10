#include <bits/stdc++.h>
using namespace std;

namespace SEG {
	int T[1 << 20];
	void pushup(int now) {
		T[now] = max(T[now << 1], T[now << 1 | 1]);
	}
	void Build(int now, int l, int r, int *a) {
		if (l == r) {
			T[now] = a[l];
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid, a), Build(now << 1 | 1, mid + 1, r, a);
		pushup(now);
	}
	void Modify(int now, int l, int r, int p, int x) {
		if (l == r) {
			T[now] = x;
			return ;
		}
		int mid = l + r >> 1;
		if (p <= mid) Modify(now << 1, l, mid, p, x);
		else Modify(now << 1 | 1, mid + 1, r, p, x);
		pushup(now);
	}
	int Query(int now, int l, int r, int L, int R) {
		if (now == 1) {
			L = max(L, l), R = min(R, r);
			if (L > R) return -1;
		}
		if (l == L && r == R) return T[now];
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
		return max(Query(now << 1, l, mid, L, mid), Query(now << 1 | 1, mid + 1, r, mid + 1, R));
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		static char s[200010]; scanf("%s", s);
		static int sum[200010];
		static int pos[400010]; for (int i = 0; i <= n + n; i++) pos[i] = -1;
		static set <int> S; S.clear();
		int cnt = 0; for (int i = 0; i < n; i++) cnt += s[i] == '0';
		if (cnt * 2 < n) {
			; for (int i = 0; i < n; i++) s[i] = s[i] == '0' ? '1' : '0'; reverse(s, s + n);
		}
		; for (int i = 0; i < n; i++) sum[i] = (i ? sum[i - 1] : 0) + (s[i] == '1' ? 1 : -1);
		; for (int i = 0; i < n; i++) pos[sum[i] + n] = i;
		; for (int i = 0; i <= n + n; i++) if (pos[i] != -1) S.insert(i);
		SEG :: Build(1, 0, n + n, pos);
		int cur = 0; while (cur < n && s[cur] == '0') cur++;
		if (cur == n) {
			printf("%d\n", 0);
			continue;
		}
		int ans = 0;
		int nxt = 0;
		auto AddNxt = [&]() -> void {
			if (pos[sum[nxt] + n] == nxt) {
				pos[sum[nxt] + n] = -1, SEG :: Modify(1, 0, n + n, sum[nxt] + n, -1), S.erase(sum[nxt] + n);
			}
			nxt++;
		};
		while (nxt < n && s[nxt] == '0') AddNxt();
		while (nxt < n && s[nxt] == '1') AddNxt();
		while (nxt < n) {
			// int nxt = cur, sum = 0; while (nxt < n && s[nxt] == '1') nxt++, sum++;
			// if (nxt == n) break;
			int C = -sum[nxt - 1] + nxt - cur;
			int minj = 0x3f3f3f3f, p = -1;
			// {
			// 	auto it = S.upper_bound(-C + n);
			// 	if (it != S.begin()) {
			// 		it--;
			// 		int val = -(*it - n) - C, cho = pos[*it];
			// 		if (val < minj || val == minj && cho > p) minj = val, p = cho;
			// 	}
			// }
			{
				auto it = S.lower_bound(-C + cur + n);
				if (it != S.end()) {
					int val = (*it - n) + C - cur, cho = pos[*it];
					if (val < minj || val == minj && cho > p) minj = val, p = cho;
				}
			}
			{
				int val = 0, cho = SEG :: Query(1, 0, n + n, -C + n, -C + cur + n);
				if (cho != -1) {
					if (val < minj || val == minj && cho > p) minj = val, p = cho;
				}
			}
			// for (int i = nxt; i < n; i++) {
			// 	int real = sum[i] + C < 0 ? -sum[i] - C : max(0, sum[i] + C - cur);
			// 	if (real <= minj) minj = real, p = i;
			// }
			ans += minj + 1;
			while (nxt <= p) {
				if (s[nxt] == '1') AddNxt();
				else swap(s[cur], s[nxt]), cur++, AddNxt();
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}