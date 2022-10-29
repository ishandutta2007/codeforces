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

#define fi first
#define se second
#define sqr(x) ((x)*(x))
#define odd(x) ((x) % 2 == 1)
#define next(i,n) ((i == n) ? 1 : i + 1)   //1..n
#define prev(i,n) ((i == 1) ? n : i - 1)   //1..n

typedef long long int64;

const int MAXN = (int)1E3+100;
const int INF = (int)1E9;
const long double eps = 1e-9;
const long double pi = 3.1415926535897932384626433832795;

using namespace std;

char c1[2], c2[2];
const int dx[]= {-1,1,0,0,-1,-1,1,1};
const int dy[]= {0,0,-1,1,-1,1,-1,1};
const string ds[]= {"U", "D", "L", "R", "LU", "RU", "LD", "RD"};

char s[3][3];
int x, o;

bool iswin(char c)
{
    if (((s[0][0] == c) && (s[0][1] == c) && (s[0][2] == c)) ||
        ((s[1][0] == c) && (s[1][1] == c) && (s[1][2] == c)) ||
        ((s[2][0] == c) && (s[2][1] == c) && (s[2][2] == c)) ||
        ((s[0][0] == c) && (s[1][0] == c) && (s[2][0] == c)) ||
        ((s[0][1] == c) && (s[1][1] == c) && (s[2][1] == c)) ||
        ((s[0][2] == c) && (s[1][2] == c) && (s[2][2] == c)) ||
        ((s[0][0] == c) && (s[1][1] == c) && (s[2][2] == c)) ||
        ((s[0][2] == c) && (s[1][1] == c) && (s[2][0] == c)))
    {
        return 1;
    }
    return 0;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    forn(i, 3) {
        scanf("%c%c%c\n", &s[i][0], &s[i][1], &s[i][2]);
        forn(j, 3) {
            if (s[i][j] == '0') o++;
            if (s[i][j] == 'X') x++;
        }
    }

    if (iswin('X')) {
        if ((x != o+1) || iswin('0')) {
            printf("illegal");
        } else {
            printf("the first player won");
        }
        return 0;
    }

    if (iswin('0')) {
        if ((x != o) || iswin('X')) {
            printf("illegal");
        } else {
            printf("the second player won");
        }
        return 0;
    }

    if ((o == 4) && (x == 5)) {
        printf("draw");
        return 0;
    }

    if (x == o) {
        printf("first");
    } else {
        if (x == o+1) {
            printf("second");
        } else {
            printf("illegal");
        }
    }

    return 0;
}