#include <bits/stdc++.h>

using namespace std;
typedef vector<int>::iterator iter;

int cmid;
bool f(int x) {
    return x <= cmid;
};

//1-indexed
struct jonson_wilson_flinston{
	int lo, hi;
	jonson_wilson_flinston *l, *r;
	int *b;

	jonson_wilson_flinston(iter from, iter to, int x, int y){
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
		l = new jonson_wilson_flinston(from, pivot, lo, mid);
		r = new jonson_wilson_flinston(pivot, to, mid+1, hi);
	}

	int map_left(int i) {
	    return b[i];
	}
	int LTE(int l, int r, int k) {
		if(l > r || k < lo) return 0;
		if(hi <= k) return r - l + 1;

		int lb = map_left(l - 1);
		int rb = map_left(r);

		return this->l->LTE(lb + 1, rb, k)
                + this->r->LTE(l - lb, r - rb, k);
	}
};

jonson_wilson_flinston *T[100010];

int n, k, x, r, q, cont;
map<int, int> id;
vector<int> range[100010], orig[100010];
vector<pair<int, int> > porra[100010];
map<int, vector<int> > qis;

struct qry {
    int x, r, q;
    bool operator <(const qry &o) const {
        return x < o.x;
    }
};
vector<qry> queries;

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &x, &r, &q);
        if(!id.count(q)) id[q] = cont++;
        queries.push_back({x, r, q});
        porra[id[q]].emplace_back(x, min(x + r, 1000000000));
        qis[x].push_back(q);
    }

    for(int i = 0; i < cont; i++) {
        sort(porra[i].begin(), porra[i].end());
        for(auto au : porra[i]) {
            orig[i].emplace_back(au.first);
            range[i].push_back(au.second);
        }
        T[i] = new jonson_wilson_flinston(range[i].begin(), range[i].end(), 0, 1000000000);
    }

    long long ans = 0;
    sort(queries.begin(), queries.end());
    for(qry query : queries) for(int Q = query.q - k, qi = 0; Q <= query.q + k; Q++) {
        if(id.count(Q)) qi = id[Q];
        else continue;

        int LB, RB;
        LB = lower_bound(orig[qi].begin(), orig[qi].end(), query.x - query.r) - orig[qi].begin() + 1;
        RB = upper_bound(orig[qi].begin(), orig[qi].end(), query.x - 1) - orig[qi].begin();
        ans += (RB-LB+1) - T[qi]->LTE(LB, RB, query.x - 1);
    }

    for(auto au : qis) {
        vector<int> v = au.second;
        sort(v.begin(), v.end());
        queue<int> qs;
        for(int i = 0; i < v.size(); i++) {
            while(!qs.empty() && qs.front() + k < v[i])
                qs.pop();
            ans += qs.size();
            qs.push(v[i]);
        }
    }

    printf("%lld\n", ans);
	return 0;
}