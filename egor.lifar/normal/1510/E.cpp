/*
KAMUI!
 
 

 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

*/
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
const int Mod = 1000000009;


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

 
string getString(int mask, int n, bool fl = false) {
    string answer(n, ')');
    for (int i = 0; i < n; i++) {
        if ((mask >> i) & 1) {
            answer[i] = '(';
        }
    }
    if (fl) {
        reverse(all(answer));
        for (char& ch : answer) {
            ch = (ch == '(' ? ')' : '(');
        }
    }
    return answer;
}
 

bool correct(const string& s) {
    int c = 0;
    for (char ch : s) {
        if (ch == '(') {
            c++;
        } else {
            c--;
        }
        if (c < 0) {
            return false;
        }
    }
    return c == 0;
}
 
 
pair<int,int> generateCenterOfMass(int n, int mask, int x, int y, int k) {
    int ansx = 0, ansy = 0;
    int c = 0;
    for (int i = 0; i < n; i++) {
        if ((mask >> i) & 1) {
            c++;
            int currentXPos = i * k + 2 * k / 3;
            int currentYPos = (c - 1) * k + k / 3;
            ansx += (x - currentXPos);
            ansy += (y - currentYPos);
            for (int j = 0; j < c - 1; j++) {
                ansx += 2 * x - (2 * i * k + k);
                ansy += 2 * y - (2 * j * k + k);
            }
        } else {
            c--;
            int currentXPos = i * k + k / 3;
            int currentYPos = c * k + k / 3;
            ansx += (x - currentXPos);
            ansy += (y - currentYPos);
            for (int j = 0; j < c; j++) {
                ansx += 2 * x - (2 * i * k + k);
                ansy += 2 * y - (2 * j * k + k);
            }
        }
    }
    return {ansx, ansy};
}
 

int getBalance(int mask, int n) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        if ((mask >> i) & 1) {
            c++;
        } else {
            c--;
        }
    }
    return c;
}
 

string trySolve(int n, int x, int y, int k) {
    vector<tuple<pair<int, int>, int, int>> arr, brr;
    for (int mask = 0; mask < (1 << n); mask++) {
        int c = 0;
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                c++;
            } else {
                c--;
            }
            if (c < 0) {
                break;
            }
        }
        if (c < 0) {
            continue;
        }
        arr.pb({generateCenterOfMass(n, mask, x, y, k), getBalance(mask, n), mask});
        brr.pb({generateCenterOfMass(n, mask, 2 * n * k - x, y, k), getBalance(mask, n), mask});
    }
    sort(all(arr));
    for (auto& [w, balance, mask] : brr) {
        w.second *= -1;
    }
    sort(all(brr));
    int j = 0;
    for (auto& [w1, balance, mask1] : arr) {
        while (j < sz(brr) && (get<0>(brr[j]) < w1 || get<0>(brr[j]) == w1 && get<1>(brr[j]) < balance)) {
            j++;
        }
        if (j < sz(brr)) {
            auto [w2, balance2, mask2] = brr[j];
            if (w1 == w2 && balance == balance2) {
                return getString(mask1, n) + getString(mask2, n, true);
            }
        }
    }
    return "";
}
 

int n;
double x, y;


bool ok(double x, int y) {
    return abs(x - y) < 1e-7;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> n >> x >> y;
    n /= 2;
    for (int k = 3; ; k += 3) {
        int X = round(k * x);
        int Y = round(k * y);
        if (!ok(k * x, X) || !ok(k * y, Y)) {
            continue;
        }
        string result = trySolve(n, X, Y, k);
        if (sz(result) && correct(result)) {
            cout << result << '\n';
            return 0;
        }
    }
    return 0;
}