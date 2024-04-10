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

int S(int x) {
    if (x < 10)
        return x;
    int s = 0;
    while(x) {
        s += x%10;
        x /= 10;
    }
    return S(s);
}

map<pair<int, int>, vector<ll>> cache;

vector<ll> add(int digits, int sum) {
    pair<int, int> key = make_pair(digits, sum);
    if (cache.count(key))
        return cache[key];
    vector<ll> ans(10);
    if (digits == 0) {
        ans[S(sum)]++;
        return ans;
    }
    rep(i,0,10) {
        vector<ll> ret = add(digits-1, sum+i);
        rep(j,0,10)
            ans[j] += ret[j];
    }
    cache[key] = ans;
    return ans;
}

int main(){
	ios::sync_with_stdio(0);
    int n;
    cin >> n;
    while(n--) {
        ll k, x;
        cin >> k >> x;
        ll ten = 1;
        rep(i,0,18)
            ten *= 10;
        ll ans = 0;
        int sum = 0;
        rrep(i,19,0) {
            rep(j,0,9) {
                //cerr << i << " " << j << " " << add(i, sum)[x] << endl;
                if (add(i, sum)[x] < k) {
                    k -= add(i, sum)[x];
                    ans += ten;
                    sum++;
                    //cerr << "ans = " << ans << " k = " << k << endl;
                }
                else {
                    break;
                }
            }
            ten /= 10;
        }
        cout << ans << endl;
    }
}