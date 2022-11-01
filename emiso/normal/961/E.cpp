#include <bits/stdc++.h>

using namespace std;
typedef vector<int>::iterator iter;

int cmid;
bool f(int x) {
    return x <= cmid;
};

//1-indexed
struct para_de_olhar_meus_codigos_tree_fdp {
	int lo, hi;
	para_de_olhar_meus_codigos_tree_fdp *l, *r;
	int *b;

	para_de_olhar_meus_codigos_tree_fdp(iter from, iter to, int x, int y){
		lo = x, hi = y;
		if(lo == hi || from >= to) {
            l = r = NULL;
            b = NULL;
            return;
		}

		int mid = lo+(hi-lo)/2, i = 1;
		cmid = mid;

		b = new int[to - from + 1];
        b[0] = 0;
		for(iter it = from; it != to; it++, i++) {
			b[i] = (b[i-1] + f(*it));
		}

		iter pivot = stable_partition(from, to, f);
		l = new para_de_olhar_meus_codigos_tree_fdp(from, pivot, lo, mid);
		r = new para_de_olhar_meus_codigos_tree_fdp(pivot, to, mid+1, hi);
	}

	int map_left(int i) {
	    return b[i];
	}
	int ratoeira(int l, int r, int k) {
		if(l > r || k < lo) return 0;
		if(hi <= k) return r - l + 1;

		int lb = map_left(l - 1);
		int rb = map_left(r);

		return this->l->ratoeira(lb + 1, rb, k)
                + this->r->ratoeira(l - lb, r - rb, k);
	}
};

long long ans;
int n, x[200020];
vector<int> v;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &x[i]);
		v.push_back(x[i]);
	}
	para_de_olhar_meus_codigos_tree_fdp james(v.begin(), v.end(), 0, 1000000000);
	for(int i = 1; i <= n; i++) {
		int RB = min(i-1, x[i]);
		ans += RB - james.ratoeira(1, RB, i-1);
	}
	printf("%lld\n", ans);
	return 0;
}