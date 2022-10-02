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
const int Mod = 998244353;


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
	return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = mul(res, a);
		}
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}


int inv(int a) {
    return powm(a, Mod - 2);
}



const int BLOCK = 316;
const int MAXN = 100228;


int n;
ll k;
ll a[MAXN];
int who[MAXN];
ll resp[MAXN];
int it = 0;
ll a1[MAXN];
int lens;
int repos;


void moves(int l, int r) {
	for (int i = l, j = 0; j < lens; i = (i == n - 1 ? 0: i + 1), j++) {
		if (i == repos) {
			a1[(i == n - 1 ? 0: i + 1)] += a[i];
		} else {
			a1[(i == n - 1 ? 0: i + 1)] += (a[i] + 1) >> 1;
			a1[(i == 0 ? n - 1: i - 1)] += a[i] >> 1;
		}
	}
	if (!(lens == n)) {
		a1[l] = k;
		a1[r] = k;
	}
	for (int i = l, j = 0; j < lens; i = (i == n - 1 ? 0: i + 1), j++) {
		a[i] = a1[i];
		a1[i] = 0;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
    // read(FILENAME);
    mt19937 as(228);
	cin >> n >> k;
	int i = -1;
	int val;
	for (int it = 0; it < 500; it++) {
		cout << "? " << 1 << endl;
		ll res;
		cin >> res;
	}
	while (true) {
		int t = as() % n;
		cout << "? " << t + 1 << endl;
		ll res;
		cin >> res;
		who[it] = t;
		resp[it] = res;
		it++;
		if (res != k) {
			val = res;
			i = t;
			break;
		}
	}
	assert(i != -1);
	if (val > k) {
		int l = i - (n + 1) / 2;
	    int r = i;
	    while (l + 1 < r) {
	        int mid = l + (r - l) / 2;
	        int pos = (mid % n + n) % n;
	        cout << "? " << pos + 1 << endl;
	        int x;
	        cin >> x;
	        if (x > k) {
	          	r = mid;
	        } else {
	          	l = mid;
	        }
	    }
	    int res = (l % n + n) % n;
	    cout << "! " << res + 1 << endl;
	} else {
		int l = i;
      	int r = i + (n + 1) / 2;
      	while (l + 1 < r) {
       	 	int mid = l + (r - l) / 2;
        	int pos = (mid % n + n) % n;
	        cout << "? " << pos + 1 << endl;
	        int x;
	        cin >> x;
        	if (x < k) {
          		l = mid;
        	} else {
          		r = mid;
        	}
      	}
      	int res = (r % n + n) % n;
      	cout << "! " << res + 1 << endl;
	}
   	return 0;
}