#include <bits/stdc++.h>

#define MAXN 1000250

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

struct myhash {
	ll chash[MAXN][2];
	ll mult[MAXN][2];
	ll b1, M1, b2, M2;

	myhash(ll b1_ = 311, ll M1_ = 1000000021, ll b2_ = 317, ll M2_ = 1000000009) :
		b1(b1_), M1(M1_), b2(b2_), M2(M2_) { calc();}

	void calc() {
		mult[0][0] = mult[0][1] = 1;
		for(ll i=1; i < MAXN; i++) {
			mult[i][0] = (mult[i-1][0] * b1)%M1;
			mult[i][1] = (mult[i-1][1] * b2)%M2;
		}
	}

	void compute(string &st) {
		chash[0][0] = chash[0][1] = st[0] + 1;
		for(int i=1; i<(int)st.size();i++) {
			chash[i][0] = ((chash[i-1][0]*b1)%M1 + st[i] + 1)%M1;
			chash[i][1] = ((chash[i-1][1]*b2)%M2 + st[i] + 1)%M2;
		}
	}

	pll substr(ll l, ll r) {
		if(!l) return make_pair(chash[r][0], chash[r][1]);

		ll p1 = chash[r][0] - (chash[l-1][0] * mult[r-l+1][0])%M1;
        ll p2 = chash[r][1] - (chash[l-1][1] * mult[r-l+1][1])%M2;
        if(p1 < 0) p1 += M1;
        if(p2 < 0) p2 += M2;
		return make_pair(p1, p2);
	}
} h;


char s[MAXN];
string a, b;
int q0, q1, sz;

int main() {
    scanf("%s", s); a = s;
    scanf("%s", s); b = s; sz = (int)b.size();
    h.compute(b);

    if(a[0] == '1')
        for(int i = 0; i < (int)a.size(); i++)
            a[i] = (a[i] == '0') ? '1' : '0';

    for(char c : a) {
        if(c == '0') q0++;
        if(c == '1') q1++;
    }

    int ans = 0;
    for(int l = 1; l < sz; l++) {
        if(sz - l * q0 <= 0 || (sz - l * q0) % q1 != 0) continue;
        pll r0 = h.substr(0, l - 1), r1 = {-1, -1};
        int flag = 1, r = (sz - l * q0) / q1;

        for(int i = 1, j = l; flag && i < (int)a.size(); i++) {
            if(a[i] == '0') {
                if(r0 != h.substr(j, j+l-1)) flag = 0;
                j += l;
            } else {
                if(r1.first == -1) {
                    r1 = h.substr(j, j+r-1);
                    if(l == r && r0 == r1) flag = 0;
                }
                else if(r1 != h.substr(j, j+r-1)) flag = 0;
                j += r;
            }
        }

        if(flag) ans++;
    }
    printf("%d\n", ans);
	return 0;
}