#include<cstdio>
#include<algorithm>
int n;
char s[200100];
struct node {
	long long int x;
	int yl, yr;
};
struct pnode {
	long long int x;
	int v;
	bool operator<(const pnode&r)const {
		return x < r.x;
	}
};
node nl[200100];
node snl[200100];
int chk[200100];
int m;
pnode pl[400100];
int psz;
long long int ans;
int main() {
	scanf("%s", s);
	for (n = 0; s[n]; n++);
	m = 1;
	nl[0].x = 0;
	nl[0].yl = 0;
	nl[0].yr = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			nl[m - 1].yr++;
		}
		else {
			m++;
			nl[m - 1].x = nl[m - 2].x + 1;
			nl[m - 1].yl = nl[m - 2].yr;
			nl[m - 1].yr = nl[m - 2].yr;
		}
	}
	for (int i = 0;; i++) {
		for (int j = 0; j < m; j++) {
			chk[j] = 0;
		}
		long long int s = 1e18;
		for (int j = 0; j < m; j++) {
			if (s > nl[j].yr - i * nl[j].x)chk[j]++;
			long long int ts = nl[j].yl - i * nl[j].x;
			if (s > ts)s = ts;
		}
		s = -(1e18);
		for (int j = m - 1; j >= 0; j--) {
			if (s < nl[j].yl - i * nl[j].x)chk[j]++;
			long long int ts = nl[j].yr - i * nl[j].x;
			if (s < ts)s = ts;
		}
		int nm = 0;
		for (int j = 0; j < m; j++) {
			if (chk[j] < 2) {
				snl[nm] = nl[j];
				nm++;
			}
		}
		m = nm;
		for (int j = 0; j < m; j++) {
			nl[j] = snl[j];
		}
		if (m == 0)break;
		psz = 0;
		for (int j = 0; j < m; j++) {
			pl[psz].x = nl[j].yl - i * nl[j].x;
			pl[psz].v = 1;
			psz++;
			pl[psz].x = nl[j].yr + 1 - i * nl[j].x;
			pl[psz].v = -1;
			psz++;
		}
		std::sort(pl, pl + psz);
		long long int sv = 0;
		for (int j = 0; j < psz; j++) {
			if (j != 0)ans += sv * (sv - 1) / 2 * (pl[j].x - pl[j - 1].x);
			sv += pl[j].v;
		}
	}
	printf("%lld", ans);
	return 0;
}