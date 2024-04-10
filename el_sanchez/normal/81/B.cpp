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

using namespace std;

const int INF = (int)1E9;
const long double eps = 1e-9;
const long double pi = 3.1415926535897932384626433832795;
const int MAXN = (int)100000;

int lexn, pos, len;
string lex[300], num[300];
char buf[300];

bool needforspace(int k) {
    if ((lex[k] == "...") || (lex[k - 1] == ","))
        return 1;
    if ((lex[k] == "Num") && (lex[k - 1] == "Num"))
        return 1;
    return 0;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    gets(buf);
    len = ((string)buf).size();
    while (pos < len) {
        if (buf[pos] == '.') {
            lex[lexn] = "...";
            lexn++;
            pos += 3;
            continue;
        }
        if (buf[pos] == ',') {
            lex[lexn] = ",";
            lexn++;
            pos++;
            continue;
        }
        if (('0' <= buf[pos]) && (buf[pos] <= '9')) {
            lex[lexn] = "Num";
            while (('0' <= buf[pos]) && (buf[pos] <= '9')) {
                num[lexn] += buf[pos];
                pos++;
            }
            lexn++;
            continue;
        }
        pos++;
    }

    if (lex[0] != "Num")
        printf("%s", lex[0].c_str());
    else
        printf("%s", num[0].c_str());
    FORN(i, 1, lexn - 1) {
        if (needforspace(i))
            printf(" ");
        if (lex[i] != "Num")
            printf("%s", lex[i].c_str());
        else
            printf("%s", num[i].c_str());
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}