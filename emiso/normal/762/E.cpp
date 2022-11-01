#include <bits/stdc++.h>

#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("O3")

using namespace std;

int cmid;
bool F(int x) {
    return x <= cmid;
};

struct evn {
    int x, r, f;
};
vector<evn> ev;
bool cmp(evn a, evn b) {
    return a.x < b.x;
}
bool cmp2(evn a, evn b) {
    return a.f < b.f;
}

const int INF = 1000000001, MN = 100010, MF = 10001;
vector<int> xs[MF], rs[MF];
int n, k, x[MN], r[MN], f[MN], auxf[MN], auxt[MN];
long long ans;

struct rato{
	int lo, hi;
	rato *l, *r;
	int *b;

	rato() {}

	rato(int *from, int *to, int x, int y){
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
		for(int *it = from; it != to; it++, i++) {
			b[i] = (b[i-1] + F(*it));
		}

		int *pt = stable_partition(from, to, F);
		l = new rato(from, pt, lo, mid);
		r = new rato(pt, to, mid+1, hi);
	}

	int x(int l, int r, int k) {
		if(l > r || k < lo) return 0;
		if(hi <= k) return r - l + 1;

		int lb = b[l - 1];
		int rb = b[r];

		return this->l->x(lb + 1, rb, k)
                + this->r->x(l - lb, r - rb, k);
	}

    ~rato(){
	    delete [] b;
		delete l;
		delete r;
	}
};

rato *frente[MF], *tras[MF];

void load(int i) {
    for(int j = 0; j < xs[i].size(); j++) {
        auxf[j] = min(INF, xs[i][j] + rs[i][j]);
        auxt[j] = max(-INF, xs[i][j] - rs[i][j]);
    }

    frente[i] = new rato(auxf, auxf + xs[i].size(), -INF, INF);
      tras[i] = new rato(auxt, auxt + xs[i].size(), -INF, INF);
}

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &x[i], &r[i], &f[i]);
        ev.push_back({x[i], r[i], f[i]});
    }
    sort(ev.begin(), ev.end(), cmp);
    for(int i = 0; i < n; i++) {
        x[i] = ev[i].x;
        r[i] = ev[i].r;
        f[i] = ev[i].f;

        xs[f[i]].push_back(x[i]);
        rs[f[i]].push_back(r[i]);
    }
    sort(ev.begin(), ev.end(), cmp2);
    for(int i = 0; i < n; i++) {
        x[i] = ev[i].x;
        r[i] = ev[i].r;
        f[i] = ev[i].f;
    }
    ev.clear();

    int ll = 1, lr = 0;
    for(int el = 0; el < n; el++) {
        int lb = max(f[el] - k, 1);
        while(ll < lb) {
            delete frente[ll];
            delete tras[ll++];
        }
        while(lr < f[el]) {
            load(++lr);
        }
        for(int freq = lb; freq <= f[el]; freq++) {
            {
                int L = lower_bound(xs[freq].begin(), xs[freq].end(), x[el] - r[el]) - xs[freq].begin() + 1;
                int R = lower_bound(xs[freq].begin(), xs[freq].end(), x[el]) - xs[freq].begin();
                if(L <= R) ans += ((R - L + 1) - frente[freq]->x(L, R, x[el] - 1));
            }
            if(freq < f[el]) {
                int L = upper_bound(xs[freq].begin(), xs[freq].end(), x[el]) - xs[freq].begin() + 1;
                int R = upper_bound(xs[freq].begin(), xs[freq].end(), x[el] + r[el]) - xs[freq].begin();
                if(L <= R) ans += tras[freq]->x(L, R, x[el]);
            }
        }
    }

    printf("%lld\n", ans);
	return 0;
}