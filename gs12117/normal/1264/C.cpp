#include<cstdio>
#include<set>
const long long int mod = 998244353;
struct st {
	long long int lm, td;
	st operator+(const st&r)const {
		st res;
		res.lm = lm * r.lm%mod;
		res.td = (td*r.lm + r.td) % mod;
		return res;
	}
};
st it[1 << 19];
int n, q;
std::set<int> cpts;
long long int ans;
int a[200100];
long long int mpow(int x, int y) {
	if (y == 0)return 1;
	long long int r = mpow(x, y / 2);
	r *= r;
	r %= mod;
	if (y % 2 == 1) {
		r *= x;
		r %= mod;
	}
	return r;
}
void itpush(int loc, long long int pd) {
	loc += 1 << 18;
	it[loc].lm = pd;
	it[loc].td = pd;
	loc /= 2;
	while (loc > 0) {
		it[loc] = it[loc * 2] + it[loc * 2 + 1];
		loc /= 2;
	}
}
long long int itcalc(int start, int end) {
	start += 1 << 18;
	end += 1 << 18;
	st l, r;
	l.lm = 1;
	l.td = 0;
	r.lm = 1;
	r.td = 0;
	while (start <= end) {
		if (start % 2 == 1) {
			l = l + it[start];
			start++;
		}
		if (end % 2 == 0) {
			r = it[end] + r;
			end--;
		}
		start /= 2;
		end /= 2;
	}
	l = l + r;
	return l.td;
}
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		itpush(i, 100 * mpow(a[i], mod - 2) % mod);
	}
	cpts.insert(0);
	cpts.insert(n);
	ans = itcalc(0, n - 1);
	for (int i = 0; i < q; i++) {
		int u;
		scanf("%d", &u);
		u--;
		std::set<int>::iterator p;
		if (cpts.find(u) == cpts.end()) {
			cpts.insert(u);
			p = cpts.find(u);
			p++;
			int v = *p;
			p = cpts.find(u);
			p--;
			int w = *p;
			ans += itcalc(w, u - 1);
			ans += itcalc(u, v - 1);
			ans += mod - itcalc(w, v - 1);
			ans %= mod;
		}
		else {
			p = cpts.find(u);
			p++;
			int v = *p;
			p = cpts.find(u);
			p--;
			int w = *p;
			cpts.erase(u);
			ans += mod - itcalc(w, u - 1);
			ans += mod - itcalc(u, v - 1);
			ans += itcalc(w, v - 1);
			ans %= mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}