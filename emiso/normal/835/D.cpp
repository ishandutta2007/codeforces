#include <bits/stdc++.h>

#define b1 311
#define M1 1000000021LL

#define b2 317
#define M2 1000000009LL

#define MAXN 5100

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll chash[MAXN][2], mult[MAXN][2];
char s[MAXN];
string st;

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

int ans[MAXN];
bool isp[MAXN][MAXN];

void palis() {
    string str = st;

    for(int i=0; i<(int)str.size(); i++) {
		isp[i][i] = 1;
		if(i && str[i] == str[i-1]) isp[i-1][i] = 1;
	}

	for(int i=2; i<(int)str.size(); i++) {
		for(int p=0; p + i < (int)str.size(); p++) {
			if(str[p] == str[p + i] && isp[p+1][p+i-1]) isp[p][p+i] = 1;
		}
	}
}

struct no {
    int l, r;
};

short int mask[MAXN][MAXN];

int main() {
    calc();
    scanf("%s", s);
    st = s;

    //for(int i=0;i<5000;i++) st += 'a';
    palis();
    compute();

    queue<no> fila;

    int n = st.size();
    for(int i=0; i<n; i++) {
        for(int j=0; j+i<n; j++) {
            if(isp[j][j+i]) {
                fila.push({j, j+i});
                mask[j][j+i] |= 2;
            }
        }
    }

    while(!fila.empty()) {
        no f = fila.front(); fila.pop();
        int l = f.l, r = f.r, siz = r - l + 1;

        if(r + siz < n && substr(l, r) == substr(r+1, r+siz)) {
            mask[l][r+siz] |= (mask[l][r] << 1);
        }

        if(r + siz + 1 < n && substr(l, r) == substr(r + 2, r + siz + 1)) {
            mask[l][r+siz+1] |= (mask[l][r] << 1);
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            if(isp[i][j]) {
                for(int k=1;k<=13;k++) {
                    ans[k] += ((mask[i][j] & (1 << k)) ? 1 : 0);
                }
            }
        }
    }

    for(int i=1; i<=n; i++) {
        printf("%lld ", ans[i]);
    }

	return 0;
}