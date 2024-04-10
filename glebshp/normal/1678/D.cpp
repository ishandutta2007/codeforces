#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int maxn = 1000 * 1000 + 100;

char s[maxn];
int horans[maxn];
int verans[maxn];
int cntver[maxn];

int n;
int m;
int tnum;

void solveHorizontal() {
    for (int i = 0; i < m; i++) {
        cntver[i] = 0;
    }    
    int sum = 0;
    for (int i = 0; i < n * m; i++) {
        sum += (s[i] - '0');
        if (i >= m) {
            sum -= (s[i - m] - '0');
        }
//        cerr << i << ' ' << sum << endl;
        if (sum > 0) {
            cntver[i % m]++;
        }
        horans[i] = cntver[i % m];
    }
}

void solveVertical() {
    for (int i = 0; i < m; i++) {
        cntver[i] = 0;
    }
    int good = 0;
    for (int i = 0; i < n * m; i++) {
        if (s[i] == '1') {
            cntver[i % m]++;
            if (cntver[i % m] == 1) {
                good++;
            }
        }
//        cerr << i << ' ' << good << endl;
        verans[i] = good;
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &tnum);
    for (int tc = 0; tc < tnum; tc++) {
        scanf("%d%d", &n, &m);
        scanf("%s", s);

        solveHorizontal();
        solveVertical();

        for (int i = 0; i < n * m; i++) {
            printf("%d ", horans[i] + verans[i]);
        }
        printf("\n");
        /*
        for (int i = 0; i < n * m; i++) {
            printf("%d ", horans[i]);
        }
        printf("\n");
        for (int i = 0; i < n * m; i++) {
            printf("%d ", verans[i]);
        }
        printf("\n");
        */
    }

    return 0;
}