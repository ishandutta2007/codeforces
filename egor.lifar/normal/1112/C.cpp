#include <bits/stdc++.h>

using namespace std;
template<class T1, class T2> inline void chkmin(T1 &x, T2 const &y) {if (x > y) x = y;}
template<class T1, class T2> inline void chkmax(T1 &x, T2 const &y) {if (x < y) x = y;}
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define mp make_pair
#define left left228
#define right right228
const int MAXN  = 500228;


int m, k, n, s;
int a[MAXN];
int b[MAXN];
int need[MAXN];
int bad = 0;
int cnt[MAXN];

void add(int x) {
	cnt[x]++;
	if (cnt[x] == need[x]) {
		bad--;
	}
}


void del(int x) {
	if (cnt[x] == need[x]) {
		bad++;
	}
	cnt[x]--;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	cin >> m >> k >> n >> s;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < s; i++) {
		cin >> b[i];
		need[b[i]]++;
	}
	for (int i = 1; i <= 500000; i++) {
		if (need[i]) {
			bad++;
		}
	}
	int uk = -1;
	for (int i = 0; i < m; i++) {
		while (bad && uk + 1 < m) {
			uk++;
			add(a[uk]);
		}
		if (bad) {
			break;
		}
		int cnt = i % k;
		int cnt1 = max(0, (uk - i + 1) - k);
		if (cnt1 == 0) {
			int f = k - (uk - i + 1);
			cnt -= f;
			chkmax(cnt, 0);
		}
		if (m - cnt - cnt1 >= n * k) {
			cout << cnt + cnt1 << '\n';
			for (int j = 0; j < cnt; j++) {
				cout << j + 1 << ' ';
			}
			for (int j = i; j <= uk && cnt1; j++) {
				if (need[a[j]] == 0) {
					cout << j + 1 << ' ';
					cnt1--;
				} else {
					need[a[j]]--;
				}
 			}
 			cout << '\n';
 			return 0;
		}
		del(a[i]);
	}
	cout << -1 << endl;
	return 0;
}