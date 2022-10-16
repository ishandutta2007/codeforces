#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";

ostream& operator<<(ostream& cerr, vector<ll> aux) {
    cerr << "[";
    for (auto e : aux) cerr << e << ' ';
    cerr << "]";
    return cerr;
}

const int maxN = 200011;

struct aib {
    ll data[maxN];
    ll n;

    void init(ll _n) {
        n = _n;
        for (ll i = 1; i <= n; i++)
            data[i] = 0;
    }

    ll zrs(ll x) {
        return (x ^ (x - 1)) & x;
    }

    void add(ll x, ll v) {
        while (x <= n) {
            data[x] += v;
            x += zrs(x);
        }
    }

    ll src(ll x) {
        ll ans = 0;
        for (ll step = 1 << 20; step > 0; step >>= 1)
            if (ans + step <= n)
                if (data[ans + step] < x)
                    x -= data[ans + step], ans += step;
        return ans;
    }

    ll sum(ll x) {
        ll ans = 0;
        while (x > 0) {
            ans += data[x];
            x -= zrs(x);
        }
        return ans;
    }
};

ll t, ti;
ll n, m, i, j, limit;
ll p[maxN];
vector< pair<ll, ll> > ord;
aib sum, cnt;
pair<ll, ll> ans;

ll run() {
    ll pos_big = sum.src((limit / 2) + 1);
    ll cnt_big = cnt.sum(pos_big);
    cnt_big -= cnt_big % m;

    ll where = cnt.src(cnt_big + 1);
    ll sum_big = sum.sum(where);

    ll pos = sum.src((limit - sum_big) + 1);
    ll cnt_final = cnt.sum(pos);
    cnt_final -= cnt_big;
    cnt_final = min(cnt_final, m);

    return cnt_final + cnt_big;
}

void solve() {
    ll i, j;

    sort(ord.begin(), ord.end());
    for (i = 0; i < ord.size(); i = j) {

        if (ord[i].first > limit) break;

        for (j = i; j < ord.size(); j++) {
            if (ord[j].first != ord[i].first) break;
            auto act = ord[j];
            cnt.add(act.second, 1);
            sum.add(act.second, act.first);
        }

        ll aux = run();
        ans = max(ans, mp(aux, ord[i].first));
    }
    
}

int main()
{
    //freopen("test.in","r",stdin);
    
    scanf("%I64d", &t);
    for (ti = 1; ti <= t; ti++) {
        scanf("%I64d%I64d%I64d", &n, &m, &limit);
        ord.clear();
        for (i = 1; i <= n; i++) {
            scanf("%I64d", &p[i]);
            ord.pb(mp(p[i], i));
        }
        sum.init(n);
        cnt.init(n);

        ans = mp(0, 1);
        solve();
        printf("%I64d %I64d\n", ans.first, ans.second);
    }





    return 0;
}