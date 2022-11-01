#include <bits/stdc++.h>

#define MN 500000

using namespace std;

int t, l, r, x, q, co, last;
int pai[MN], sz[MN], xo[MN];
unordered_map<int, int> compress;

int find(int x) {
	if(x == pai[x]) return x;
	int prev = pai[x];
	pai[x] = find(pai[x]);
	xo[x] ^= xo[prev];
	return pai[x];
}

void merge(int a, int b, int x) {
	find(a); find(b);
	x ^= xo[a] ^ xo[b];
	a = pai[a]; b = pai[b];

	if(sz[a] < sz[b]) swap(a, b);
	pai[b] = a;
	xo[b] = x;
	sz[a]++;
}

int query(int a, int b) {
	find(a); find(b);
	if(pai[a] != pai[b]) return -1;
	return xo[a] ^ xo[b];
}

int main() {
    for(int i = 0; i < MN; i++) pai[i] = i;

    scanf("%d", &q);
    while(q--) {
        scanf("%d %d %d", &t, &l, &r);
        l ^= last; r ^= last;
        if(l > r) swap(l, r);
        r++;

        if(!compress.count(l)) compress[l] = co++;
        if(!compress.count(r)) compress[r] = co++;
        l = compress[l];
        r = compress[r];

        if(t == 1) {
            scanf("%d", &x);
            x ^= last;

            if(query(l, r) == -1)
                merge(l, r, x);
        } else if(t == 2) {
            int ans = query(l, r);
            printf("%d\n", ans);
            last = (ans == -1)  ? 1 : ans;
        } else assert(false);
    }
	return 0;
}