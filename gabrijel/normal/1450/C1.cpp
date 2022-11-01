#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int maxn = 310;

int smjx[] = {0, 1, 0, -1};
int smjy[] = {1, 0, -1, 0};

int n;
char mat[maxn][maxn];
bool bio[maxn][maxn];
vector <pair <int, int> > tr;

void ff(int x, int y) {
	tr.push_back(make_pair(x, y));
	bio[x][y] = 1;
	REP(i, 4) {
		int nx = x + smjx[i], ny = y + smjy[i];
		if(nx >= 0 && ny >= 0 && nx < n && ny < n && mat[nx][ny] != '.' && !bio[nx][ny]) ff(nx, ny);
	}
	return;
}

int main() {
	int t;
	scanf("%d", &t);
	REP(tt, t) {
		scanf("%d", &n);
		int cnt = 0;
		REP(i, n) {
			scanf("%s", mat[i]);
			REP(j, n) cnt += mat[i][j] != '.';
		}
		memset(bio, 0, sizeof bio);
		REP(i, n) {
			REP(j, n) {
				if(mat[i][j] != '.' && !bio[i][j]) {
					tr.clear();
					ff(i, j);
					int mini = n * n, mink;
					REP(k, 3) {
						int tr_b = 0;
						for(pair <int, int> tr_p : tr) {
							if((tr_p.first + tr_p.second) % 3 == k) tr_b++;
						}
						if(tr_b < mini) {
							mini = tr_b;
							mink = k;
						}
					}
					for(pair <int, int> tr_p : tr) {
						if((tr_p.first + tr_p.second) % 3 == mink) mat[tr_p.first][tr_p.second] = 'O';
					}
				}
			}
		}
		REP(i, n) {
			printf("%s\n", mat[i]);
		}
	}
	return 0;
}