#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int T, a, b;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &a, &b);
        vector<int> ans;
        int num1 = (a + b + 1) / 2, num2 = a + b - num1;
        for (int i = 0; i <= min(a, num1); i++) if (a - i <= num2) {
            ans.push_back(num1 - i + a - i);
        }
        swap(num1, num2);
        for (int i = 0; i <= min(a, num1); i++) if (a - i <= num2) {
            ans.push_back(num1 - i + a - i);
        }
        sort(ans.begin(), ans.end());
        ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
        printf("%d\n", ans.size());
        for (int x : ans) printf("%d ", x);
        putchar('\n');
    }
    return 0;
}