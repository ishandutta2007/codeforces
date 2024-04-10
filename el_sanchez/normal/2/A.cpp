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
#define odd(x) (x % 2 == 1)
#define next(i,n) ((i == n) ? 1 : i + 1)   //1..n
#define prev(i,n) ((i == 1) ? n : i - 1)   //1..n

typedef long long int64;

const int MAXN = (int)1E3+100;
const int INF = (int)1E9;
const long double eps = 1e-9;
const long double pi = 3.1415926535897932384626433832795;

using namespace std;

int main() {

    int score[MAXN], res[MAXN];
    string name[MAXN], all[MAXN];
    char temp[MAXN];

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);

    forn(i, n) {
        scanf("%s %d", &temp, &score[i]);
        name[i] = temp;
    }

    int j, p = 0;
    forn(i, n) {
        j = 0;
        while ((j < p) && (all[j] != name[i])) j++;
        if (j == p) {
            p++;
            all[j] = name[i];
            res[j] = score[i];
        } else {
            res[j] += score[i];
        }
    }

    int id = 0, ref = n;
    forn(i, p) {
        int cref = -1, curr = 0;
        while (curr < res[i]) {
            cref++;
            if (name[cref] == all[i])
                curr += score[cref];
        }
        if ((res[id] < res[i]) || ((res[id] == res[i]) && (cref < ref))) {
            id = i;
            ref = cref;
        }
    }

    printf("%s\n", all[id].c_str());

    return 0;
}