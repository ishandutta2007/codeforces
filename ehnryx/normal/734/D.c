#include <stdio.h>

#define L 0
#define R 1
#define U 2
#define D 3
#define UL 4
#define UR 5
#define DL 6
#define DR 7
#define INF 2000000001

typedef struct {
	char t;//type
	int d;//dist
} Piece;

int main() {
	int i, p, kx, ky, tempx, tempy;
	Piece check[8];
	scanf("%d", &p);
	char type[2];
	scanf("%d %d", &kx, &ky);
	for (i = 0; i < 8; i++) {
		check[i].t = '\0';
		check[i].d = INF;
	}
	while (p--) {
		scanf("%s %d %d", &type, &tempx, &tempy);
		if (kx == tempx) {
			if (ky < tempy && tempy-ky < check[U].d) {
				check[U].d = tempy-ky;
				check[U].t = type[0];
			}
			else if (ky > tempy && ky-tempy < check[D].d) {
				check[D].d = ky-tempy;
				check[D].t = type[0];
			}
		}
		else if (ky == tempy) {
			if (kx < tempx && tempx-kx < check[R].d) {
				check[R].d = tempx-kx;
				check[R].t = type[0];
			}
			else if (kx > tempx && kx-tempx < check[L].d) {
				check[L].d = kx-tempx;
				check[L].t = type[0];
			}
		}
		else if (tempx-kx == tempy-ky) {
			if (kx < tempx && tempx-kx < check[UR].d) {
				check[UR].d = tempx-kx;
				check[UR].t = type[0];
			}
			else if (kx > tempx && kx-tempx < check[DL].d) {
				check[DL].d = kx-tempx;
				check[DL].t = type[0];
			}
		}
		else if (tempx-kx == -tempy+ky) {
			if (kx < tempx && tempx-kx < check[DR].d) {
				check[DR].d = tempx-kx;
				check[DR].t = type[0];
			}
			else if (kx > tempx && kx-tempx < check[UL].d) {
				check[UL].d = kx-tempx;
				check[UL].t = type[0];
			}
		}
	}
	for (i = 0; i < 4; i++) {
		if (check[i].t == 'Q' || check[i].t == 'R') {
			printf("YES\n");
			return 0;
		}
	}
	for ( ; i < 8; i++) {
		if (check[i].t == 'Q' || check[i].t == 'B') {
			printf("YES\n");
			return 0;
		} 
	}
	printf("NO\n");
	return 0;
}