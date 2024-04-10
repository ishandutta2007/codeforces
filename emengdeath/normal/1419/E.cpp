#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> ans;
int main() {
    int n, T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        ans.clear();
        ans.push_back(1);
        for (int i = 2; 1ll * i * i <=n ; i ++)
            if (n % i == 0) {
                int v = 1;
                int l = 0, r = ans.size() - 1;
                swap(r, l);
                while (n % i == 0) {
                    n /= i;
                    v *= i;
                    for (int j = l; j <= r; j ++)
                        ans.push_back(ans[j] * v);
                    if (l != r)
                        for (int j = l; j >= r; j --)
                            ans.push_back(ans[j] * v);
                    swap(r, l);
                }
            }
        if (n != 1) {
            int r = ans.size() - 1, l = 0;
            for (int j = r; j >= l; j --)
                ans.push_back(ans[j] * n);
        }
        if (__gcd(ans[1], ans[ans.size() - 1]) == 1 && ans.size() > 4)
            swap(ans[ans.size() - 1], ans[ans.size() - 2]);
        for (auto u:ans)
            if (u != 1)
                printf("%d ", u);
        puts("");
        if (__gcd(ans[1], ans[ans.size() - 1]) == 1)
            puts("1");
        else
            puts("0");
    }
    return 0;
}