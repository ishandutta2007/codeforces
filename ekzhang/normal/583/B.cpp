#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

int N;
int ar[MAXN];
bool hacked[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ar[i];
	}

	int c = 0;
	int t = 0;
	for (int d = 1; ; d = -d) {
		if (d == 1) {
			for (int i = 0; i < N; i++) {
				if (!hacked[i] && ar[i] <= c) {
					c++;
					hacked[i] = true;
				}
			}
		}
		if (d == -1) {
			for (int i = N - 1; i >= 0; i--) {
				if (!hacked[i] && ar[i] <= c) {
					c++;
					hacked[i] = true;
				}
			}
		}

		if (c == N) {
			break;
		}
		t++;
	}

	cout << t << endl;
	return 0;
}