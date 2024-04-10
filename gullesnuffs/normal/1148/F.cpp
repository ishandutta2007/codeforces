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

ll getRand() {
    ll a = 0;
    rep(i,0,62) {
        if (rand()%2)
            a += 1LL<<i;
    }
    return a;
}

ll getSum(vector<pair<ll, ll>>& a, ll s) {
    ll sum = 0;
    for (auto it : a) {
        if (__builtin_popcountll(s&it.second)%2)
            sum -= it.first;
        else
            sum += it.first;
    }
    return sum;
}

double getWeightedSum(vector<pair<ll, ll>>& a, ll s) {
    double sum = 0;
    for (auto it : a) {
        if (__builtin_popcountll(s&it.second)%2)
            sum -= it.first / double(__builtin_popcountll(it.second));
        else
            sum += it.first / double(__builtin_popcountll(it.second));
    }
    return sum;
}

int main(){
	ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    rep(i,0,n) {
        ll x, y;
        cin >> x >> y;
        a[i] = make_pair(x, y);
    }
    ll startSum = getSum(a, 0);
    if (startSum < 0) {
        rep(i,0,n) {
            a[i].first *= -1;
        }
        startSum *= -1;
    }
    ll s = 0;
    while (true) {
        ll newS = s ^ (1LL<<(rand()%62));
        ll newSum = getSum(a, newS);
        if (newSum < 0) {
            cout << newS << endl;
            return 0;
        }
        if (getWeightedSum(a, newS) < getWeightedSum(a, s)) {
            s = newS;
        }
    }
}