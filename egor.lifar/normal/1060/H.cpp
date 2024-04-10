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
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define rank rank228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
const string FILENAME = "input";



int Mod;


int mul(int a, int b) {
    return ((ll)a * b) % Mod;
}


int sumM(int a, int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}


ll powm(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = mul(res, a);
        }
        b >>= 1;
        a = mul(a, a);
    }
    return res;
}


void sum(int a, int b, int c) {
    cout << "+ " << a << ' ' << b << ' ' << c << '\n';
}


void step(int a, int b) {
    cout << "^ " << a << ' ' << b << '\n';
}


int d;
int uk = 0;


int mult(int x, ll c) {
    if (c == 0) {
       c = Mod;
    }
    if (c == 1) {
       return x;
    }
    int y = mult(x, c / 2);
    sum(y, y, uk);
    y = uk++;
    if (c % 2 == 1) {
       sum(x, y, y);
    }
    return y;
}


ll cnk[20][20];
ll a[20][20];
int one;
ll c[20];
int e[20];
 

int squared(int x) {
    e[0] = x;
    for (int i = 1; i <= d; i++) {
        e[i] = uk++;
    }
    for (int i = 1; i <= d; i++) {
        sum(e[i - 1], one, e[i]);
    }
    for (int i = 0; i <= d; i++) {
        step(e[i], e[i]);
        e[i] = mult(e[i], c[i]);
    }
    for (int i = 1; i <= d; i++) {
        sum(e[0], e[i], e[0]);
    }
    return e[0];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 	//read(FILENAME);	
    cin >> d >> Mod;
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                cnk[i][j] = 1;
            } else {
                cnk[i][j] = cnk[i - 1][j] + cnk[i - 1][j - 1];
            }  
        }
    }
    int x = 1;
    int y = 2;
    int pos = 3;
    sum(x, y, pos);
    one = 4;
    uk = 5;
    for (int i = 0; i <= d; i++) {
        for (int j = 0; j <= d; j++) {
            a[i][j] = mul(cnk[d][i], powm(j, i));
        }
    }
    a[d - 2][d + 1] = 1;
    int id = 0;
    for (int i = 0; i <= d; i++) {
        int fl = 0;
        for (int j = id; j <= d; j++) {
            if (a[j][i]) {
                for (int k = 0; k <= d + 1; k++) {
                    swap(a[id][k], a[j][k]);
                }
                fl = 1;
                break;
            }
        }
        ll x = powm(a[id][i], Mod - 2);
        for (int j = 0; j <= d + 1; j++) {
            a[id][j] = mul(a[id][j], x);
        }
        for (int j = 0; j <= d; j++) {
            if (j == id) {
                continue;
            }
            ll x = a[j][i];
            for (int k = 0; k <= d + 1; k++) {
                a[j][k] = sumM(a[j][k], Mod - mul(x, a[id][k]));
            }
        }
        id++;
    }
    for (int i = 0; i <= d; i++) {
        c[i] = a[i][d + 1];
    }
    x = squared(x);
    y = squared(y);
    pos = squared(pos);
    x = mult(x, Mod - 1);
    y = mult(y, Mod - 1);
    sum(x, pos, pos);
    sum(y, pos, pos);
    pos = mult(pos, (Mod + 1) / 2);
    cout << "f " << pos << '\n';
}