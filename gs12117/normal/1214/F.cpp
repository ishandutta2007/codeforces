#include<cstdio>
#include<algorithm>
int m, n;
int ad[200100];
int bd[200100];
struct st {
	int loc, val;
	bool operator<(const st&r)const {
		return val < r.val;
	}
};
st as[200100];
st bs[200100];
long long int cres[400100];
int ansr[200100];
void calc() {
	int p = n;
	int d = 0;
	int i = 0;
	int j = 0;
	while (i < n || j < n) {
		if (i != n && (j == n || as[i].val < bs[j].val)) {
			cres[p] += as[i].val - d;
			p++;
			d = as[i].val;
			i++;
		}
		else {
			cres[p] += bs[j].val - d;
			p--;
			d = bs[j].val;
			j++;
		}
	}
	cres[p] += m - d;
}
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &ad[i]);
		as[i].loc = i;
		as[i].val = ad[i];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &bd[i]);
		bs[i].loc = i;
		bs[i].val = bd[i];
	}
	std::sort(as, as + n);
	std::sort(bs, bs + n);
	calc();
	long long int fres = 0;
	long long int ansp = 0;
	for (int i = 0; i <= 2 * n; i++) {
		fres += cres[i];
		if (fres * 2 >= m) {
			ansp = i;
			break;
		}
	}
	long long int ansl = 0;
	for (int i = 0; i <= 2 * n; i++) {
		if (i > ansp)ansl += (i - ansp)*cres[i];
		else ansl -= (i - ansp)*cres[i];
	}
	printf("%lld\n", ansl);
	for (int i = 0; i < n; i++) {
		ansr[as[(i + ansp) % n].loc] = bs[i].loc + 1;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", ansr[i]);
	}
	return 0;
}