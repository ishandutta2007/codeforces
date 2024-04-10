#include <bits/stdc++.h>
using namespace std;

void Print(char *s, int *cut) {
	int n = strlen(s + 1);
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		if (cut[i]) tot++;
	}
	printf("%d\n", tot);
	int lst = 1;
	for (int i = 1; i <= n; i++) {
		if (cut[i]) printf("%d %d\n", lst, i), lst = i + 1;
	}
}

vector <int> Solve(const vector <int> &a) {
	if (a == vector <int>{4}) return {4};
	if (a == vector <int>{1, 3}) return {1, 4};
	if (a == vector <int>{3, 1}) return {4, 1};
	if (a == vector <int>{2, 2}) return {1, 3, 1, 1};
	if (a == vector <int>{8}) return {8};
	if (a == vector <int>{2, 6}) return {1, 2, 2, 2, 3};
	if (a == vector <int>{6, 2}) return {2, 2, 3, 1, 2};
	if (a == vector <int>{3, 5}) return {1, 3, 2, 2, 2};
	if (a == vector <int>{5, 3}) return {2, 2, 2, 1, 3};
	if (a == vector <int>{2, 3, 3}) return {1, 2, 4, 4};
	if (a == vector <int>{3, 2, 3}) return {4, 1, 2, 4};
	if (a == vector <int>{3, 3, 2}) return {4, 4, 1, 2};
	assert(0);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		static char s[1000010]; scanf("%s", s + 1);
		static int cut[1000010];
		goto TRY;
		BAD:;
		{
			int n = strlen(s + 1);
			555; for (int i = 1; i <= n; i++) cut[i] = 0;
			cut[n] = 1;
			while (n && s[n] == '0') n--;
			static vector <int> a; a.clear();
			cut[n] = 1;
			for (int i = 1; i < n; i++) {
				if (s[i] == '0') continue;
				int j = i; while (j < n && s[j] == '1') j++;
				a.push_back(j - i), i = j - 1;
			}
			vector <int> sol = Solve(a);
			int pos = 0;
			for (int i = 1; i < n; i++) {
				if (s[i] == '0') continue;
				int j = i; while (j < n && s[j] == '1') j++;
				int k = i; while (k < j) cut[k + sol[pos] - 1] = 1, k += sol[pos], pos++;
				i = j - 1;
			}
			Print(s, cut);
			continue;
		}
		TRY:;
		int n = strlen(s + 1);
		555; for (int i = 1; i <= n; i++) cut[i] = 0;
		cut[n] = 1;
		while (n && s[n] == '0') n--;
		if (n == 0) {
			printf("-1\n");
			continue;
		}
		static vector <int> one, three; one.clear(), three.clear();
		int sum = 0, tot = 0; for (int i = 1; i < n; i++) tot += s[i] == '1';
		cut[n] = 1;
		for (int i = 1; i < n; i++) {
			if (s[i] == '0') continue;
			int j = i; while (j < n && s[j] == '1') j++;
			int k = i; while (k + 2 < j) sum += 7, three.push_back(k), cut[k + 2] = 1, k += 3;
			if (k == j) {
				while (k < n && s[k] == '0') cut[k] = 1, k++;
			} else if (k + 1 == j) {
				sum += 2, one.push_back(k);
				cut[k + 1] = 1, k += 2;
				while (k < n && s[k] == '0') cut[k] = 1, k++;
			} else {
				sum += 6, three.push_back(k);
				cut[k + 2] = 1, k += 3;
				while (k < n && s[k] == '0') cut[k] = 1, k++;
			}
			i = j - 1;
		}
		int tar = 0; while (tar < tot) tar = tar << 1 | 1;
		int need = sum - tar;
		assert(need >= 0);
		while (need > 0) {
			if (need >= 3 && three.size()) {
				int x = three.back(); three.pop_back();
				cut[x + 1] = 1, need -= 3;
				one.push_back(x);
				continue;
			}
			if (need >= 1 && one.size()) {
				int x = one.back(); one.pop_back();
				cut[x] = 1, need--;
				continue;
			}
			goto BAD;
		}
		Print(s, cut);
	}
	return 0;
}