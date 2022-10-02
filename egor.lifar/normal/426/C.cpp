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


int n, t;
int a[200];
int d[200][200];


int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    multiset<int> s, s1;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            s.clear();
            s1.clear();
            for (int k = i; k <= j; k++) {
                s.insert(a[k]);
                d[i][j] += a[k];
            }
            for (int k = 0; k < i; k++) {
                s1.insert(a[k]);
            }
            for (int k = j + 1; k < n; k++) {
                s1.insert(a[k]);
            }
            int k = 1;
            while (k <= t && s.size() != 0 && s1.size() != 0) {
                if (*s.begin() >= *s1.rbegin()) {
                    break;
                }
                d[i][j] -= *s.begin();
                d[i][j] += *s1.rbegin();
                k++;
                s.erase(s.find(*s.begin()));
                s1.erase(s1.find(*s1.rbegin()));
            }
        }
        s.clear();
        s1.clear();
    }
    int ans = -1000000000;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            ans = max(ans, d[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}