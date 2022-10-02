#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <assert.h>


using namespace std;


#define INF 10000;


int n;
int a[100];
short d[101][262144];
int c[101][262144];
char p[101][262144];
short ans = INF;
map<int, int> m;
vector<int> v;


int main() {
   // freopen("output.txt", "w", stdout);
    m[2] = 1;
    m[3] = 2;
    m[5] = 3;
    m[7] = 4;
    m[11] = 5;
    m[13] = 6;
    m[17] = 7;
    m[19] = 8;
    m[23] = 9;
    m[29] = 10;
    m[31] = 11;
    m[37] = 12;
    m[41] = 13;
    m[43] = 14;
    m[47] = 15;
    m[53] = 16; 
    int fact[59] = {0, 0, 1, 2, 1, 4, 3, 8, 1, 2, 5, 16, 3, 32, 9, 6, 1, 64, 3, 128, 5, 10, 17, 256, 3, 4, 33, 2, 9, 512, 7, 1024, 1, 18, 65, 12, 3, 2048, 129, 34, 5, 4096, 11, 8192, 17, 6, 257, 16384, 3, 8, 5, 66, 33, 32768, 3, 20, 9, 130, 513};  
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // for (int i = 1; i <= 59; i++) {
    //     if (i == 1) {
    //         fact[i] = 0;
    //     } else {
    //         int i1 = i;
    //         for (int j = 2; j <= i; j++) {
    //             if (i1 % j == 0) {
    //                 //cout << j << endl;
    //                 fact[i] = fact[i] | (1LL << (m[j] - 1));
    //                 //cout << m[j] - 1 << endl;
    //                 while (i1 % j == 0) {
    //                     i1 /= j;
    //                     //cout << i << endl;
    //                     //cout << "Opa" << endl;
    //                 }
    //             }
    //         }
    //     }
    //     cout << ", " << fact[i];
    // }
    for (int j = 0; j <= 131071; j++) {
        d[0][j] = INF;
    }
    //cout << fact[3] << endl;
    //cout << "ans" << endl;
    d[0][0] = 0;
   // cout << fact[32] << endl;
    int j1 = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 131071; j++) {
            d[i][j] = INF;
            for (int k = 1; k <= 2 * a[i - 1] - 1; k++) {
               // cout << k << endl;
                if (j >= fact[k] && ((j & fact[k]) == fact[k])) {
                    if (d[i][j] > d[i - 1][j - fact[k]] + abs(k - a[i - 1])) {
                        d[i][j] = d[i - 1][j - fact[k]] + abs(k - a[i - 1]);
                        c[i][j] = j - fact[k];
                        p[i][j] = k;
                    }
                }
            }
            //cout << "op" << endl;
            if (i == n) {
                if (ans > d[i][j]) {
                    ans = d[i][j];
                    j1 = j;
                }
            }
           // cout << ans << endl;
        }
    }
    //cout << ans << endl;
    int i1 = n;
    vector<int> v;
    while (i1 > 0) {
        v.push_back(p[i1][j1]);
        j1 = c[i1][j1];
        i1--;
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
    return 0;
}