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

int n, len;
string w[MAXN];
string h;
char letter;
bool change[MAXN];

bool compare(int i, int j, string a) {
    if (j - i + 1 != a.size())
        return 0;
    string temp = h, temp2 = a;
    for (int x = i; x <= j; x++) {
        if ('A' <= temp[x] && temp[x] <= 'Z')
            temp[x] = temp[x] + ('a' - 'A');
        if ('A' <= temp2[x - i] && temp2[x - i] <= 'Z')
            temp2[x - i] = temp2[x - i] + ('a' - 'A');
        if (temp[x] != temp2[x - i]) return 0;
    }
    return 1;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> n;
    forn(i, n)
        cin >> w[i];
    cin >> h;
    cin >> letter;

    len = h.size();
    for (int i = 0; i < len; i++)
        for (int j = i; j < len; j++) {
            forn(k, n)
                if (compare(i, j, w[k]))
                    for (int l = i; l <= j; l++)
                        change[l] = 1;
        }

    char capsletter, smallletter;
    smallletter = letter;
    capsletter = letter - ('a' - 'A');
    forn(i, len)
        if (change[i]) {
            if ('a' <= h[i] && h[i] <= 'z')
                if (h[i] == smallletter) {
                    if (smallletter == 'a')
                        cout << 'b';
                    else
                        cout << 'a';
                } else
                    cout << smallletter;
            else
                if (h[i] == capsletter) {
                    if (capsletter == 'A')
                        cout << 'B';
                    else
                        cout << 'A';
                } else
                    cout << capsletter;
        } else
            cout << h[i];
    cout << endl;

    return 0;
}