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

int main(){

	string s;
	cin >> s;
	int x = 0, y = 0;
	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < i; j++) {
			if (s[i] == s[j]) {
				x = i, y = j;
			}
		}
	}

	if (x == y + 1) {
		puts("Impossible");
		return 0;
	}

	string ans[2];
	for (int i = 0; i < 2; i++) {
		ans[i] = string(13, 'A');
	}

	int num = (x - y - 1) / 2;
	int X = 1, Y = num;
	for (int i = y; i < x; i++) {
		ans[X][Y] = s[i];
		if (X == 1) {
			if (Y == 0) {
				X -= 1;
			} else {
				Y -= 1;
			}
		} else {
			if (Y == 12) {
				X += 1;
			} else {
				Y += 1;
			}
		}
	}
	for (int i = (x + 1) % 27; i != y; i = (i + 1) % 27) {
		ans[X][Y] = s[i];
		if (X == 1) {
			if (Y == 0) {
				X -= 1;
			} else {
				Y -= 1;
			}
		} else {
			if (Y == 12) {
				X += 1;
			} else {
				Y += 1;
			}
		}
	}
	cout << ans[0] << "\n" << ans[1] << "\n";

	return 0;
}