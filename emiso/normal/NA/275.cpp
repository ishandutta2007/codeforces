#include <bits/stdc++.h>

using namespace std;
typedef vector<int>::iterator iter;

struct wavelet_tree{
	int lo, hi;
	wavelet_tree *l, *r;
	vector<int> b;

    /**
     * nodes are in range [x,y]
	 * array indices are [from, to)
     **/
	wavelet_tree(iter from, iter to, int x, int y){
		lo = x, hi = y;
		if(lo == hi || from >= to) {
            l = r = NULL;
            return;
		}

		int mid = lo+(hi-lo)/2;

		auto f = [mid](int x) {
			return x <= mid;
		};

		b.reserve(to-from+1);
		b.push_back(0);
		for(iter it = from; it != to; it++)
			b.push_back(b.back() + f(*it));

		iter pivot = stable_partition(from, to, f);
		l = new wavelet_tree(from, pivot, lo, mid);
		r = new wavelet_tree(pivot, to, mid+1, hi);
	}

	int map_left(int i) {
	    return b[i];
	}

	int map_right(int i) {
	    return i - b[i];
	}

    int query(int l, int r, int k) {
        if(r - l + 1 < k) return -1;
        if(lo == hi) return lo;

        int ret = this->l->query(map_left(l-1)+1, map_left(r), k);
        if(ret == -1) ret = this->r->query(l-map_left(l-1), r-map_left(r), k);

        return ret;
    }
};

int main() {
    int n, q, l, r, k;
    scanf("%d %d", &n, &q);

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    wavelet_tree T(v.begin(), v.end(), 1, n);
    while(q--) {
        scanf("%d %d %d", &l, &r, &k);
        printf("%d\n", T.query(l, r, (r-l+1)/k + 1));
    }
	return 0;
}