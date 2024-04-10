#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define sorv(V) sort(allv(V))
#define revv(V) reverse(allv(V))
#define univ(V) (V).erase(unique(allv(V)),(V).end())
#define clv(V) (V).clear()
#define upmin(a,b) (a)=min((a),(b))
#define upmax(a,b) (a)=max((a),(b))
#define INF (0x3f3f3f3f)
#define INFLL (0x3f3f3f3f3f3f3f3fll)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char __carr[550055], *__pcarr=__carr;
bool __barr[550055], *__pbarr=__barr;
inline char* newchar(const unsigned int SZ) {
	__pcarr += SZ;
	return __pcarr - SZ;
}
inline void initchar() { __pcarr=__carr; }
inline bool* newbool(const unsigned int SZ) {
	__pbarr += SZ;
	return __pbarr - SZ;
}
inline void initbool() { __pbarr=__barr; }
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

char DB[5][5][37][4][4];

char *A[100005];
bool *chk[100005];

int T, H, W, N;

int countStars(int H, int W) {
	int ret = 0;
	for(int i = 1; i <= H; i++) for(int j = 1; j <= W; j++) {
		if('*' != A[i][j]) continue;
		if('*' == A[i+1][j] && '*' == A[i][j+1]) ret++;
		if('*' == A[i+1][j] && '*' == A[i][j-1]) ret++;
		if('*' == A[i-1][j] && '*' == A[i][j+1]) ret++;
		if('*' == A[i-1][j] && '*' == A[i][j-1]) ret++;
	}
	return ret;
}

void dfs(int y, int x) {
	chk[y][x] = true;
	for(int dr = 0; dr < 4; dr++) {
		int ny = y+dy[dr], nx = x+dx[dr];
		if('*' != A[ny][nx] || chk[ny][nx]) continue;
		dfs(ny, nx);
	}
}
bool isConnected(int H, int W) {
	initbool();
	for(int i = 0; i <= H+1; i++)
		chk[i] = newbool(W+2);
	for(int i = 0; i <= H+1; i++)
		fill(chk[i], chk[i]+W+2, false);
	
	bool flag = false;
	for(int i = 1; i <= H; i++) {
		for(int j = 1; j <= W; j++) {
			if('*' == A[i][j]) {
				flag = true;
				dfs(i, j);
				break;
			}
		}
		if(flag) break;
	}

	if(!flag) return false;

	for(int i = 1; i <= H; i++) for(int j = 1; j <= W; j++)
		if('*' == A[i][j] && !chk[i][j]) return false;
	return true;
}

void printAnswer(int H, int W) {
	initbool();
	for(int i = 0; i <= H+1; i++)
		chk[i] = newbool(W+2);
	for(int i = 0; i <= H+1; i++)
		fill(chk[i], chk[i]+W+2, false);
	
	dfs(1, 1);

	for(int i = 1; i <= H; i++) {
		for(int j = 1; j <= W; j++)
			putchar('*' == A[i][j] && chk[i][j] ? '*' : '.');
		puts("");
	}
}

