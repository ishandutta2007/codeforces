#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define fst first
#define snd second

#define FILE_NAME "a"

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MAXN = 100500;
const int ALPH = 30;

int n;
string s[MAXN];
int cnt[ALPH];
vi g[ALPH];
bool is_leaf[ALPH];
bool used[ALPH];

bool read() {
    if (scanf("%d", &n) < 1) {
        return 0;
    }
    
    forn(i, n) {
        cin >> s[i];
    }
    
    return 1;
}
    
bool solve() {
        
    forn(i, n) {
        memset(cnt, 0, sizeof(cnt));
    
        forn(j, sz(s[i])) {
            cnt[s[i][j] - 'a']++;
        }
        forn(j, ALPH) {
            if (cnt[j] > 1) {
                return false;
            }
        }
    }
    
    // now strings are permutations    
    
    memset(cnt, 0, sizeof(cnt));
        
    forn(i, n) {
        forn(j, sz(s[i])) {
            cnt[s[i][j] - 'a']++;
        }
    }
    
    forn(i, ALPH) {
        g[i].clear();                
    }
    
    forn(i, n) {
        forn(j, sz(s[i]) - 1) {
            g[(s[i][j] - 'a')].pb(s[i][j + 1] - 'a');                
        }
    }
    
    forn(i, ALPH) {
        sort(all(g[i]));
        g[i].resize(unique(all(g[i])) - g[i].begin());
    }
    
    forn(i, ALPH) {
        if (sz(g[i]) > 1) {
            return false;
        }
    }
    
    string res = "";
    forn(i, ALPH) {
        used[i] = 0;
        is_leaf[i] = 1;
    }
    
    forn(i, ALPH) {
        for (auto to: g[i]) {
            is_leaf[to] = 0;
        }
    }
    
    int rest = 0;
    forn(i, ALPH) {
        rest += (cnt[i] > 0);
    }
    //cerr << rest << endl;
    
    forn(i, ALPH) {
        int s = -1;
        forn(j, ALPH) {
            if (cnt[j] > 0 && !used[j] && is_leaf[j]) {
                s = j;
                break;   
            }
        }
        
        if (s == -1) {
            break;
        }
        
        while (true) {
            //cerr << char('a' + s) << endl;
            if (used[s]) {
                return false;
            }
            
            used[s] = 1;
            rest--;
            res += (char)('a' + s);

            if (g[s].empty()) {
                break;
            }
            
            s = g[s][0];
        }
    }
    
    assert(rest >= 0);
    if (rest != 0) {
        return false;
    }
    
    cout << res << '\n';
    
    return true;
}

int main() {
#ifdef LOCAL
    freopen(FILE_NAME ".in", "r", stdin);
    //freopen(FILE_NAME ".out", "w", stdout);
#endif    
    
    while (read()) {
        if (!solve()) {
            cout << "NO" << '\n';
        }
    }
    
    return 0;
}