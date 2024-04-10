#include<stdio.h>
#include<vector>
int t, n;
int p[200][3];
int pn[200];
int zdist[200];
int cnt;
void init() {
	cnt = 0;
	for (int i = 0; i < 170; i++) {
		pn[i] = 0;
		zdist[i] = -1;
	}
}
void getqry(int x) {
	if (cnt == 16) {
		pn[x] = 2;
		return;
	}
	cnt++;
	printf("? %d\n", x);
	fflush(stdout);
	scanf("%d", &pn[x]);
	for (int i = 0; i < pn[x]; i++) {
		scanf("%d", &p[x][i]);
	}
}
int main() {
	scanf("%d", &t);
	while (t--) {
		init();
		std::vector<int> c, d;
		c.clear();
		d.clear();
		scanf("%d", &n);
		int x = 1;
		getqry(x);
		if (pn[x] == 2) {
			printf("! %d\n", x);
			goto end;
		}
		x = p[x][0];
		while (1) {
			c.push_back(x);
			getqry(x);
			if (pn[x] == 2) {
				printf("! %d\n", x);
				goto end;
			}
			if (pn[x] == 1) {
				break;
			}
			if (pn[p[x][0]] != 0)x = p[x][1];
			else x = p[x][0];
		}
		x = 1;
		while (1) {
			d.push_back(x);
			if (pn[x] == 1) {
				break;
			}
			if (pn[p[x][0]] != 0)x = p[x][1];
			else x = p[x][0];
			getqry(x);
			if (pn[x] == 2) {
				printf("! %d\n", x);
				goto end;
			}
		}
		if (c.size() > d.size()) {
			x = c[(c.size() - d.size()) / 2];
		}
		else {
			x = d[(d.size() - c.size()) / 2];
		}
		zdist[x] = (c.size() + d.size()) / 2;
		while (1) {
			fflush(stdout);
			if (zdist[x] >= n - 4) {
				if (pn[p[x][0]] == 0)x = p[x][0];
				else if (pn[p[x][1]] == 0)x = p[x][1];
				else x = p[x][2];
				getqry(x);
				if (pn[x] == 2) {
					printf("! %d\n", x);
					goto end;
				}
				for (int i = 0; i < pn[x]; i++) {
					int y = p[x][i];
					if (pn[y] != 0)continue;
					getqry(y);
					if (pn[y] == 2) {
						printf("! %d\n", y);
						goto end;
					}
					for (int j = 0; j < pn[y]; j++) {
						int z = p[y][j];
						if (pn[z] != 0)continue;
						getqry(z);
						if (pn[z] == 2) {
							printf("! %d\n", z);
							goto end;
						}
					}
				}
			}
			else {
				d.clear();
				while (1) {
					d.push_back(x);
					if (pn[x] == 1) {
						break;
					}
					if (pn[p[x][0]] == 0)x = p[x][0];
					else if (pn[p[x][1]] == 0)x = p[x][1];
					else x = p[x][2];
					getqry(x);
					if (pn[x] == 2) {
						printf("! %d\n", x);
						goto end;
					}
				}
				x = d[(d.size() - zdist[d[0]]) / 2];
				zdist[x] = (d.size() + zdist[d[0]]) / 2;
			}
		}
		end:;
		fflush(stdout);
	}
	return 0;
}