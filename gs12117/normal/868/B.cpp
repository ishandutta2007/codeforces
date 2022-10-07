#include<cstdio>
int h, m, s, ta, tb;
int main() {
	scanf("%d%d%d%d%d", &h, &m, &s, &ta, &tb);
	ta %= 12;
	tb %= 12;
	h %= 12;
	ta *= 3600;
	tb *= 3600;
	h = h * 3600 + m * 60 + s;
	m = (m * 60 + s) * 12;
	s *= 12 * 60;
	int flag = 0;
	if ((ta < h) ^ (tb < h))flag++;
	if ((ta < m) ^ (tb < m))flag++;
	if ((ta < s) ^ (tb < s))flag++;
	if (flag == 0 || flag == 3) {
		printf("YES");
	}
	else {
		printf("NO");
	}
	return 0;
}