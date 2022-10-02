#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <set>


using namespace std;


int n;
string s[2001];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int t = 6;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cnt = 0;
            for (int k = 0; k < 6; k++) {
                if (s[i][k] != s[j][k]) {
                    cnt++;
                }
            }
            t = min(t, max(0, (cnt + 1) / 2 - 1));
        }
    }
    cout << t << endl;
    return 0;
}