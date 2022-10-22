#include <cstdio>
#include <cstring>

using namespace std;

int n, m, i, j, l1, l2, k, p, k2, p2, x, y, verif, ans, minarea = 5000, rezx, rezy;

char s[500][500];

int main() {
	scanf("%d%d\n", &n, &m);
	for (i = 0; i < n; ++i)
		fgets(s[i], sizeof(s[i]), stdin);

	for (i = 1; i <= n; ++i)
		if (n % i == 0)
			for (j = 1; j <= m; ++j)
				if (m % j == 0) {
					l1 = n / i;
					l2 = m / j;
					verif = 1;
					for (k = 0; k < n && verif == 1; k += l1)
						for (p = 0; p < m && verif == 1; p += l2)
							for (k2 = 0; k2 < n && verif == 1; k2 += l1)
								for (p2 = 0; p2 < m && verif == 1; p2 += l2)
									if (k != k2 || p != p2) {
										verif = 0;
										for (x = 0; x < l1 && verif == 0; ++x)
											for (y = 0; y < l2 && verif == 0; ++y)
												if (s[k + x][p + y] != s[k2 + x][p2 + y])
													verif = 1;
										if (verif == 0)
											continue;
										verif = 0;
										for (x = 0; x < l1 && verif == 0; ++x)
											for (y = 0; y < l2 && verif == 0; ++y)
												if (s[k +x][p + y] != s[k2 + l1 - x - 1][p2 + l2 - y - 1])
													verif = 1;
										if (verif == 0)
											continue;

										if (l1 != l2)
											continue;
										verif = 0;
										for (x = 0; x < l1 && verif == 0; ++x)
											for (y = 0; y < l2 && verif == 0; ++y)
												if (s[k + x][p + y] != s[k2 + l1 - y - 1][p2 + x])
													verif = 1;
									}
					if (verif == 1)
						++ans;
					else
						continue;
					if (l1 * l2 < minarea)
						minarea = l1 * l2, rezx = l1, rezy = l2;
					else
						if (l1 * l2 ==minarea && l1 < rezx)
							rezx = l1, rezy = l2;
				}

	printf("%d\n%d %d\n", ans, rezx, rezy);
}