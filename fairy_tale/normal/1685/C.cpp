#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t << 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#define endl '\n'
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, int> PL;

const int maxn = 2e5 + 5;
const int mod = 998244353;

string s;

void solve()
{
    int n;
    cin >> n;
    cin >> s;
    n <<= 1;

    int l = -1, Lmax = 0, Lnow = 0, idL = -1;
    int r = n, Rmin = 0, Rnow = 0, idR = n;
    int u = 1, v = -1;

	vector<P> op;
    while (true) {
        while (l + u != r && Lnow >= 0) {
			l += u;
            Lnow += (s[l] == '(' ? 1 : -1);
			if (Lnow > Lmax) {
				Lmax = Lnow;
				idL = l;
			}
        }

        while (r + v != l && Rnow <= 0) {
			r += v;
            Rnow += (s[r] == '(' ? 1 : -1);
            if (Rnow < Rmin) {
				Rmin = Rnow;
				idR = r;
			}
        }

        if (Lnow >= 0 && Rnow <= 0) break;

        //cout << l << " " << r << endl;
		op.push_back(P(idL + u, idR + v));
		swap(l, r);
		swap(u, v);
		Lnow -= Lmax;
		Rnow -= Rmin;
		swap(Lnow, Rnow);
		Lnow = Lmax = Lnow + Lmax;
		Rnow = Rmin = Rnow + Rmin;
		idL = l;
		idR = r;
    }

	int m = op.size();
	if (m > 1) {
		cout << 2 << endl;
		Lnow = Lmax = 0;
		idL = -1;
		for (int i = 0; i < n; i++) {
			Lnow += (s[i] == '(' ? 1 : -1);
			if (Lnow > Lmax) {
				Lmax = Lnow;
				idL = i;
			}
		}
		cout << 1 << " " << idL + 1 << "\n" << idL + 2 << " " << n << endl;
		return;
	}

	cout << m << endl;
	for (int i = m - 1; i >= 0; i--) {
		if (op[i].fi > op[i].se) swap(op[i].fi, op[i].se);
		cout << op[i].fi + 1 << " " << op[i].se + 1 << endl;
	}
}

int main()
{
#ifdef FEIFEI
    //freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int pT = 1;
    cin >> pT;
    while (pT--) {
        solve();
    }

    //Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}