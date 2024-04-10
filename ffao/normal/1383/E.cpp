#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int mod = 1000000007;

vi pts;
vi nxt;

int memo[3100000];

int rec(int id) {
    int cur, want;
    if (id <= pts.size()) {
        cur = id;
        want = 0;
    }
    else {
        cur = nxt[id - (pts.size()+1)];
        want = pts[id - (pts.size()+1)] + 1;
    }

    if (cur == pts.size()) return 1;

    int &ret = memo[id];
    if (ret == -1) {
        ret = ((pts[cur] - want + 1) * 1ll * rec(cur+1)) % mod;
        ret = (ret + rec(cur + pts.size() + 1)) % mod;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;

    memset(memo,-1,sizeof(memo));

    int n = s.size();
    int la = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            pts.push_back(la);
            la = 0;
        }
        else la++;
    }
    pts.push_back(la);

    if (pts.size() == 1) {
        cout << n << '\n';
        return 0;
    }

    long long ans = 1;
    ans = (ans * 1ll * (pts[0]+1)) % mod;
    ans = (ans * 1ll * (pts.back()+1)) % mod;

    pts.erase(pts.begin());
    pts.pop_back();

    nxt.resize(pts.size());
    for (int i = pts.size()-1; i >= 0; i--) {
        nxt[i] = i+1;
        while (nxt[i] < pts.size() && pts[nxt[i]] <= pts[i] ) nxt[i] = nxt[nxt[i]];
    }

    ans = (ans * 1ll * rec(0)) % mod;
    
    cout << ans << endl;
    return 0;
}