#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <map>
#include <assert.h>


using namespace std;


#define M 1000000007


int m;
int dp[448][100002];
int where[100002];
int step[100002], step1[100002];


int powm(int x, int a) {
    if (a == 0) {
        return 1; 
    } else {    
        if (a % 2 == 0) {
            int g = powm(x, a / 2);
            return (1LL * g * g) % M;
        } else {
            return (1LL * x * powm(x, a - 1)) % M;
        }
    }
}


int main() {
    cin >> m;
    vector<int> v;
    string s;
    cin >> s;
    v.push_back((int)s.size());
    int cur = (int)s.size();
    vector<pair<int, int> > z;
    for (int i = 0; i < m; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            cin >> s;
            v.push_back((int)s.size());
            cur = (int)s.size();
        } else {
            int n;
            scanf("%d", &n);
            z.push_back(make_pair(cur, n));
        }
    }
    sort(v.begin(), v.end());
    v.resize(distance(v.begin(), unique(v.begin(), v.end())));
    for (int i = 0; i <= 100000; i++) {
        if (i == 0) {
            step[i] = 1;
        } else {
            step[i] = (25LL * step[i - 1]) % M;
        }
        step1[i] = powm(i, M - 2);
    }
    for (int i = 0; i < (int)v.size(); i++) {
        int h = v[i];   
        where[h] = i;
        int st = 1;
        for (int j = 1; j <= 100000; j++) {
            if (j < h) {
                dp[i][j] = 0;
            } else {
                if (j == h) {
                    dp[i][j] = 1;
                } else {
                    st = (1LL * st * (j - 1)) % M;
                    st = (1LL * st * step1[j - 1 - (h - 1)]) % M;
                    dp[i][j] = (26LL * dp[i][j - 1] + 1LL * step[j - h] * st) % M;
                }
            }
        }
    }
    for (int i = 0; i < (int)z.size(); i++) {
        printf("%d\n", dp[where[z[i].first]][z[i].second]);
    }
    return 0;
}