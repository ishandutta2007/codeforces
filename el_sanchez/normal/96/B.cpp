#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>

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

vector<int> lucky;
int num, temp, len;

void gen(int x, int s4, int s7, int l) {
    if (l == len) {
        lucky.push_back(x);
        return;
    }
    if (s4 < len / 2)
        gen(x * 10 + 4, s4 + 1, s7, l + 1);
    if (s7 < len / 2)
        gen(x * 10 + 7, s4, s7 + 1, l + 1);
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> num;
    temp = num;
    while (temp > 0) {
        temp /= 10;
        len++;
    }
    if (num == 1000000000) {
        cout << 4444477777 <<  endl;
        return 0;
    }

    if (len % 2 || num > 77774444) {
        forn(i, len / 2 + 1) cout << 4;
        forn(i, len / 2 + 1) cout << 7;
        cout << endl;
        return 0;
    }

    gen(0, 0, 0, 0);
    sort(all(lucky));
    int i = 0;
    while (i < lucky.size() && lucky[i] < num) i++;

    if (i >= lucky.size()) {
        forn(i, len / 2 + 1) cout << 4;
        forn(i, len / 2 + 1) cout << 7;
        cout << endl;
    } else
        cout << lucky[i] << endl;

    return 0;
}