#include<cstdio>
#include<algorithm>
#include<map>
int n;
int a[400100];
int ans;
std::map<int, int> mp;
struct st {
	int loc, val;
	bool operator<(const st&r)const {
		return val > r.val;
	}
};
st sl[400100];
int m;
int ax, ay;
int ansr[400100];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		mp[a[i]]++;
	}
	m = 0;
	for (int i = 0; i < n; i++) {
		if (mp[a[i]] > 0) {
			sl[m].loc = a[i];
			sl[m].val = mp[a[i]];
			mp[a[i]] = 0;
			m++;
		}
	}
	std::sort(sl, sl + m);
	int p = m;
	int tans = 0;
	for (int i = 1; i <= n; i++) {
		tans += p;
		while (p > 0 && sl[p - 1].val == i)p--;
		int r = tans / i;
		if (r < i)break;
		if (ans < i*r) {
			ans = i * r;
			ax = i;
			ay = r;
		}
	}
	int pz = 0;
	for (int i = 0; i < m; i++) {
		int mpz = sl[i].val;
		if (mpz > ax)mpz = ax;
		mpz += pz;
		if (mpz >= ans)mpz = ans;
		for (int j = pz; j < mpz; j++) {
			ansr[j] = sl[i].loc;
		}
		pz = mpz;
	}
	printf("%d\n", ans);
	printf("%d %d\n", ax, ay);
	for (int i = 0; i < ax; i++) {
		for (int j = 0; j < ay; j++) {
			printf("%d ", ansr[((j + ay - i)*ax + i) % ans]);
		}
		printf("\n");
	}
	return 0;
}