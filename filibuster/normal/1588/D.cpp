//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vint = vector<int>;
using matr = vector<vint>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 10;
const int M = 1e9 + 9;
const ld eps = 1e-6;
const int K = 103;
const int LOGN = 22;
const int A = 52;


/*
*/

int n;

int dp[A][1 << N];
pii p[A][1 << N];

int pos[N][A][2];

ld ord[A][1 << N];
//string s[N];

//void calc(int x, int mask) {
//    for(int y = 0; y < A; y++) {
//        int nmask = 0;
//
//        for(int i = 0; i < n; i++) {
//            if(pos[i][y][1] <= pos[i][x][(mask >> i) & 1])
//                return;
//
//            if(pos[i][y][0] <= pos[i][x][(mask >> i) & 1])
//                nmask |= (1 << i);
//        }
//
//        if(dp[y][nmask] < dp[x][mask]) {
//            dp[y][nmask] = dp[x][mask];
//            p[y][nmask] = {x, mask};
//        }
//    }
//}

/*
1
2
ABC
CBA

1
3
abcde
aBcDe
ace
*/


void solve() {

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < A; j++) {
            for(int k = 0; k < 2; k++)
                pos[i][j][k] = -1;
        }
    }

    for(int x = 0; x < A; x++) {
        for(int mask = 0; mask < (1 << n); mask++) {
            dp[x][mask] = 0;
            p[x][mask] = {-1, -1};
        }
    }

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for(int j = 0; j < s.size(); j++) {
            int x;
            if('A' <= s[j] && s[j] <= 'Z')
                x = s[j] - 'A';
            else
                x = s[j] - 'a' + 26;

            if(pos[i][x][1] == -1)
                pos[i][x][1] = j;
            else {
                pos[i][x][0] = pos[i][x][1];
                pos[i][x][1] = j;
            }
        }
    }
//cout << "sag" << endl;
    vector<pair<ld, pii>> ts;

    for(int x = 0; x < A; x++) {
        for(int mask = 0; mask < (1 << n); mask++) {
            ord[x][mask] = 0;
            for(int i = 0; i < n; i++) {
                if(pos[i][x][(mask >> i) & 1] == -1) {
                    ord[x][mask] = -1;
                    break;
                }
                ord[x][mask] = ord[x][mask] * A * 2 + pos[i][x][(mask >> i) & 1];
            }
            ts.emplace_back(ord[x][mask], make_pair(x, mask));
        }
    }
//cout << "sag" << endl;
    sort(ts.begin(), ts.end());

    int mxx = -1, mxmask = -1;

    for(auto pr : ts) if(pr.f != -1) {
        int x = pr.s.f, mask = pr.s.s;

        dp[x][mask] = max(dp[x][mask], 1);

        if(dp[x][mask] > 0 && (mxx == -1 || dp[mxx][mxmask] < dp[x][mask])) {
            mxx = x;
            mxmask = mask;
        }

//        cout << x << ' ' << mask << ' ' << dp[x][mask] << endl;

        for(int y = 0; y < A; y++) {
            int nmask = 0;
            bool fl = false;

            for(int i = 0; i < n; i++) {
                if(pos[i][y][1] <= pos[i][x][(mask >> i) & 1]) {
                    fl = true;
                    break;
                }


                if(pos[i][y][0] <= pos[i][x][(mask >> i) & 1])
                    nmask |= (1 << i);
            }

//            if(!fl)
//                cout << "go " << x << ' ' << mask  << " -> " << y << ' ' << nmask << endl;
            if(!fl && dp[y][nmask] < dp[x][mask] + 1) {
                dp[y][nmask] = dp[x][mask] + 1;
                p[y][nmask] = {x, mask};
            }
        }
    }

//    cout << mxx << ' ' << mxmask << endl;

    if(mxx == -1) {
        cout << 0 << endl << endl;
        return;
    }
//cout << mxx << ' ' << mxmask << ' ' << dp[mxx][mxmask] << endl;
    string s = "";
    int x = mxx, mask = mxmask;
    while(true) {
        s += (x >= 26 ? char('a' + x - 26) : char('A' + x));
        pii pr = p[x][mask];
        x = pr.f;
        mask = pr.s;
        if(x == -1)
            break;
    }

    reverse(s.begin(), s.end());

    cout << s.size() << endl;
    cout << s << endl;
}

signed main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}