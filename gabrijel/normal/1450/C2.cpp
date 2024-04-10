#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int maxn = 310;

int smjx[] = {0, 1, 0, -1};
int smjy[] = {1, 0, -1, 0};

int n;
char mat[maxn][maxn];
char pom[maxn][maxn];
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

bool provjeri(int x, int y) {
	if(x >= 2) if(pom[x][y] == pom[x - 1][y] && pom[x][y] == pom[x - 2][y]) return 0;
	if(x >= 1 && x + 1 < n) if(pom[x][y] == pom[x - 1][y] && pom[x][y] == pom[x + 1][y]) return 0;
	if(x < n - 2) if(pom[x][y] == pom[x + 1][y] && pom[x][y] == pom[x + 2][y]) return 0;
	if(y >= 2) if(pom[x][y] == pom[x][y - 1] && pom[x][y] == pom[x][y - 2]) return 0;
	if(y >= 1 && y + 1 < n) if(pom[x][y] == pom[x][y - 1] && pom[x][y] == pom[x][y + 1]) return 0;
	if(y < n - 2) if(pom[x][y] == pom[x][y + 1] && pom[x][y] == pom[x][y + 2]) return 0;
	return 1;
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
		REP(i, n) REP(j, n) pom[i][j] = mat[i][j];
		memset(bio, 0, sizeof bio);
		REP(i, n) {
			REP(j, n) {
				if(mat[i][j] != '.' && !bio[i][j]) {
					tr.clear();
					ff(i, j);
					int mini = n * n, mink, minl;
					int obr = 0;
					REP(k, 3) {
						REP(l, 3) {
							int tr_b = 0;
							for(pair <int, int> tr_p : tr) {
								if(mat[tr_p.first][tr_p.second] == 'X') {
									if((tr_p.first + tr_p.second) % 3 == k) {
										pom[tr_p.first][tr_p.second] = 'O';
										tr_b++;
									}
								}
								else {
									if((tr_p.first + tr_p.second) % 3 == l) {
										pom[tr_p.first][tr_p.second] = 'X';
										tr_b++;
									}
								}
							}
							bool ok = 1;
							for(pair <int, int> tr_p : tr) {
								if(!provjeri(tr_p.first, tr_p.second)) {
									ok = 0;
									break;
								}
							}
							if(ok && tr_b < mini) {
								mini = tr_b;
								mink = k;
								minl = l;
								obr = 0;
							}
							for(pair <int, int> tr_p : tr) {
								pom[tr_p.first][tr_p.second] = mat[tr_p.first][tr_p.second];
							}
							//
							tr_b = 0;
							for(pair <int, int> tr_p : tr) {
								if(mat[tr_p.first][tr_p.second] == 'X') {
									if((tr_p.first + tr_p.second) % 3 == k) {
										pom[tr_p.first][tr_p.second] = 'O';
										tr_b++;
									}
								}
								else {
									if((tr_p.first - tr_p.second) % 3 == l) {
										pom[tr_p.first][tr_p.second] = 'X';
										tr_b++;
									}
								}
							}
							ok = 1;
							for(pair <int, int> tr_p : tr) {
								if(!provjeri(tr_p.first, tr_p.second)) {
									ok = 0;
									break;
								}
							}
							if(ok && tr_b < mini) {
								mini = tr_b;
								mink = k;
								minl = l;
								obr = 1;
							}
							for(pair <int, int> tr_p : tr) {
								pom[tr_p.first][tr_p.second] = mat[tr_p.first][tr_p.second];
							}
							//
							tr_b = 0;
							for(pair <int, int> tr_p : tr) {
								if(mat[tr_p.first][tr_p.second] == 'X') {
									if((tr_p.first - tr_p.second) % 3 == k) {
										pom[tr_p.first][tr_p.second] = 'O';
										tr_b++;
									}
								}
								else {
									if((tr_p.first + tr_p.second) % 3 == l) {
										pom[tr_p.first][tr_p.second] = 'X';
										tr_b++;
									}
								}
							}
							ok = 1;
							for(pair <int, int> tr_p : tr) {
								if(!provjeri(tr_p.first, tr_p.second)) {
									ok = 0;
									break;
								}
							}
							if(ok && tr_b < mini) {
								mini = tr_b;
								mink = k;
								minl = l;
								obr = 2;
							}
							for(pair <int, int> tr_p : tr) {
								pom[tr_p.first][tr_p.second] = mat[tr_p.first][tr_p.second];
							}
							//
							tr_b = 0;
							for(pair <int, int> tr_p : tr) {
								if(mat[tr_p.first][tr_p.second] == 'X') {
									if((tr_p.first - tr_p.second) % 3 == k) {
										pom[tr_p.first][tr_p.second] = 'O';
										tr_b++;
									}
								}
								else {
									if((tr_p.first - tr_p.second) % 3 == l) {
										pom[tr_p.first][tr_p.second] = 'X';
										tr_b++;
									}
								}
							}
							ok = 1;
							for(pair <int, int> tr_p : tr) {
								if(!provjeri(tr_p.first, tr_p.second)) {
									ok = 0;
									break;
								}
							}
							if(ok && tr_b < mini) {
								mini = tr_b;
								mink = k;
								minl = l;
								obr = 4;
							}
							for(pair <int, int> tr_p : tr) {
								pom[tr_p.first][tr_p.second] = mat[tr_p.first][tr_p.second];
							}
						}
					}
					//cout << mink << " " << minl << endl;
					for(pair <int, int> tr_p : tr) {
						if(mat[tr_p.first][tr_p.second] == 'X') {
							if(obr == 0 || obr == 1) {
								if((tr_p.first + tr_p.second) % 3 == mink) {
									mat[tr_p.first][tr_p.second] = 'O';
								}
							}
							else {
								if((tr_p.first - tr_p.second) % 3 == mink) {
									mat[tr_p.first][tr_p.second] = 'O';
								}
							}
						}
						else {
							if(obr == 0 || obr == 2) {
								if((tr_p.first + tr_p.second) % 3 == minl) {
									mat[tr_p.first][tr_p.second] = 'X';
								}
							}
							else {
								if((tr_p.first - tr_p.second) % 3 == minl) {
									mat[tr_p.first][tr_p.second] = 'X';
								}
							}
						}
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