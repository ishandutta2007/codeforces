#include <bits/stdc++.h>

#define b1 29//102811
#define M1 1000000021LL

#define b2 31//104729
#define M2 1000000009LL

#define MAXN 250250

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll chash[MAXN][2], mult[MAXN][2];
char s[MAXN];
vector <ll> st;
map <ll, vector<ll> > occ;
vector<pll> reps;

void calc() {
    mult[0][0] = mult[0][1] = 1;
	for(ll i=1; i < MAXN; i++) {
		mult[i][0] = (mult[i-1][0] * b1)%M1;
		mult[i][1] = (mult[i-1][1] * b2)%M2;
	}
}

void compute() {
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

bool cmp(pll a, pll b) {
    ll lena = a.second - a.first;
    ll lenb = b.second - b.first;

    if(lena == lenb) {
        return a < b;
    }
    return lena < lenb;
}

int main() {
    calc();

    int n;
    ll x;

    scanf("%d", &n);
    for(int i=0; i < n; i++) {
        scanf("%lld", &x);
        st.push_back(x);
        occ[x].push_back(i);
    }
    compute();
    for(pair<ll, vector<ll> > opa : occ) {
        int num = opa.first;
        vector<ll> pos = opa.second;

        for(int i=0;i<pos.size();i++) {
            for(int j=i+1;j<pos.size();j++) {
                int cthulhu = pos[j] - pos[i] - 1;
                if(pos[j] + cthulhu < n && substr(pos[i], pos[j]-1) == substr(pos[j], pos[j] + cthulhu))
                    reps.push_back({pos[i], pos[j] + cthulhu});
            }
        }
    }

    sort(reps.begin(), reps.end(), cmp);

    ll l = 0;
    for(pair<ll,ll> p : reps) {
        if(p.first >= l) {
            l = (p.first + p.second) / 2 + 1;
        }
    }

    printf("%d\n", n - l);
    for(int i=l;i<n;i++) printf("%d ", st[i]);

	return 0;
}