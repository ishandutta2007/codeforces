#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define odd(x) ((x) % 2 == 1)

typedef long long int64;

const int MAXN = (int)110;
const int INF = (int)1E9;
const long double eps = 1e-9;
const long double pi = 3.1415926535897932384626433832795;

using namespace std;

int i1, i2, n, balance;
map<string, int> types;
string cmd, temp, name[2];

void convert(string s) {
    int len = s.length();
    i1 = 0;
    while (s[i1] == '&') {i1++;}
    i2 = len - 1;
    while (s[i2] == '*') {i2--;}
    i2 = len - 1 - i2;
    name[1] = s.substr(i1, len - i2 - i1);
    if (types.find(name[1]) == types.end())
        name[1] = "errtype";
    balance = (i2 - i1) + types[name[1]];
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    types["errtype"] = -INF;
    types["void"] = 0;
    cin >> n;
    forn(i, n) {
        cin >> cmd;
        if (cmd == "typedef") {
            cin >> temp >> name[0];
            convert(temp);
            if (balance >= 0)
                types[name[0]] = balance;
            else
                types[name[0]] = -INF;
        } else {
            cin >> temp;
            convert(temp);
            if (balance >= 0) {
                cout << "void";
                forn(j, balance)
                    cout << "*";
                printf("\n");
            } else
                cout << "errtype" << endl;
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}