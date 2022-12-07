#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const string S = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string T = "What are you doing while sending \".\"? Are you busy? Will you send \".\"?";
const string P = "What are you doing while sending \"";
const string Q = "\"? Are you busy? Will you send \"";
const string R = "\"?";
int n;
LL pos;
LL sz[100005];

char solve(int n, LL pos) {
    if (sz[n] < pos) {
        return '.';
    }
    if (n == 0) {
        return S[pos - 1];
    }
    if ((int)P.size() >= pos) {
        return P[pos - 1];
    }
    pos -= (int)P.size();
    if (sz[n - 1] >= pos) {
        return solve(n - 1, pos);
    }
    pos -= sz[n - 1];
    if ((int)Q.size() >= pos) {
        return Q[pos - 1];
    }
    pos -= (int)Q.size();
    if (sz[n - 1] >= pos) {
        return solve(n - 1, pos);
    }
    pos -= sz[n - 1];
    assert((int)R.size() >= pos);
    return R[pos - 1];
}

void init() {
    LL ssz = S.size();
    LL tsz = T.size();
    sz[0] = ssz;
    for (int i = 1; i < 100005; ++i) {
        sz[i] = sz[i - 1] * 2 + tsz - 2;
        sz[i] = min(sz[i], LL(3e18));
    }
    assert(P.size() + Q.size() + R.size() + 2 == T.size());
}

int main() {
    init();
    int tc;
    cin >> tc;
    string ans;
    forn(_, tc) {
        cin >> n >> pos;
        ans.pb(solve(n, pos));
    }
    cout << ans << endl;
    return 0;
}