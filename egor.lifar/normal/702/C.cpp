#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>


using namespace std;


int n, m;
int a[100001];
vector<int> b;

    
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    b.resize(m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        int t = 2000000000;
        if (it != b.end()) {
            t = min(t, *it - a[i]);
        }
        if (it != b.begin()) {
            it--;
            t = min(t, a[i] - *it);
        }
        ans = max(ans, t);
    }
    cout << ans << endl;
    return 0;
}