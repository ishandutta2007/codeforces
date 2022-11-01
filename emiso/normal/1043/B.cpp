#include <bits/stdc++.h>

using namespace std;

int a[1100], n;
vector<int> rr, ans;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        rr.push_back(a[i] - a[i-1]);
    }

    for(int k = 1; k <= n; k++) {
        int flag = 1;
        for(int i = 0; i < rr.size(); i++) {
            if(rr[i] != rr[i % k]) flag = 0;
        }
        if(flag) ans.push_back(k);
    }
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);

    return 0;
}