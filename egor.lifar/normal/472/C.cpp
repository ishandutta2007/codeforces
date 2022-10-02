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



int n;
string s[100000], s1[100000];
bool dp[100000][2];
int a[100000];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> s1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    dp[0][0] = true;
    dp[0][1] = true;
    for (int i = 1; i < n; i++) {
        if (dp[i - 1][0] && s[a[i - 1]] < s[a[i]]) {
            dp[i][0] = true;
        }
        if (dp[i - 1][1] && s1[a[i - 1]] < s[a[i]]) {
            dp[i][0] = true;
        }
        if (dp[i - 1][0] && s[a[i - 1]] < s1[a[i]]) {
            dp[i][1] = true;
        }
        if (dp[i - 1][1] && s1[a[i - 1]] < s1[a[i]]) {
            dp[i][1] = true;
        }
    }
    if (dp[n - 1][0] || dp[n - 1][1]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}