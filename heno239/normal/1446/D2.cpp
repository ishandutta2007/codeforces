#pragma GCC optimize("Ofast")
#pragma GCC target ("sse4")

#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acosl(-1.0);


const int b = 800;
const int bd = (200000 + b - 1) / b;
vector<int> mp[bd][bd];
int mpsz[bd][bd];

int cnt[200001][bd];

int ccnt[200000];
int trans[200000];
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i]; a[i]--;
    }
    if (n == 1) {
        cout << 0 << "\n"; return;
    }

    vector<int> sz(n);
    rep(i, n)sz[a[i]]++;

    int ans = 0;

   
    rep1(i, b) {
        rep(j, n)ccnt[j] = 0;
        int tmp = 0;
        int l = 0;
        rep(r, n) {
            while (ccnt[a[r]] == i) {
                if (ccnt[a[l]] == i)tmp--;
                ccnt[a[l]]--;
                l++;
            }
            ccnt[a[r]]++;
            if (ccnt[a[r]] == i)tmp++;

            if (tmp >= 2) {
                ans = max(ans, r - l + 1);
            }
        }
    }


    vector<int> ids;
    rep(j, n)if (sz[j] > b) {
        trans[j] = ids.size();
        ids.push_back(j);
    }
    rep(i, n) {
        rep(j, ids.size()) {
            cnt[i + 1][j] = cnt[i][j];
        }
        if (sz[a[i]] > b) {
            cnt[i + 1][trans[a[i]]]++;
        }
    }


    rep1(i, n) {
        int z = a[i - 1];
        if (sz[z] > b) {
            for (int id : ids)if (id != z) {
                int dif = cnt[i][trans[z]] - cnt[i][trans[id]];
                mpsz[trans[z]][trans[id]] = max(mpsz[trans[z]][trans[id]], dif);
            }
        }
    }


    rep(i, bd)rep(j, bd)mp[i][j].resize(mpsz[i][j] + 1,mod);
    rep1(i, n) {
        int ma = -1, chk = -1;
        for (int id : ids) {
            if (cnt[i][trans[id]] > ma) {
                ma = cnt[i][trans[id]]; chk = id;
            }
        }
        if (ma < 0)continue;

        int tmp = 0;
        for (int id : ids) {
            if (cnt[i][trans[id]] == ma)tmp++;
        }
        if (tmp >= 2) {
            if(ma>b)ans = max(ans, i);
        }
        else {
            int mi = mod;
            for (int id : ids)if (id != chk) {
                int dif = cnt[i][trans[chk]] - cnt[i][trans[id]];
                if(dif<=mpsz[trans[chk]][trans[id]])mi = min(mi, mp[trans[chk]][trans[id]][dif]);
            }
            if (mi < mod) {
                int c = cnt[i][trans[chk]] - cnt[mi][trans[chk]];
                if (c > b) {
                    ans = max(ans, i - mi);
                }
            }
        }
        int z = a[i - 1];
        if (sz[z] > b) {
            for (int id : ids)if (id != z) {
                int dif = cnt[i][trans[z]] - cnt[i][trans[id]];
                if (dif > 0) {
                    mp[trans[z]][trans[id]][dif]= min(mp[trans[z]][trans[id]][dif], i);
                }
            }
        }
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout << fixed << setprecision(15);
    //init_f();
    //init();
    //expr();
    //int t; cin >> t; rep(i, t)
    solve();
    return 0;
}