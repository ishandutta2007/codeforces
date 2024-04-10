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

struct MaxTreeLL {
	typedef ll T;
	static const T LOW = -1e18;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	MaxTreeLL(int n = 0, T def = 0) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos > 1; pos /= 2)
			s[pos / 2] = f(s[pos & ~1], s[pos | 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = LOW, rb = LOW;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

struct MaxTreeP {
	typedef pair<int, int> T;
	T LOW = make_pair(INT_MIN, -1);
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	MaxTreeP(int n = 0, T def = make_pair(INT_MIN, -1)) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos > 1; pos /= 2)
			s[pos / 2] = f(s[pos & ~1], s[pos | 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = LOW, rb = LOW;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

struct MinTree {
	typedef ll T;
	static const T LOW = 1e18;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	MinTree(int n = 0, T def = 0) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos > 1; pos /= 2)
			s[pos / 2] = f(s[pos & ~1], s[pos | 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = LOW, rb = LOW;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

MinTree minTree(300005);
MaxTreeLL maxTree(300005);
MaxTreeP diffTree(300005);
ll ans;

void rec(int l, int r) {
    if (r-l <= 1)
        return;
    auto bestCut = diffTree.query(l, r-1);
    ll cutDiff = bestCut.first;
    int cut = bestCut.second;
    ll res = maxTree.query(cut+2, r+1);
    res -= minTree.query(l, cut+1);
    res -= cutDiff * cutDiff;
    ans = max(ans, res);
    rec(l, cut+1);
    rec(cut+1, r);
}

int main(){
	ios::sync_with_stdio(0);
    int n, a;
    cin >> n >> a;
    vector<ll> d(n), g(n);
    rep(i,0,n) {
        ll c;
        cin >> d[i] >> c;
        g[i] = a - c;
    }
    vector<ll> gsum(n+1);
    rep(i,0,n) {
        gsum[i+1] = gsum[i] + g[i];
        minTree.update(i, gsum[i]);
        maxTree.update(i, gsum[i]);
        if (i < n-1) {
            diffTree.update(i, make_pair(d[i+1]-d[i], i));
        }
        ans = max(ans, g[i]);
    }
    minTree.update(n, gsum[n]);
    maxTree.update(n, gsum[n]);
    rec(0, n);
    cout << ans << endl;
}