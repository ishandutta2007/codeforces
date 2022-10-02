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
const int MAXN = 8028;
const int Mod = 1000000007;


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
	return ((ll)a * b % Mod);
}


int L;
ll d[MAXN * 4];
int len[MAXN * 4];
int last[MAXN * 4];
int mod[MAXN * 4];


void init(int v, int vl, int vr, const vector<int> &xs) {
   	len[v] = xs[vr] - xs[vl - 1];
   	if (vl < vr) {
      	int mid = (vl + vr) >> 1;
      	init(v * 2, vl, mid, xs);
      	init(v * 2 + 1, mid + 1, vr, xs);
   	}
}


void restore(int v, int vl, int vr, const vector<int> &go) {
   	mod[v] = -1;
   	if (vl == vr) {
      	d[v] = (ll)(len[v]) * (L - go[vl]);
      	last[v] = go[vl];
      	return;
   	}
   	int mid = (vl + vr) >> 1;
   	restore(v * 2, vl, mid, go);
   	restore(v * 2 + 1, mid + 1, vr, go);
   	d[v] = d[v * 2] + d[v * 2 + 1];
   	last[v] = last[v * 2 + 1];
}


void push(int v, int l, int r) {
   	if (mod[v] != -1) {
      	last[v] = mod[v];
      	d[v] = (ll)len[v] * (L - mod[v]);
      	if (l < r) {
         	mod[v * 2] = mod[v];
         	mod[v * 2 + 1] = mod[v];
      	}
      	mod[v] = -1;
   	}
}


void add(int v, int vl, int vr, int l, int r, int pos) {
   	push(v, vl, vr);
   	if (l > vr || r < vl) {
   		return;
   	}
   	if (l <= vl && vr <= r) {
      	mod[v] = pos;
      	push(v, vl, vr);
      	return;
   	}
   	int mid = (vl + vr) >> 1;
   	add(v * 2, vl, mid, l, r, pos);
   	add(v * 2 + 1, mid + 1, vr, l, r, pos);
   	d[v] = d[v * 2] + d[v * 2 + 1];
   	last[v] = last[v * 2 + 1];
}


int spusk(int v, int vl, int vr, int pos) {
   	push(v, vl, vr);
   	if (last[v] <= pos) {
   		return -1;
   	}
   	if (vl == vr) {
   		return vl;
   	}
   	int mid = (vl + vr) >> 1;
   	int ans = spusk(v * 2, vl, mid, pos);
   	if (ans != -1) {
   		return ans;
   	}
   	return spusk(v * 2 + 1, mid + 1, vr, pos);
}


int N, K; 
int NX, NY;
int X[MAXN], Y[MAXN], C[MAXN];
vector<int> xs, ys;
int prv[MAXN], nxt[MAXN];


void del(int i) {
	int xprv = (prv[i] == -1 ? -1 : X[prv[i]]);
	int xcur = X[i];
	int xnxt = (nxt[i] == -1 ? L : X[nxt[i]]);
	int l =  lower_bound(all(xs), xprv) - xs.begin() + 1;
	int r = spusk(1, 1, NX - 2, xnxt);
	if (r == -1) {
		r = NX - 1;
	} 
	r--;
	r = min(r, (int)(lower_bound(all(xs), xcur) - xs.begin()));
	if (l <= r) {
		add(1, 1, NX - 2, l, r, xnxt);
	}
}



bool comp(int i, int j) {
	return make_pair(Y[i], -X[i]) > make_pair(Y[j], -X[j]);
}


void resort() {
	vector<int> order;
    for (int i = 0; i < N; i++) {
      	order.pb(i);
    }
    sort(order.begin(), order.end(), comp);
    vector<int> newX(N), newY(N), newC(N);
    for (int i = 0; i < N; i++) {
        newX[i] = X[order[i]];
        newY[i] = Y[order[i]];
        newC[i] = C[order[i]];
    }
    for (int i = 0; i < N; i++) {
    	X[i] = newX[i];
    	Y[i] = newY[i];
    	C[i] = newC[i];
    }
}


int main() {
  	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// /read(FILENAME);
   	cin >> N >> K >> L;
   	xs = {-1, L};
  	ys = {-1, L};
   	for (int i = 0; i < N; i++) {
     	cin >> X[i] >> Y[i] >> C[i];
      	C[i]--;
      	xs.pb(X[i]);
      	ys.pb(Y[i]);
   	}
   	sort(all(xs));
   	xs.resize(unique(all(xs)) - xs.begin());
   	sort(all(ys));
   	ys.resize(unique(all(ys)) - ys.begin());
   	NX = xs.size();
   	NY = ys.size();
   	resort();
   	init(1, 1, NX - 2, xs);
   	int ans = 0;
   	for (int yr = 1; yr + 1 < NY; yr++) {
	    vector<vector<int> > start(NX);
	    for (int i = 0; i < N; i++) {
	        if (Y[i] <= ys[yr]) {
	            int xi = lower_bound(all(xs), X[i]) - xs.begin();
	            start[xi].pb(C[i]);
	        }
	    }
	    int bad = K;
	    vector<int> cnts(K);
	    auto inc = [&](int z) {
	        if (++cnts[z] == 1) {
	        	--bad;
	        }
	    };
	    auto dec = [&](int z) {
	        if (--cnts[z] == 0) {
	        	++bad;
	        }
	    };
	    vector<int> go(NX);
	    int uk = 0;
	    for (int i = 1; i + 1 < NX; i++) {
	        while (bad && uk + 2 < NX) {
	            uk++;
	            for (auto z: start[uk]) {
	            	inc(z);
	            }
	        }
	        if (bad) {
	         	go[i] = L;
	        } else {
	         	go[i] = xs[uk];
	        }
	        for (auto z: start[i]) {
	         	dec(z);
	        }
	    }
	    restore(1, 1, NX - 2, go);
	    vector<map<int, int> > m(K);
	    for (int i = 0; i < N; i++) {
	         if (Y[i] <= ys[yr]) {
	            auto it = m[C[i]].lower_bound(X[i]);
	            if (it == m[C[i]].end()) {
	               	nxt[i] = -1;
	            } else {
	               	nxt[i] = it->second;
	            }
	            it = m[C[i]].upper_bound(X[i]);
	            if (it == m[C[i]].begin()) {
	               	prv[i] = -1;
	            } else {
	               	prv[i] = prev(it)->second;
	            }
	            m[C[i]][X[i]] = i;
	         }
	    }
	    uk = N - 1;
	    for (int yl = 1; yl <= yr; yl++) {
	        int add = mul(d[1] % Mod, mul(ys[yr + 1] - ys[yr], ys[yl] - ys[yl - 1]));
	        ans = sum(ans, add);
	        while (uk >= 0 && Y[uk] == ys[yl]) {
	        	del(uk--);
	        }
	    }
   	}
   	cout << ans << '\n';
   	return 0;
}