#include <bits/stdc++.h>
using namespace std;

vector <int> all[1 << 3];
vector <int> ans;
int cnt[26][3];

void Match(vector <int> &a, vector <int> &b, int t = 0x3f3f3f3f) {
	while (t && a.size() && b.size()) {
		ans.push_back(a.back() * 26 + b.back());
		a.pop_back(), b.pop_back(), t--;
	}
}

string s[3];

int main() {
	int sz[3] = {0, 0, 0};
	for (int it = 0; it < 3; it++) {
		static char buf[1010];
		scanf("%s", buf);
		s[it] = buf;
		int n = strlen(buf);
		sz[it] = n;
		for (int i = 0; i < n; i++) {
			cnt[buf[i] - 'A'][it]++;
		}
	}
	int lim = min(sz[0], min(sz[1], sz[2]));
	for (int i = 0; i < 26; i++) {
		int pa = 0, pb = 0, pc = 0;
		for (int a = 0; a <= min(cnt[i][1], cnt[i][2]); a++) {
			cnt[i][1] -= a, cnt[i][2] -= a;
			for (int b = 0; b <= min(cnt[i][2], cnt[i][0]); b++) {
				cnt[i][2] -= b, cnt[i][0] -= b;
				int c = min(cnt[i][0], cnt[i][1]);
				if (a + b + c > lim || pa + pb + pc < a + b + c) pa = a, pb = b, pc = c;
				cnt[i][2] += b, cnt[i][0] += b;
			}
			cnt[i][1] += a, cnt[i][2] += a;
		}
		while (pa + pb + pc > lim) pc > 0 ? pc-- : pb > 0 ? pb-- : pa--;
		lim -= pa + pb + pc;
		cnt[i][1] -= pa, cnt[i][2] -= pa, cnt[i][2] -= pb, cnt[i][0] -= pb, cnt[i][0] -= pc, cnt[i][1] -= pc;
		while (pa--) all[6].push_back(i);
		while (pb--) all[5].push_back(i);
		while (pc--) all[3].push_back(i);
		while (cnt[i][0]--) all[1].push_back(i);
		while (cnt[i][1]--) all[2].push_back(i);
		while (cnt[i][2]--) all[4].push_back(i);
	}
	Match(all[1], all[6]), Match(all[2], all[5]), Match(all[3], all[4]);
	{
		vector <vector <int> *> a = {&all[1], &all[2], &all[4]};
		sort(a.begin(), a.end(), [&](vector <int> *x, vector <int> *y) -> bool {return x->size() < y->size();});
		if (a[2]->size() >= a[0]->size() + a[1]->size()) {
			Match(*a[0], *a[2]), Match(*a[1], *a[2]);
		} else {
			int tot = a[0]->size() + a[1]->size() + a[2]->size();
			while (tot > 1) {
				Match(*a[1], *a[2], 1);
				sort(a.begin(), a.end(), [&](vector <int> *x, vector <int> *y) -> bool {return x->size() < y->size();});
				tot -= 2;
			}
		}
	}
	for (int i = 0; i < 8; i++) {
		while (all[i].size()) ans.push_back(all[i].back() * 26 + all[i].back()), all[i].pop_back();
	}
	printf("%d\n", (int)ans.size());
	for (auto it : ans) {
		printf("%c%c\n", (char)('A' + it / 26), (char)('A' + it % 26));
	}
	return 0;
}