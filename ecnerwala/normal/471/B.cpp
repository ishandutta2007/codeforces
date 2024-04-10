#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5000;

typedef pair<int, int> pii;
#define A first
#define B second

int N;
pii V[MAXN];

int res[MAXN][3];
int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> V[i].A;
		V[i].B = i + 1;
	}
	sort(V, V + N);

	for(int i = 0; i < N; i++) {
		res[i][0] = res[i][1] = res[i][2] = V[i].B;
	}

	int cnt = 0;
	for(int i = 0; i + 1 < N; i++) {
		if(V[i].A == V[i + 1].A) {
			cnt++;
			swap(res[i][cnt], res[i + 1][cnt]);
			if(cnt == 2) break;
		}
	}
	if(cnt >= 2) {
		cout << "YES\n";
		for(int j = 0; j < 3; j++) {
			for(int i = 0; i < N; i++) {
				cout << res[i][j] << ' ';
			}
			cout << '\n';
		}
	} else {

		cout << "NO\n";
	}

	return 0;
}