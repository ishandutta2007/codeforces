#include <bits/stdc++.h>

#define MAXN 250250

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

struct myhash {
	ll chash[MAXN][2];
	ll mult[MAXN][2];
	ll b1, M1, b2, M2;

	myhash(ll b1 = 311, ll M1 = 1000000021, ll b2 = 317, ll M2 = 1000000009) :
		b1(b1), M1(M1), b2(b2), M2(M2) { calc();}

	void calc() {
		mult[0][0] = mult[0][1] = 1;
		for(ll i=1; i < MAXN; i++) {
			mult[i][0] = (mult[i-1][0] * b1)%M1;
			mult[i][1] = (mult[i-1][1] * b2)%M2;
		}
	}

	// Preprocess new string in string st
	void compute(string &st) {
		chash[0][0] = chash[0][1] = st[0] + 1;
		for(int i=1; i<(int)st.size();i++) {
			chash[i][0] = ((chash[i-1][0]*b1)%M1 + st[i] + 1)%M1;
			chash[i][1] = ((chash[i-1][1]*b2)%M2 + st[i] + 1)%M2;
		}
	}

	// Hash of substring [l, r] INCLUSIVE
	pll substr(ll l, ll r) {
		if(!l) return make_pair(chash[r][0], chash[r][1]);

		ll p1 = (chash[r][0] - (chash[l-1][0] * mult[r-l+1][0])%M1 + M1)%M1;
		ll p2 = (chash[r][1] - (chash[l-1][1] * mult[r-l+1][1])%M2 + M2)%M2;
		return make_pair(p1, p2);
	}
} s1, s2, s3, cg, cp;


char s[MAXN];
string st1, st2, st3;

bool is_sub(string g, string p) {
    if(g.size() < p.size()) return false;
    cg.compute(g);
    cp.compute(p);
    int ps = p.size(), gs = g.size();

    for(int i = 0; i + ps <= gs; i++) {
        if(cg.substr(i, i + ps - 1) == cp.substr(0, ps - 1))
            return true;
    }

    return false;
}

int solve(string &a, string &b, string &c) {
    int as = a.size(), bs = b.size(), cs = c.size();
    int ret = as + bs + cs;

    s1.compute(a);
    s2.compute(b);
    s3.compute(c);

    if(is_sub(a, b) && is_sub(a, c)) return as;

    int sz = 0, tmp = -1;
    if(is_sub(b, a)) {
        ret -= as;
    }
    else {
        while(sz < as && sz < bs) {
            if(s1.substr(as-sz-1, as-1) == s2.substr(0, sz)) tmp = sz;
            sz++;
        }
        sz = tmp + 1;
        ret -= sz;
    }

    if(is_sub(b, c)) {
        ret -= cs;
    } else {
        int k = 0, tmp = -1;
        while(k < bs && k < cs) {
            if(s2.substr(bs-k-1, bs-1) == s3.substr(0, k)) tmp = k;
            k++;
        }
        ret -= (tmp + 1);
    }

    return ret;
}

int main() {
	cin >> st1 >> st2 >> st3;

    int ans = solve(st1, st2, st3);
    ans = min(ans, solve(st1, st3, st2));
    ans = min(ans, solve(st2, st1, st3));
    ans = min(ans, solve(st2, st3, st1));
    ans = min(ans, solve(st3, st1, st2));
    ans = min(ans, solve(st3, st2, st1));

    printf("%d\n", ans);

	return 0;
}