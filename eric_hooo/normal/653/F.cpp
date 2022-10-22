#include <bits/stdc++.h>
using namespace std;

char s[500010];
int sa[500010], rnk[500010], tmp[500010], tp;
int sum[500010], height[500010];
int n;

bool cmp1(int a, int b) {
    return rnk[a] < rnk[b];
}

bool cmp(int a, int b, int k) {
    return tmp[a] != tmp[b] || (a + k < n ? tmp[a + k] : 0) != (b + k < n ? tmp[b + k] : 0);
}

void Qsort() {
    for (int i = 1; i <= 500000; i++) {
        sum[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        sum[rnk[tmp[i]]]++;
    }
    for (int i = 1; i <= 500000; i++) {
        sum[i] += sum[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        sa[--sum[rnk[tmp[i]]]] = tmp[i];
    }
}

void get_sa() {
    for (int i = 0; i < n; i++) {
        sa[i] = i, rnk[i] = s[i];
    }
    sort(sa, sa + n, cmp1);
    for (int k = 1; k <= n; k <<= 1) {
        tp = 0;
        for (int i = n - k; i < n; i++) {
            tmp[tp++] = i;
        }
        for (int i = 0; i < n; i++) {
            if (sa[i] >= k) tmp[tp++] = sa[i] - k;
        }
        Qsort();
        swap(tmp, rnk);
        rnk[sa[0]] = 1;
        for (int i = 1; i < n; i++) {
            rnk[sa[i]] = rnk[sa[i - 1]] + cmp(sa[i], sa[i - 1], k);
        }
    }
}

void get_height() {
	int h = 0;
	for (int i = 0; i < n; i++) {
		if (h) h--;
		if (rnk[i] == n) continue;
		int j = sa[rnk[i]];
		while (i + h < n && j + h < n && s[i + h] == s[j + h]) h++;
		height[rnk[i]] = h;
	}
}

vector <int> all[1000010];
int now[500010];
int f[500010][19];

int main () {
	scanf("%d", &n);
	scanf("%s", s);
	get_sa(), get_height();
	now[0] = 500000;
	for (int i = 0; i < n; i++) {
		all[now[i]].push_back(i);
		now[i + 1] = now[i] + (s[i] == '(' ? 1 : -1);
		f[i][0] = now[i];
	}
	for (int j = 1; j < 19; j++) {
		for (int i = 0; i <= n; i++) {
			if (i + (1 << j) - 1 > n) continue;
			f[i][j] = min(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
		}
	}
	all[now[n]].push_back(n);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int x = sa[i];
		int N = x + 1;
		for (int i = 18; i >= 0; i--) {
			if (f[N][i] >= now[x]) N += 1 << i;
		}
		int low = x + height[i + 1] + 1;
		if (N < low) continue;
		int ll = lower_bound(all[now[x]].begin(), all[now[x]].end(), low) - all[now[x]].begin();
		int rr = lower_bound(all[now[x]].begin(), all[now[x]].end(), N + 1) - all[now[x]].begin();
		ans += rr - ll;
	}
	printf("%I64d\n", ans);
	return 0;
}