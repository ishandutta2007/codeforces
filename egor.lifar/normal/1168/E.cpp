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
template<class T1, class T2> inline void chkmin(T1 &x, const T2 &y) {if (x > y) x = y;}
template<class T1, class T2> inline void chkmax(T1 &x, const T2 &y) {if (x < y) x = y;}
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define mp make_pair
#define pb push_back
#define read(FILENAME) freopen((string(FILENAME) + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((string(FILENAME) + ".out").c_str(), "w", stdout);
const int MAXN = 4100;


int k;
int a[MAXN];
int n;
int b[MAXN];
int p[MAXN], q[MAXN];
int id[MAXN];



void change(int i, int j) {
	if (q[i] == (p[i] ^ b[i])) {
        return;
    } 
    if (q[i] == (p[i] ^ b[j])) {
    	swap(id[p[i]], id[p[j]]);
    	swap(p[i], p[j]);
        swap(q[i], q[j]);
        return;
    }  
   	if (q[i] == (p[j] ^ b[i])) {
   		swap(id[p[i]], id[p[j]]);
        swap(p[i], p[j]);
        return;
    }
    if (q[i] == (p[j] ^ b[j])) {
        swap(q[i], q[j]);
        return;
    }
    int t = id[b[i] ^ q[i]];
    swap(id[p[t]], id[p[i]]);
    swap(q[t], q[i]);
    swap(q[t], q[j]);
    swap(q[i], q[j]);
    swap(p[t], p[i]);
    change(t, j);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read("input");
	cin >> k;
	n = (1 << k);
	int cur = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cur ^= a[i];
	}
	if (cur) {
		cout << "Fou\n";
		return 0;
	}
	cout << "Shi\n";
    for (int i = 0; i < n; i++) {
      	p[i] = i;
      	q[i] = i;
      	id[i] = i;
    }
    for (int i = 0; i < n - 1; i++) {
      	b[i + 1] ^= (a[i] ^ b[i]);
      	b[i] = a[i];
      	change(i, i + 1);
    }
    for (int i = 0; i < n; i++) {
      	cout << p[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
      	cout << q[i] << ' ';
    }
    cout << '\n';
}