#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

int a[100002], b[100002], last[100002];
int z;

bool f(int x) {
    return x <= z;
};

struct obi_pu_2x_tree {
	int kk, hi;
	obi_pu_2x_tree *l, *r;
	int *b;

    obi_pu_2x_tree(){}
	obi_pu_2x_tree(int *fr, int *t, int x, int y){
		kk = x, hi = y;
		if(kk == hi || fr >= t) {
            l = r = NULL;
            b = NULL;
            return;
		}

		int mm = kk+(hi-kk)/2, i = 1;
		z = mm;

		b = new int[t - fr + 1];
        b[0] = 0;
		for(int *it = fr; it != t; it++, i++) {
			b[i] = (b[i-1] + f(*it));
		}

		int *pt = stable_partition(fr, t, f);
		l = new obi_pu_2x_tree(fr, pt, kk, mm);
		r = new obi_pu_2x_tree(pt, t, mm+1, hi);
	}

	int x(int l, int r, int k) {
		if(l > r || k < kk) return 0;
		if(hi <= k) return r - l + 1;

		int lb = b[l - 1];
		int rb = b[r];

		return this->l->x(lb + 1, rb, k)
                + this->r->x(l - lb, r - rb, k);
	}
} T;

int main() {
    int n;
    scanf("%d", &n);

    map<int, int> last_occur;
    for(int i = 0 ; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = last_occur[a[i]];
        last_occur[a[i]] = i + 1;
    }

    T = obi_pu_2x_tree(b, b + n, 0, 100001);
    for(int k = 1; k <= n; k++) {
        int ans = 0, i = 1;
        while(i <= n) {
            int l = max(i + k - 1, last[i]), r = n, m;
            while(l < r) {
                m = l+(r-l+9)/10;
                if(T.x(i, m, i-1) <= k)
                    l = m;
                else
                    r = m - 1;
            }
            last[i] = l + 1;
            i = l + 1;
            ans++;
        }
        printf("%d ", ans);
    }

	return 0;
}