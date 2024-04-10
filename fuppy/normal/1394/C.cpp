#include <bits/stdc++.h>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
// #define int ll
 
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

#define ci complex<ll>
//x,y\[g
bool cmp_x(const ci p, const ci q) {
	if (p.real() != q.real()) return p.real() < q.real();
	return p.imag() < q.imag();
}

//uxNga,bO
ll det(ci a, ci b) {
	return a.real()*b.imag() - b.real()*a.imag();
}

//uxNga,b
ll dot(ci a, ci b) {
	return a.real()*b.real() + a.imag()*b.imag();
}

//ps: SW, n: WBW
vector<ci> convex_hull(vector<ci> ps, int n) {
	sort(ps.begin(), ps.end(), cmp_x);
	int k = 0; //_
	vector<ci> qs(n * 2); //\z
	for (int i = 0; i < n; i++) {
		while (k > 1 && det(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) <= 0) k--;
		qs[k++] = ps[i];
	}
	for (int i = n - 2, t = k; i >= 0; i--) {
		while (k > t && det(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) <= 0) k--;
		qs[k++] = ps[i];
	}
	qs.resize(k - 1);
	return qs;
}


void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<ci> temp;
    pii mi(inf, inf), ma(-inf, -inf);
    rep (i, n) {
        cin >> s[i];
        int x = 0, y = 0;
        rep (j, s[i].size()) {
            if (s[i][j] == 'B') x++;
            else y++;
        }
        chmin(mi, pii(x, y));
        chmax(ma, pii(x, y));
        temp.push_back(ci(x, y));
    }

    temp = convex_hull(temp, temp.size());
    temp.push_back(ci(mi.first, mi.second));
    temp.push_back(ci(ma.first, ma.second));

    int yl = 0, yr = 500000;
    auto f = [&](int y) {
        auto g = [&](int x) {
            int ma = -inf;
            rep (i, temp.size()) {
                int xx = temp[i].real(), yy = temp[i].imag();
                if ((ll)(xx - x) * (yy - y) >= 0) {
                    chmax(ma, max(abs(xx - x), abs(yy - y)));
                }
                else {
                    chmax(ma, abs(xx - x) + abs(yy - y));
                }
            }
            return ma;
        };
        int xl = 0, xr = 500000;
        while (xl + 2 < xr) {
            int x1 = (2 * xl + xr) / 3, x2 = (xl + 2 * xr) / 3;
            if (g(x1) > g(x2)) {
                xl = x1;
            }
            else {
                xr = x2;
            }
        }

        int mi = inf;
        int res_x = -1;
        for (int i = xl; i <= xr; i++) {
            int v = g(i);
            if (v <= mi) {
                mi = v;
                res_x = i;
            }
        }
        return pii(mi, res_x);
    };
    while (yl + 2 < yr) {
        int y1 = (2 * yl + yr) / 3, y2 = (yl + 2 * yr) / 3;
        int xl = 0, xr = 50000;
        pii temp1 = f(y1), temp2 = f(y2);
        if (temp1.first > temp2.first or (temp1.first == temp2.first and temp1.second < temp2.second)) yl = y1;
        else yr = y2;
    }

    int ans = inf;
    int res_x=0, res_y=0;
    for (int i = yl; i <= yr; i++) {
        pii temp = f(i);
        int v = temp.first, x = temp.second;
        if (v < ans or v == ans and res_x < x) {
            ans = v;
            res_x = x;
            res_y = i;
        }
    }
    cout << ans << endl;
    rep (i, res_x) cout << 'B';
    rep (i, res_y) cout << 'N';
    cout << endl;
}


signed main() {
    fio();

    int t = 1;
    // cin >> t;
    while (t--) solve();
}