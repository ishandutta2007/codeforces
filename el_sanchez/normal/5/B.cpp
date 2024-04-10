#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <complex>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define sqr(x) (x)*(x)
#define odd(x) ((x) % 2 == 1)
#define next(i,n) ((i == n) ? 1 : i + 1)   //1..n
#define prev(i,n) ((i == 1) ? n : i - 1)   //1..n

typedef long long int64;

const int MAXN = (int)1E3+100;
const int INF = (int)1E9;
const long double eps = 1e-9;
const long double pi = 3.1415926535897932384626433832795;

using namespace std;

char w[MAXN];
string s[MAXN];
int l[MAXN];
int all, len, tlen;
bool fl;

int main() {

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    while (gets(w)) {
        s[all] = w;
        l[all] = strlen(w);
        len = max(len, l[all]); //0..len-1
        all++;
    }

    string st = "*";
    forn(i, len+1)
        st += "*";
    printf("%s\n", st.c_str());
    forn(i, all) {
        printf("*");
        tlen = len - l[i];
        FORN(j, 1, tlen / 2)
            printf(" ");
        if odd(tlen) {
            if (fl) {
                printf(" ");
                printf("%s", s[i].c_str());
            } else {
                printf("%s", s[i].c_str());
                printf(" ");
            }
            fl = !fl;
        } else
            printf("%s", s[i].c_str());
        FORN(j, 1, tlen / 2)
            printf(" ");
        printf("*\n");
    }
    printf("%s\n", st.c_str());

    return 0;
}