#include <bits/stdc++.h>

#define MAXN 250250

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

struct myhash {
	ll chash[MAXN][2];
	ll mult[MAXN][2];
	ll b1, M1, b2, M2;

	myhash(ll b1 = 200017, ll M1 = 1000000021, ll b2 = 200023, ll M2 = 1000000009) :
		b1(b1), M1(M1), b2(b2), M2(M2) { calc();}

	void calc() {
		mult[0][0] = mult[0][1] = 1;
		for(ll i=1; i < MAXN; i++) {
			mult[i][0] = (mult[i-1][0] * b1)%M1;
			mult[i][1] = (mult[i-1][1] * b2)%M2;
		}
	}

	// Preprocess new string in global string st
	void compute(vector<int> &st) {
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
} h;

int n, m, l, r, len;
char s[200020]; string str;
vector<int> occ[26], meta;

pll get(int l, int r) {
    pll sub = h.substr(l, r);

    for(int i = 0; i < 26; i++) {
        int pos = lower_bound(occ[i].begin(), occ[i].end(), l) - occ[i].begin();
        if(pos == occ[i].size() || occ[i][pos] > r) continue;

        sub.first = (sub.first - ((meta[occ[i][pos]]+1)*h.mult[r-occ[i][pos]][0])%h.M1 + h.M1) % h.M1;
        sub.second = (sub.second - ((meta[occ[i][pos]]+1)*h.mult[r-occ[i][pos]][1])%h.M2 + h.M2) % h.M2;

        sub.first = (sub.first + h.mult[r-occ[i][pos]][0]) % h.M1;
        sub.second = (sub.second + h.mult[r-occ[i][pos]][1]) % h.M2;
    }

    return sub;
}

int main() {
    scanf("%d %d %s", &n, &m, s);
    str = s;

    for(int i = 0; i < n; i++) {
        int c = str[i] - 'a';
        if(occ[c].empty()) meta.push_back(0);
        else meta.push_back(i - occ[c].back());
        occ[c].push_back(i);
    }

    h.compute(meta);

    while(m--) {
        scanf("%d %d %d", &l, &r, &len);
        l--; r--;
        printf("%s\n", (get(l, l + len - 1) == get(r, r + len - 1)) ? "YES" : "NO");
    }

    return 0;
}