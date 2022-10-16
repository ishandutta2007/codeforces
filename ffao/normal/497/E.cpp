#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

const int mod = 1000000007;
long long n;
int k;

int s(long long p, int l) {
    int r = 0;
    while (p > 0){
        int d = p % l;
        p /= l;
        r += d;
    }
    return r % l;
}

vi gt(int x) {
    vector<int> t(k+1, 0);
    t[x]++;
    return t;
}

void sub(vi& t1, const vi& t2) {
    for (int i = 0; i < (int)t1.size(); i++) {
        t1[i] = (t1[i]-t2[i]) % mod;
    }
}

void add(vi& t1, const vi& t2) {
    for (int i = 0; i < (int)t1.size(); i++) {
        t1[i] = (t1[i]+t2[i]) % mod;
    }
}

void mul(int m, vi& t) {
    for (int i = 0; i < (int)t.size(); i++) {
        t[i] = (t[i] * 1ll * m) % mod;
    }
}

vvi man(long long a, long long b) {
    vi last = vi(k, -1);
    vvi dp;

    for (int x = 0; x < min((long long) k+1, b-a+1); x++) {
        dp.push_back(gt(x));
    }

    for (long long x = a; x < a+k; x++) {
        int this_s = s(x, k);
        last[this_s] = x - a;
    }

    for (long long x = a+k; x < b; x++) {
        int this_s = s(x, k);
        dp.push_back(dp.back());
        mul(2, dp.back() );
        sub(dp.back(), dp[last[this_s]]);
        last[this_s] = x-a;
    }

    vvi ret(dp.end() - std::min((int) dp.size(), k+1), dp.end());
    return ret;
}

vi get_last(long long st, long long ed) {
    vi ret;
    long long x = max(st, ed-k);
    while (x < ed) {
        ret.push_back(s(x, k));
        x++;
    }
    return ret;
}

vi get_first(long long st, long long ed) {
    vi ret;
    long long lim = min(st+k, ed);
    long long x = st;
    while (x < lim) {
        ret.push_back(s(x, k));
        x++;
    }
    return ret;
}

vi compose(vi vals, vvi fs) {
    long long tt[k+1];
    for (int x = 0; x < k+1; x++) tt[x]=0;
    
    vector<long long> t(k+1, 0);
    for (int x = 0; x < (int)vals.size(); x++) { 
        for (int j = 0; j < fs[x].size(); j++) {
            tt[j] = (tt[j] + (fs[x][j] * 1ll * vals[x]));
        }
    }
    for (int j = 0; j < fs[0].size(); j++) tt[j] %= mod;
    
    return vector<int>(tt, tt+(k+1));
}

map<long long int, vvi> ca;

vvi calc(long long st, long long ed) {
    if (st == 0 && ca.count(ed)) {
        return ca[ed];
    }

    long long total = ed - st;
    if (total <= 100) {
        return man(st, ed);
    }

    long long mid = k;
    while (total/k > mid) mid *= k;

    vvi ans1 = calc(0, mid);
    vvi ans2 = calc(mid, total);

    vi last1 = get_last(st, st+mid);
    vi first1 = get_first(st+mid, ed);

    vi val = ans1.back();
    
    vvi firsts;

    firsts.push_back(val);

    for (int x : first1) {
        mul(2, val);
        for (int idx = 0; idx < (int)last1.size(); idx++) {
            if (last1[idx] == x) {
                sub(val, ans1[idx]);
                break;
            }
        }

        firsts.push_back(val);
    }

    firsts.resize(k+1, vi(0, k+1));

    vvi ans;
    for (vi resp : ans2) {
        vi th = compose(resp, firsts);
        ans.push_back(th);
    }

    if (st == 0) ca[ed] = ans;
    return ans;
}

int main() {
    scanf("%lld %lld",&n, &k);

    vvi ans = calc(0, n);
    long long resp = 0;

    long long pot = 1;
    for (int idx = 0; idx < (int)ans.back().size(); idx++) {
        resp = (resp + (pot * ans.back()[idx])) % mod;
        pot = (pot * 2) % mod;
    }

    printf("%lld\n", ((resp % mod) + mod) % mod);
}