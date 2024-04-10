#include <bits/stdc++.h>

#define MAXN 101000

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll mult[MAXN][2];

struct myhash {
	ll chash[MAXN][2];
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
	void compute(vector<int> &st) {
		chash[0][0] = chash[0][1] = st[0] + 1;
		for(int i=1; i<(int)st.size();i++) {
			chash[i][0] = ((chash[i-1][0]*b1)%M1 + st[i] + 1)%M1;
			chash[i][1] = ((chash[i-1][1]*b2)%M2 + st[i] + 1)%M2;
		}
	}
	pll substr(ll l, ll r) {
		if(!l) return make_pair(chash[r][0], chash[r][1]);

		ll p1 = (chash[r][0] - (chash[l-1][0] * mult[r-l+1][0])%M1 + M1)%M1;
		ll p2 = (chash[r][1] - (chash[l-1][1] * mult[r-l+1][1])%M2 + M2)%M2;
		return make_pair(p1, p2);
	}
} h[11];


int n, m, x, app[100010][11];
vector<int> seq[11];

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &x);
            seq[i].push_back(x);
            app[x][i] = j;
        }
        h[i].compute(seq[i]);
	}
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int l = i, r = n-1, mid;
        while(l < r) {
            mid = (l + r + 1) / 2;
            int flag = 1;

            pll tgt = h[0].substr(i, mid);
            for(int j = 1; flag && j < m; j++) {
                int p = app[seq[0][i]][j];
                if(p + mid - i >= n) flag = 0;
                else if(h[j].substr(p, p + mid - i) != tgt) flag = 0;
            }

            if(flag) l = mid;
            else r = mid - 1;
        }
        ans += (l - i + 1);
    }

    printf("%lld\n", ans);
	return 0;
}