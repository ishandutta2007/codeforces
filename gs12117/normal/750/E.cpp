#include<stdio.h>
struct itnod {
	int a[5][5];
	itnod operator+(itnod z) {
		itnod res;
		for (int i = 0; i < 5; i++) {
			for (int j = i; j < 5; j++) {
				res.a[i][j] = 99999999;
				for (int k = i; k <= j; k++) {
					if (res.a[i][j] > a[i][k] + z.a[k][j])res.a[i][j] = a[i][k] + z.a[k][j];
				}
			}
		}
		return res;
	}
};
itnod it[1 << 19];
int n, q;
char s[200100];
int qry[200100][2];
const int itsz = 1 << 18;
itnod makeitn(int p) {
	itnod res;
	for (int i = 0; i < 5; i++) {
		for (int j = i; j < 5; j++) {
			res.a[i][j] = 99999999;
			if (i == j)res.a[i][j] = 0;
		}
	}
	if (p == 2) {
		res.a[0][1] = 0;
		res.a[0][0] = 1;
	}
	if (p == 0) {
		res.a[1][2] = 0;
		res.a[1][1] = 1;
	}
	if (p == 1) {
		res.a[2][3] = 0;
		res.a[2][2] = 1;
	}
	if (p == 7) {
		res.a[3][4] = 0;
	}
	if (p == 6) {
		res.a[3][3] = 1;
		res.a[4][4] = 1;
	}
	return res;
}
itnod itcalc(int start, int end) {
	start += itsz;
	end += itsz;
	itnod left = makeitn(3);
	itnod right = makeitn(3);
	while (start <= end) {
		if (start % 2 == 1) {
			left = left + it[start];
			start++;
		}
		if (end % 2 == 0) {
			right = it[end] + right;
			end--;
		}
		start /= 2;
		end /= 2;
	}
	return left + right;
}
int main() {
	scanf("%d%d", &n, &q);
	scanf("%s", s);
	for (int i = 0; i < n; i++) {
		it[itsz + i] = makeitn(s[i] - '0');
	}
	for (int i = itsz - 1; i > 0; i--) {
		it[i] = it[i * 2] + it[i * 2 + 1];
	}
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &qry[i][0], &qry[i][1]);
		qry[i][0]--;
		qry[i][1]--;
		itnod res = itcalc(qry[i][0], qry[i][1]);
		if (res.a[0][4] >= 999999)res.a[0][4] = -1;
		printf("%d\n", res.a[0][4]);
	}
	return 0;
}