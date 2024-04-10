#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <string.h>
#include <cmath>
#include <set>


using namespace std;


int n, m;
int w[100000];
int b[100000];



int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        b[i]--;
    }
    set<int> s;
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        if (s.find(b[i]) == s.end()) {
            ans.push_back(b[i]);
        }
        s.insert(b[i]);
    }
    for (int i = 0; i < n; i++) {
        if (s.find(i) == s.end()) {
            ans.push_back(i);
        }
    }
    int ans1 = 0;
    for (int i = 0; i < m; i++) {
        int g = 0;
        for (int j = 0; j < n; j++) {
            if (ans[j] == b[i]) {
                g = j;
                break;
            }
        }
        for (int j = 0; j < g; j++) {
            ans1 += w[ans[j]];
        }
        vector<int> ans2;
        ans2.push_back(b[i]);
        for (int j = 0; j < g; j++) {
            ans2.push_back(ans[j]);
        }
        for (int j = g + 1; j < n; j++) {
            ans2.push_back(ans[j]);
        }
        ans = ans2;
    }
    cout << ans1 << endl;
    return 0;
}