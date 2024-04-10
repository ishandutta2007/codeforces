#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))

using namespace std;

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const int INF = 1000000000;
const int MAXN = 100100;

string s;
int l;

int main() {

#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif

    getline(cin, s);
    l = s.size();
    forn(i, l) {
        if ('A' <= s[i] && s[i] <= 'Z')
            s[i] = s[i] - 'A' + 'a';
        if (!(s[i] == 'a' or s[i] == 'o' or s[i] == 'y' or s[i] == 'e' or s[i] == 'u' or s[i] == 'i'))
            cout << '.' << s[i];
    }
    cout << endl;

    return 0;
}