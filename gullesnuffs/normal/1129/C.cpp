#include <bits/stdc++.h>
#define MOD 1000000007
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


typedef long long H;
static const H M = INT_MAX;
H C[2]; // initialized below


ll dp[3005][3005];
bool ok[3005][3005];
vector<int> S;
#define HASH_NUM 2
ll Hash[HASH_NUM][3005][3005];

bool isOk(int l, int r) {
    if (r-l > 4)
        return false;
    if (r-l <= 0)
        return false;
    if (l < 0)
        return false;
    string s;
    rep(i,l,r) {
        if(S[i])
            s.push_back('1');
        else
            s.push_back('0');
    }
    if (s == "0011")
        return false;
    if (s == "0101")
        return false;
    if (s == "1110")
        return false;
    if (s == "1111")
        return false;
    return true;
}

#include <sys/time.h>

int main(){
	ios::sync_with_stdio(0);

    C[1] = (ll)1e9+7; // (order ~ 3e9; random also ok)
    timeval tp;
    gettimeofday(&tp, 0);
    C[0] = tp.tv_usec;
    int m;
    cin >> m;
    S.resize(m);
    rep(i,0,m) {
        cin >> S[i];
    }
    rep(i,0,m+1)
        rep(j,0,m+1)
            ok[i][j] = isOk(i, j);
    rep(i,0,m) {
        Hash[0][i][i] = 0;
        Hash[1][i][i] = 0;
        rep(j,i+1,m+1) {
            rep(k,0,HASH_NUM)
                Hash[k][i][j] = (Hash[k][i][j-1] * C[k] + S[j-1])%M;
            if (ok[i][j]) {
                ++dp[i][j];
            }
            rep(k,max(0, j-4),j) {
                if (ok[k][j]) {
                    dp[i][j] += dp[i][k];
                }
            }
            dp[i][j] %= MOD;
        }
    }
    string s;
    rep(i,0,m) {
        if(S[i])
            s.push_back('1');
        else
            s.push_back('0');
    }
    //ll ans = 0;
    vector<ll> ans(m+1);
    rep(len,1,m+1) {
        unordered_set<ll> seen[HASH_NUM];
        rep(i,0,m) {
            int j = i + len;
            if (j > m)
                break;
            bool isOk = false;
            rep(k,0,HASH_NUM) {
                auto key = Hash[k][i][j];
                if (!seen[k].count(key)) {
                    isOk = true;
                    seen[k].insert(key);
                }
            }
            if (isOk) {
                ans[j-1] += dp[i][j];
            }
        }
    }
    rep(j,0,m) {
        if (j)
            ans[j] += ans[j-1];
        ans[j] %= MOD;
        cout << ans[j] << endl;
    }
    /*rep(j,1,m+1) {
        rep(i,0,j) {
            auto key1 = Hash[0][i][j];
            //auto key2 = Hash[1][i][j];
            if (seen1[j-i].count(key1))
                continue;
            //if (seen2[j-i].count(key2))
            //    continue;
            seen1[j-i].insert(key1);
            //seen2[j-i].insert(key2);
            ans += dp[i][j];
        }
        ans %= MOD;
        cout << ans << endl;
    }*/
    exit(0);
}