int main() {
	for(int i = 0; i < 10; i++)
		A[i] = newchar(10);
	for(int h = 3; h <= 4; h++) for(int w = 3; w <= 4; w++) {
		for(int key = 0; key < (1<<(w*h)); key++) {
			for(int i = 0; i <= h+1; i++)
				fill(A[i], A[i]+w+2, '.');
			for(int i = 0; i < h; i++) for(int j = 0; j < w; j++)
				A[i+1][j+1] = (key & (1<<(i*w+j))) ? '*' : '.';
			int cnt = countStars(h, w);
			if(!isConnected(h, w)) continue;

			for(int i = 0; i < h; i++) for(int j = 0; j < w; j++)
				DB[h][w][cnt][i][j] = A[i+1][j+1];
		}
	}

	scanf("%d", &T);
	for(int ti = 0; ti < T; ti++) {
		if(ti) puts("");
		scanf("%d%d%d", &H, &W, &N);
		if((H-1)*(W-1)*4 < N) {
			puts("-1");
			continue;
		}
		if(H <= 4 && W <= 4) {
			if(!DB[H][W][N][0][0]) {
				puts("-1");
				continue;
			}
			for(int i = 0; i < H; i++) {
				for(int j = 0; j < W; j++) {
					putchar(DB[H][W][N][i][j]);
				}
				puts("");
			}
			continue;
		}

		if((H-1) * (W-2) * 4 == N) {
			for(int i = 1; i <= H; i++) {
				for(int j = 1; j < W; j++)
					putchar('*');
				puts(".");
			}
			continue;
		}
		
		if((H-2) * (W-1) * 4 == N) {
			for(int i = 1; i < H; i++) {
				for(int j = 1; j <= W; j++)
					putchar('*');
				puts("");
			}
			for(int j = 1; j <= W; j++)
				putchar('.');
			puts("");
			continue;
		}

		initchar();
		for(int i = 0; i <= H+1; i++) {
			A[i] = newchar(W+2);
			fill(A[i], A[i]+W+2, '.');
		}

		bool flag = false;
		int cnt = 0;
		for(int i = 1; i <= W; i++) A[1][i] = '*';
		for(int i = 2; i <= H; i++) {
			for(int j = 1; j <= W; j++) {
				int ll = i < H ? min(4, W) : 0;
				for(int nkey = 0; nkey < (1<<ll); nkey++) {
					for(int k = 0; k < ll; k++)
						A[i+1][k+1] = (nkey & (1<<k)) ? '*' : '.';

					int l = min(4, W-j+1);
					for(int key = 0; key < (1<<l); key++) {
						int sum = cnt, nsum = 0;
						bool iscon = true, niscon = true;

						for(int k = 0; k < l; k++)
							A[i][j+k] = (key & (1<<k)) ? '*' : '.';
						for(int k = 0; k < l; k++) if(key & (1<<k)) {
							if('*' == A[i-1][j+k]) {
								if('*' == A[i-1][j+k-1]) sum++;
								if('*' == A[i][j+k-1]) sum++;
								if('*' == A[i-1][j+k+1]) sum++;
							}
							if('*' == A[i][j+k-1] && '*' == A[i-1][j+k-1]) sum++;
							if('*' != A[i-1][j+k] && '*' != A[i][j+k-1]) iscon = false;
						}

						for(int k = 0; k < ll; k++) if(nkey & (1<<k)) {
							if('*' == A[i][k+1]) {
								if('*' == A[i][k]) nsum++;
								if('*' == A[i+1][k]) nsum++;
								if('*' == A[i][k+2]) nsum++;
							}
							if('*' == A[i+1][k] && '*' == A[i][k]) nsum++;
							if('*' != A[i][k+1] && '*' != A[i+1][k]) niscon = false;
						}

						if(sum+nsum == N && iscon && niscon && isConnected(H, W)) {
							flag = true;
							printAnswer(H, W);
							break;
						}
						nsum = 0; niscon = true;

						if('*' != A[i][W]) {
							A[i][W] = '*';
							if('*' == A[i-1][W]) {
								if('*' == A[i-1][W-1]) sum++;
								if('*' == A[i][W-1]) sum++;
							}
							if('*' == A[i][W-1] && '*' == A[i-1][W-1]) sum++;
							if('*' != A[i-1][W] && '*' != A[i][W-1]) iscon = false;

							for(int k = 0; k < ll; k++) if(nkey & (1<<k)) {
								if('*' == A[i][k+1]) {
									if('*' == A[i][k]) nsum++;
									if('*' == A[i+1][k]) nsum++;
									if('*' == A[i][k+2]) nsum++;
								}
								if('*' == A[i+1][k] && '*' == A[i][k]) nsum++;
								if('*' != A[i][k+1] && '*' != A[i+1][k]) niscon = false;
							}

							if(sum+nsum == N && iscon && niscon && isConnected(H, W)) {
								flag = true;
								printAnswer(H, W);
								break;
							}
						}

						for(int k = 0; k < l; k++)
							A[i][j+k] = '.';
						A[i][W] = '.';
					}

					for(int k = 0; k < ll; k++)
						A[i+1][k+1] = '.';

					if(flag) break;
				}
				if(flag) break;

				A[i][j] = '*';
				if(1 == j) cnt++;
				else if(j == W) cnt += 3;
				else cnt += 4;
			}
			if(flag) break;
		}

		if(!flag) {
			puts("-1");
			continue;
		}
	}

	return 0;
}