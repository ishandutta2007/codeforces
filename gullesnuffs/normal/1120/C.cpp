#include <bits/stdc++.h>
#define MOD 9483728193453LL
#define MOD2 8593287637511LL
#define LIM 500000
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto &it : (v))
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

ll dp[5005];

int main(){
    vector<vector<pair<ll, int>>> exists(LIM);
	ios::sync_with_stdio(0);
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    unordered_map<ll, int> M[5005];
    rep(i,0,n+1)
        dp[i] = 1e9;
    dp[0] = 0;
    rep(i,0,n) {
        ll h1 = 24234;
        ll h2 = 2422;
        dp[i+1] = min(dp[i+1], dp[i] + a);
        rep(j,i,n) {
            h1 = (72831*h1+s[j])%MOD;
            h2 = (9572*h2+s[j])%MOD2;
            bool alreadyFound = false;
            for (auto it : exists[h1%LIM]) {
                if (it.first == h2 && it.second <= i) {
                    dp[j+1] = min(dp[j+1], dp[i] + b);
                    alreadyFound = true;
                    break;
                }
            }
            if (!alreadyFound) {
                if (j-i > n-j+10)
                    break;
                exists[h1%LIM].emplace_back(h2, j+1);
            }
        }
    }
    cout << dp[n] << endl;
}