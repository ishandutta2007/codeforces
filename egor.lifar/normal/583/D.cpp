#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>


using namespace std;


#define INF 1000000000


int n, t;
int a[101];
int m[101][101];
int m1[101][101];


void get(int mt[101][101], int x) {
    if (x == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mt[i][j] = m[i][j];
            }
        }
        return;
    }
    if (x % 2 == 0) {
        int m2[101][101];
        get(m2, x / 2);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mt[i][j] = -INF;
                for (int k = 0; k < n; k++) {
                    mt[i][j] = max(mt[i][j], m2[i][k] + m2[k][j]);
                }
            }
        }
    } else {
        int m2[101][101];
        get(m2, x - 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mt[i][j] = -INF;
                for (int k = 0; k < n; k++) {
                    mt[i][j] = max(mt[i][j], m2[i][k] + m[k][j]);
                }
            }
        }
    }
}


int main() {   
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j] >= a[i]) {
                m[i][j] = 1;
                for (int k = 0; k < j; k++) {
                    if (a[k] <= a[j]) {
                        m[i][j] = max(m[i][j], 1 + m[i][k]);
                    }
                }
            } else {
                m[i][j] = -INF; 
            }
        }
    }
    get(m1, t);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, m1[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}