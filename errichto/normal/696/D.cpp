#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const ll M = 1000 * 1000 * 1000;
const ll inf = 3 * M * M;
const int nax = 215;

int in_add[nax];
string sl[nax];
string impo[nax];
int val[nax];
bool e[nax][nax];
ll t[nax][nax], ans[nax][nax];
ll nowy[nax][nax];

bool nd_pre(const string & caly, const string & b) {
    int roz = int(caly.length()) - int(b.length());
    if(roz >= 0 && b == caly.substr(roz, b.length()))
        return true;
    return false;
}

int main() {
    int n;
    ll L;
    cin >> n >> L;
    REP(i, n) cin >> in_add[i];;
    REP(i, n) cin >> sl[i];
    set<string> prefy;
    REP(i, n) FOR(j, 0, (int) sl[i].length())
        prefy.insert(sl[i].substr(0, j));
    int start_n = n;
    n = 0;
    for(string ple : prefy)
        impo[n++] = ple;
    assert(n < nax);
    assert(impo[0] == string(""));
    REP(i, n)
        REP(j, start_n)
            if(nd_pre(impo[i], sl[j]))
                val[i] += in_add[j];
    REP(i, n) RI(j, n - 1) {
        int len = impo[j].length();
        assert(len >= 1);
        string tmp = impo[j].substr(0, len - 1);
        if(nd_pre(impo[i], tmp))
            e[i][j] = true;
    }
    REP(i, n) REP(j, n) {
        if(e[i][j]) t[i][j] = val[j];
        else t[i][j] = -inf;
    }
    REP(i, n) REP(j, n) {
        ans[i][j] = -inf;
    }
    ans[0][0] = 0;
    while(L) {
        if(L % 2) {
            // ans *= t
            REP(i, n) REP(j, n) nowy[i][j] = -inf;
            REP(i, n) REP(j, n) REP(k, n)
                maxi(nowy[i][k], ans[i][j] + t[j][k]);
            REP(i, n) REP(j, n) ans[i][j] = nowy[i][j];
        }
        // t *= t
        REP(i, n) REP(j, n) nowy[i][j] = -inf;
        REP(i, n) REP(j, n) REP(k, n)
            maxi(nowy[i][k], t[i][j] + t[j][k]);
        REP(i, n) REP(j, n) t[i][j] = nowy[i][j];
        L /= 2;
    }
    ll x = -1;
    REP(i, n) maxi(x, ans[0][i]);
    assert(x >= 0);
    printf("%lld\n", x);
    return 0;
}