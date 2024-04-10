#include <bits/stdc++.h>

using namespace std;

int cm;
bool f(int x) {
    return x <= cm;
};

int t, n, q, a, b[100010], l, r, k, last = 0, ans;
vector<int> lst[100010];

struct mopa{
	int p, q;
	mopa *l, *r;
	int *b;

	mopa(int *fr, int *t, int x, int y){
		p = x, q = y;
		if(p == q || fr >= t) return;

		int m = p+(q-p)/2, i = 1;
		cm = m;

		b = new int[t - fr + 1];
        b[0] = 0;
		for(int *it = fr; it != t; it++, i++) {
			b[i] = (b[i-1] + f(*it));
		}

		int *pv = stable_partition(fr, t, f);
		l = new mopa(fr, pv, p, m);
		r = new mopa(pv, t, m+1, q);
	}

	int x(int l, int r, int k) {
		if(l > r || k < p) return 0;
		if(q <= k) return r - l + 1;

		int lb = b[l - 1];
		int rb = b[r];

		return this->l->x(lb + 1, rb, k)
                + this->r->x(l - lb, r - rb, k);
	}
};

int main() {
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        b[i] = (lst[a].size() >= k)? lst[a][lst[a].size()-k] : 0;
        lst[a].push_back(i + 1);
    }

    mopa t(b, b + n, 0, 100000);

    scanf("%d", &q);
    while(q--) {
        scanf("%d %d", &l, &r);
        l = (l + last) % n + 1;
        r = (r + last) % n + 1;
        if(l > r) swap(l, r);
        ans = t.x(l, r, l - 1);
        printf("%d\n", ans);
        last = ans;
    }
	return 0;
}