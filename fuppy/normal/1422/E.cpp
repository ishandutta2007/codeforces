#include <bits/stdc++.h>

// #include <atcoder/all>

using namespace std;
// using namespace atcoder;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
#define int ll

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



void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<pair<char, int>> p;
    vector<pair<char, int>> num;
    vector<string> ans;
    vi ans2;
    rrep (i, s.size()) {
        if (p.size() == 0) {
            p.emplace_back(s[i], i);
            num.emplace_back(s[i], 1);
        }
        else if (p.back().second != i + 1) {
            if (p.back().first == s[i]) num.back().second++;
            else num.emplace_back(s[i], 1);
            p.emplace_back(s[i], i);
        }
        else {
            if (p.back().first != s[i]) {
                p.emplace_back(s[i], i);
                num.emplace_back(s[i], 1);
            }
            else {
                if (num.size() == 1) {
                    p.pop_back();
                    num.back().second--;
                    if (num.back().second == 0) num.pop_back();
                }
                else {
                    char cc = num[num.size() - 2].first;
                    assert(cc != s[i]);
                    if (cc > s[i]) {
                        p.emplace_back(s[i], i);
                        num.back().second++;
                    }
                    else {
                        p.pop_back();
                        num.back().second--;
                        if (num.back().second == 0) num.pop_back();
                    }
                }
            }
        }
        // DEBUG_VEC(p);
        // DEBUG_VEC(num);

        ans2.push_back(p.size());
        string t;
        if (p.size() <= 10) {
            rrep (i, p.size()) {
                t += p[i].first;
            }
        }
        else {
            rep (i, 5) {
                t += p[p.size() - 1 - i].first;
            }
            t += "...";
            rrep (i, 2) {
                t += p[i].first;
            }
        }
        ans.push_back(t);
    }
    reverse(all(ans));
    reverse(all(ans2));

    rep (i, ans.size()) {
        cout << ans2[i] << " " << ans[i] << '\n';
    }
}

signed main() {
    fio();

    int t = 1;
    // cin >> t;
    while (t--) solve();
}