#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int n, bs, mx, mn;

int main() {
    scanf("%lld", &n);
    bs = n; mx = 1; mn = n + 1;

    for(int i = 1; i <= n; i++) {
        int rem = n % i;
        int tmp = (n / i) + (rem > 0) + i;

        if(tmp < mn) {
            mn = tmp;
            mx = i;
            bs = (n / i) + (rem > 0);
        }
    }

    vector<int> ans, tmp;
    for(int i = 1; i <= n; i++) {
        tmp.push_back(i);
        if(i % mx == 0 || i == n) {
            while(!tmp.empty()) {
                ans.push_back(tmp.back());
                tmp.pop_back();
            }
        }
    }
    reverse(ans.begin(), ans.end());

    for(int x : ans) {
        printf("%d ", x);
    } puts("");
    return 0;
}