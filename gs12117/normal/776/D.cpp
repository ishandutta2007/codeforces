#include<stdio.h>
int n, m;
int room[100100][3];
int uft[100100][2];
int uftf(int x) {
	if (x == uft[x][0])return x;
	int res = uftf(uft[x][0]);
	uft[x][1] ^= uft[uft[x][0]][1];
	uft[x][0] = res;
	return res;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &room[i][0]);
		room[i][0] ^= 1;
		room[i][1] = -1;
		room[i][2] = -1;
	}
	for (int i = 0; i < m; i++) {
		int cn;
		scanf("%d", &cn);
		for (int j = 0; j < cn; j++) {
			int rn;
			scanf("%d", &rn);
			rn--;
			if (room[rn][1] == -1) {
				room[rn][1] = i;
			}
			else {
				room[rn][2] = i;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		uft[i][0] = i;
		uft[i][1] = 0;
	}
	for (int i = 0; i < n; i++) {
		int p = uftf(room[i][1]);
		int q = uftf(room[i][2]);
		if (p == q) {
			if (uft[room[i][1]][1] != (uft[room[i][2]][1] ^ room[i][0])) {
				printf("NO");
				return 0;
			}
		}
		else {
			uft[p][1] = room[i][0] ^ uft[room[i][1]][1] ^ uft[room[i][2]][1];
			uft[p][0] = q;
		}
	}
	printf("YES");
	return 0;
}