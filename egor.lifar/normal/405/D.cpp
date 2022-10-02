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
int x[500000];
bool b[1000001];
map<int, bool> m1;


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
        b[x[i]] = true;
    }
    int l = 1;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (!b[1000000 - x[i] + 1]) {
            ans.push_back(1000000 - x[i] + 1);
        } else {
            if (!m1[x[i]]) {
                while (b[l] || b[1000000 - l + 1]) {
                    l++;
                }
                ans.push_back(l);
                ans.push_back(1000000 - l + 1);
                m1[1000000 - x[i] + 1] = true;
                l++;
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    cout << endl;
    return 0;
}