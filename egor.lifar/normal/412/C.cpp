#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>


using namespace std;


int n, m;
string a[100000];
set<int> s[100000];
string ans;


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    m = a[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != '?') {
                s[j].insert(a[i][j]);
            }
        }
    }
    ans.resize(m);
    for (int i = 0; i < m; i++) {
        if (s[i].size() == 1) {
            ans[i] = *s[i].begin();
        } else {
            if (s[i].size() == 0) {
                ans[i] = 'a';
            } else {
                ans[i] = '?';
            }
        }
    }
    cout << ans << endl;
    return 0;
}