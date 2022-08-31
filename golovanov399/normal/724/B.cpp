#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

bool ok(const vector<int>& a, const vector<int>& b) {
	int cnt = 0;
	for (itn i = 0; i < (int)a.size(); i++) {
		if (a[i] != b[i]) {
			cnt++;
		}
	}
	return cnt <= 2;
}

int main(){

	int n = nxt(), m = nxt();
	vector<vector<int>> a(n);
	for (int i = 0; i < n; i++) {
		a[i].resize(m);
		for (int j = 0; j < m; j++) {
			a[i][j] = nxt();
		}
	}

	vector<int> id(m);
	for (itn i = 0; i < m; i++) {
		id[i] = i + 1;
	}

	for (int x = 0; x < m; x++) {
		for (int y = 0; y < x; y++) {
			swap(id[x], id[y]);
			bool cock = true;
			for (int i = 0; cock && i < n; i++) {
				cock &= ok(a[i], id);
			}
			if (cock) {
				puts("YES");
				return 0;
			}
			swap(id[x], id[y]);
		}
	}
	bool cock = true;
	for (int i = 0; cock && i < n; i++) {
		cock &= ok(a[i], id);
	}
	if (cock) {
		puts("YES");
		return 0;
	}

	puts("NO");

	return 0;
}