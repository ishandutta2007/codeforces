#include <bits/stdc++.h>

#define MOD 1000000009
#define MN 300003

using namespace std;
typedef long long ll;

int n, m, arr[MN];

inline int add(int a, int b) {
    int ret = a + b;
    if(ret >= MOD) ret -= MOD;
    return ret;
}

inline int sub(int a, int b) {
    int ret = a - b;
    if(ret < 0) ret += MOD;
    return ret;
}

struct matrix {
    int c[2][2];

    matrix() {
        c[0][0] = c[0][1] = c[1][0] = c[1][1] = 0;
    }

    bool operator == (matrix b) const {
        return c == b.c;
    }

    matrix operator + (matrix b) const {
        matrix ret;
        for(int i=0; i<2; i++)
            for(int j=0;j<2;j++)
                ret.c[i][j] = add(c[i][j], b.c[i][j]);
        return ret;
    }

    matrix operator - (matrix b) const {
        matrix ret;
        for(int i=0; i<2; i++)
            for(int j=0;j<2;j++)
                ret.c[i][j] = sub(c[i][j], b.c[i][j]);
        return ret;
    }

    matrix operator % (matrix b) const {
        matrix ret;
        for(int i=0;i<2;i++) {
            for(int j=0;j<2;j++) {
                int sum = 0;
                for(int k=0;k<2;k++) {
                    int quant = 1LL * c[i][k] * b.c[k][j] % MOD;
                    sum = add(sum, quant);
                }
                ret.c[i][j] = sum;
            }
        }
        return ret;
    }
};
matrix lazy[MN<<2], fib[MN];
int tree[MN<<2];

void push(int id, int l, int r) {
    if(!(lazy[id].c[0][0] | lazy[id].c[0][1] | lazy[id].c[1][0] | lazy[id].c[1][1])) return;
	int sz = (r - l + 1), m = (l+r)/2;
	tree[id] = sub(add(tree[id], (lazy[id] % fib[sz+1]).c[1][0]), (lazy[id] % fib[1]).c[1][0]);
	if(l != r) {
		lazy[id<<1] = lazy[id<<1] + lazy[id];
		lazy[id<<1|1] = lazy[id<<1|1] + (lazy[id] % fib[m - l + 1]);
	}
	lazy[id].c[0][0] = lazy[id].c[0][1] = lazy[id].c[1][0] = lazy[id].c[1][1] = 0;
}

void update(int id, int l, int r, int lq, int rq, int pot) {
	push(id, l, r);
	if(r < lq || rq < l) return;
	if(lq <= l && r <= rq) {
		lazy[id] = fib[l-pot];
		push(id, l, r);
	} else {
		int m = (l+r)/2;
		update(id<<1, l, m, lq, rq, pot);
		update(id<<1|1, m+1, r, lq, rq, pot);
		tree[id] = add(tree[id<<1], tree[id<<1|1]);
	}
}

int query(int id, int l, int r, int lq, int rq) {
	if(r < lq || rq < l) return 0;
	push(id, l, r);
	if(lq <= l && r <= rq) return tree[id];
	int m = (l+r)/2;
    return add(query(id<<1, l, m, lq, rq),
                query(id<<1|1, m+1, r, lq, rq));
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		arr[i] = add(arr[i], arr[i-1]);
	}

    fib[1].c[0][0] = 0;
    fib[1].c[0][1] = 1;
    fib[1].c[1][0] = 1;
    fib[1].c[1][1] = 1;
    for(int i = 2; i < MN; i++)
		fib[i] = fib[i-1] % fib[1];

	while(m--) {
		int t, l, r;
		scanf("%d %d %d", &t, &l, &r);
		if(t == 1) update(1, 1, n, l, r, l-1);
		else {
            int resp = sub(add(query(1, 1, n, l, r), arr[r]), arr[l-1]);
            printf("%d\n", resp);
		}
	}
	return 0;
}