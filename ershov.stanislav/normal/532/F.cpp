#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

const int N = 200200;
const int P = 1e9 + 7, Q = 1e9 + 9;
const int M = 29;

int lens, lent, last[26];
char s[N], t[N];
ll hsP[N], htP[26];
ll hsQ[N], htQ[26];

ll get_pow(ll a, ll p, ll MOD) {
    ll ans = 1;
    while (p) {
        if (p & 1) {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        p >>= 1;
    }
    return ans;
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d %s %s", &lens, &lent, s, t);
//    cout << s << ' ' << t << endl;
    int slen = lens, tlen = lent;
    for (int i = 1; i <= lens; i++) {
        hsP[i] = (hsP[i - 1] * M + s[i - 1] - 'a') % P;
        hsQ[i] = (hsQ[i - 1] * M + s[i - 1] - 'a') % Q;
    }
    for (int j = 0; j < 26; j++) {
        for (int i = 1; i <= lent; i++) {
            int c = (t[i - 1] == (char)j + 'a');
            htP[j] = (htP[j] * M + (int) c) % P;
            htQ[j] = (htQ[j] * M + (int) c) % Q;
        }
//        cout << htP[j] << ' ' <<  htQ[j] << endl;
    }
    for (int i = 0; i < 26; i++) {
        last[i] = INF;
    }
    vector<int> ans;
    for (int i = slen - 1; i >= 0; i--) {
        last[s[i] - 'a'] = i;
        if (i <= slen - tlen) {
            vector<int> v(26);
            for (int j = 0; j < 26; j++) {
                v[j] = -1;
            }
            bool flag = true;
            for (int j = 0; j < 26; j++) {
                if (last[j] < i + tlen) {
                    int r = t[last[j] - i] - 'a';
                    if (v[j] != r && v[j] != -1) {
                        flag = false;
                        break;
                    }
                    if (v[r] != j && v[r] != -1) {
                        flag = false;
                        break;
                    }
                    v[r] = j;
                    v[j] = r;
                }
            }
//            for (int i = 0; i < 26; i++) {
//                cout << v[i] << ' ';
//            }
//            cout << endl;
//            cout << "flag: " << flag << endl;
            if (flag) {
                for (int j = 0; j < 26; j++) {
                    if (v[j] == -1) {
                        v[j] = j;
                    }
                }
                ll hashP = 0, hashQ = 0;
                for (int j = 0; j < 26; j++) {
                    hashP = (hashP + htP[v[j]] * j) % P;
                    hashQ = (hashQ + htQ[v[j]] * j) % Q;
                }
//                cout << hashP << ' ' << hashQ << endl;
                if (hashP % P == ( (hsP[i + tlen] - hsP[i] * get_pow(M, tlen, P)) % P + P) % P) {
                    if (hashQ % Q == ( (hsQ[i + tlen] - hsQ[i] * get_pow(M, tlen, Q)) % Q + Q) % Q) {
                        ans.pb(i);
                    }
                }
            }
        }
    }
    reverse(all(ans));
    printf("%d\n", (int) ans.size());
    for (int i = 0; i < (int) ans.size(); i++) {
        printf("%d ", ans[i] + 1);
    }
    return 0;
}