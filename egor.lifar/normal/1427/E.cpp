#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>

using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double; 
const string FILENAME = "input";



vector<pair<char, pair<ll, ll> > > res;
set<ll> have;
vector<ll> haves;
vector<ll> fd;


ll add(ll a, ll b) {
	if (have.find(a + b) != have.end()) {
		return a + b;
	}
	if (a + b >= 1000000000000000000LL) {
		return a + b;
	}
	res.pb(mp('+', mp(a, b)));
	fd.pb(a + b);
	have.insert(a + b);
	haves.pb(a + b);
	return a + b;
}


ll xorM(ll a, ll b) {
	if (have.find((a ^ b)) != have.end()) {
		return (a ^ b);
	}
	if ((a ^ b) >= 1000000000000000000LL) {
		return (a ^ b);
	}
	have.insert((a ^ b));
	res.pb(mp('^', mp(a, b)));
	fd.pb(a ^ b);
	haves.pb(a ^ b);
	return a ^ b;
}

struct BitwiseGauss {
    int B;
    vector<ll> bb;
    BitwiseGauss(int _B) {
        B = _B;
        bb.resize(B);
    }
 	bool insert1(ll x) {
    	vector<pair<ll, ll> > kek;
        for (int i = B - 1; i >= 0; --i) {
            if (((x >> i) & 1)) {
                if (bb[i]) {
                    x ^= bb[i];
                } else {
                	return true;
                }
            }
        }
        return false;
    }

    void insert(ll x) {
    	vector<pair<ll, ll> > kek;
        for (int i = B - 1; i >= 0; --i) {
            if (((x >> i) & 1)) {
                if (bb[i]) {
                	kek.pb(mp(x, bb[i]));
                    x ^= bb[i];
                } else {
                	for (auto z: kek) {
                		xorM(z.first, z.second);
                	}
                    bb[i] = x;
                    break;
                }
            }
        }
    }
    bool can1(ll x) {
    	for (int i = B - 1; i >= 1; --i) {
    		if (((x >> i) & 1)) {
                if (bb[i]) {
                    x ^= bb[i];
                }
            }
    	}
    	if (x == 0) {
    		if (bb[0]) {
    			x ^= bb[0];
    		}
    	}
    	return x == 1;
    }
    bool can(ll x) {
    	for (int i = B - 1; i >= 1; --i) {
    		if (((x >> i) & 1)) {
                if (bb[i]) {
                    xorM(x, bb[i]);
                    x ^= bb[i];
                }
            }
    	}
    	if (x == 0) {
    		if (bb[0]) {
    			xorM(x, bb[0]);
    			x ^= bb[0];
    		}
    	}
    	return x == 1;
    }
    void clear() {
        fill(bb.begin(), bb.end(), 0);
    }
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
//	while (true) {
		BitwiseGauss kek(61);
		ll x;
		cin >> x;
		//x = rand() % 1000000 + 3;
		have.clear();
		haves.clear();
		have.insert(x);
		haves.pb(x);
		kek.insert(x);
		res.clear();
		//gen trash numbers stage;
		mt19937 as;
		while ((!kek.can1(x) && !kek.bb[0])) {
			fd.clear();
			while (fd.empty()) {
				ll f = haves[as() % sz(haves)];
				ll f1 = haves[as() % sz(haves)];
				if (as() & 1) {
					ll vl = f + f1;
					if (vl <= 1000000000000000000LL) {
						if (have.find(vl) == have.end()) {
							if (kek.insert1(vl)) {
								ll op = add(f, f1);
							}
						}
					}
				} else {
					ll vl = f ^ f1;
					if (vl <= 1000000000000000000LL) {
						if (have.find(vl) == have.end()) {
							if (kek.insert1(vl)) {
								ll op = xorM(f, f1);
							}
						}
					}
				}
			}
			while (!fd.empty() && (!kek.can1(x) && !kek.bb[0])) {
				auto x = fd.back();
				fd.pop_back();
				if (kek.insert1(x)) {
					kek.insert(x);
				}
			}
		}
		//cerr << x << endl;
		assert(kek.can(x));
		//cout << sz(res) << endl;
		assert(sz(res) <= 100000);
	//}
	cout << sz(res) << '\n';
	for (auto x: res) {
		cout << x.second.first << ' ' << x.first << ' ' << x.second.second << '\n';
	}
}