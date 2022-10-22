#include <bits/stdc++.h>
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

ll getAns(vector<ll> a) {
    int n = sz(a);
    vector<ll> sum(n+1);
    sum[0]=0;
    rep(i,0,n) {
        sum[i+1]=sum[i]+a[i];
    }
    ll ans = 0;
    rep(l,0,n)
        rep(r,1,n+1) {
            ans = max(ans, (r-l)*(sum[r]-sum[l]));
        }
    return ans;
}

ll findAnswer(vector<ll> a) {
    int n = sz(a);
    int k = -1;
    ll res = 0;
    ll cur = 0;
    rep(i,0,n) {
        cur += a[i];
        if (cur < 0) {
            cur = 0;
            k = i;
        }
        res = max(res, (i-k)*cur);
    }
    return res;
}

int main(){
	ios::sync_with_stdio(0);
    ll k;
    cin >> k;
    ll l1 = 1000;
    ll l2 = 999;
    ll s2 = 2*k;
    ll s1 = -k;
    while (s1+l1 < 0) {
        s1 += l1;
        s2 -= l1 + l2;
    }
    cout << l1+l2 << endl;
    vector<ll> ans(l1+l2);
    rrep(i,l1,0) {
        ll sub = max(-1000000LL, s1);
        ans[i] = sub;
        s1 -= sub;
    }
    /*rep(i,0,l1) {
        ans[i] = s1/l1;
    }
    s1 -= ans[0] * l1;
    rrep(i,l1,0) {
        if (s1) {
            ans[i]--;
            ++s1;
        }
    }*/
    rep(i,l1,l1+l2) {
        ans[i] = s2/l2;
    }
    s2 -= ans[l1]*l2;
    rep(i,l1,l1+l2) {
        if (s2) {
            ++ans[i];
            --s2;
        }
    }
    for (auto x : ans) {
        assert(abs(x) <= 1000000);
        cout << x << " ";
    }
    cout << endl;
    /*cerr << findAnswer(ans) << endl;
    cerr << getAns(ans) << endl;
    assert(findAnswer(ans) + k == getAns(ans));*/
}