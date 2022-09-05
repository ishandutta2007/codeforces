#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    vector<int> ans = {1};
    for (int p : {2, 3, 5, 7, 11}) {
        if (ans.size() > n) break;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] * p <= 2 * n * n) ans.push_back(ans[i] * p);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) printf("%d ", ans[i]);
    return 0;
}