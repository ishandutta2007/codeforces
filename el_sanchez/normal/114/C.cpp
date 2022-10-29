#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const int INF = (int)1E9;
const int MAXN = (int)11000;

using namespace std;

vector<string> inp;

int defword(int id) {
    string k = inp[id];
    int sz = k.size();
    if (sz >= 4 && k.substr(sz - 4, 4) == "lios")
        return 0;
    if (sz >= 5 && k.substr(sz - 5, 5) == "liala")
        return 1;
    if (sz >= 3 && k.substr(sz - 3, 3) == "etr")
        return 2;
    if (sz >= 4 && k.substr(sz - 4, 4) == "etra")
        return 3;
    if (sz >= 6 && k.substr(sz - 6, 6) == "initis")
        return 4;
    if (sz >= 6 && k.substr(sz - 6, 6) == "inites")
        return 5;
    return -1;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string a;
    while (cin >> a)
        inp.push_back(a);
    if (inp.size() == 1) {
        if (defword(0) != -1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return 0;
    }

    bool rod[2];
    rod[0] = 0, rod[1] = 0;
    int now = 0;
    forn(i, inp.size()) {
        int cur = defword(i);
        if (cur == -1) {
            cout << "NO\n";
            return 0;
        }

        rod[cur % 2] = 1;
        int def = cur / 2;
        if (def == 0)
            if (now > 0) {
                cout << "NO\n";
                return 0;
            }

        if (def == 1) {
            if (now != 0) {
                cout << "NO\n";
                return 0;
            }
            now = 1;
        }

        if (def == 2) {
            if (now == 0) {
                cout << "NO\n";
                return 0;
            }
            now = 2;
        }

    }

    if (rod[0] && rod[1] || now == 0)
        cout << "NO\n";
    else
        cout << "YES\n";

    return 0;
}