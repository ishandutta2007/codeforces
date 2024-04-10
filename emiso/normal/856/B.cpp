#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define MAXN 1000100

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long long pll;

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

	void compute(string &st) {
		chash[0][0] = chash[0][1] = st[0] + 1;
		for(int i=1; i<(int)st.size(); i++) {
			chash[i][0] = (chash[i-1][0] * b1 + st[i] + 1)%M1;
			chash[i][1] = (chash[i-1][1] * b2 + st[i] + 1)%M2;
		}
	}

	pll substr(ll l, ll r) {
		if(!l) return 1000000000LL * chash[r][0] + chash[r][1];
		ll p1 = (chash[r][0] - (chash[l-1][0] * mult[r-l+1][0])%M1 + M1)%M1;
		ll p2 = (chash[r][1] - (chash[l-1][1] * mult[r-l+1][1])%M2 + M2)%M2;
		return 1000000000LL * p1 + p2;
	}
};

char s[MAXN];
string st;

int vis[1000100], mark[1000100], n, t;

int dfs(int no, vector<vector<int>> &adj, int pai = 1000010) {
    vis[no] = t;
    int flag = 1, ret = 0;
    for(int v : adj[no]) {
        if(v == pai) continue;
        ret += dfs(v, adj, no);
        if(mark[v]) flag = 0;
    }
    mark[no] = flag;
    return ret + flag;
}

unsigned hash_f(unsigned x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}
struct chash {
    int operator()(int x) const { return hash_f(x); }
};

int main() {
	myhash h;
    scanf("%d", &t);
    while(t) {
        scanf("%d", &n);

        gp_hash_table<ll, ll, chash> prf;
        gp_hash_table<ll, int, chash> TC; int cnt = 0;
        vector<vector<int>> adj;

        for(int i = 0; i < n; i++) {
            scanf("%s", s); st = s;
            h.compute(st);
            for(int j = 0; j < st.size(); j++) {
                pll x = h.substr(0, j), y = -1;
                if(j) y = h.substr(1, j);
                prf[x] = y;

                if(TC.find(x) == TC.end()) TC[x] = cnt++;
            }
        }

        adj.resize(cnt);
        for(auto tt : prf) {
            if(prf.find(tt.second) != prf.end()) {
                int x = TC[tt.first], y = TC[tt.second];
                adj[x].push_back(y);
                adj[y].push_back(x);
            }
        }

        int ans = 0;
        for(int i = 0; i < cnt; i++)
            if(vis[i] != t)
                ans += dfs(i, adj);

        printf("%d\n", ans);
        t--;
    }
	return 0;
}