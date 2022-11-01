#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> ans;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);

    for(int i = 1; i < n; i *= 2) {
        ans.push_back(vector<int>());
        for(int m = 0; m < n; m++)
            if((i & m) == 0) ans.back().push_back(m + 1);
    }

    printf("%d\n", (int)ans.size());
    for(vector<int> &v : ans) {
        printf("%d", v.size());
        for(int x : v) printf(" %d", x);
        puts("");
    }
    return 0;
}