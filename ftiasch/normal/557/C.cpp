#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>

const int N = 100000;

int l[N];
std::vector <int> d[N + 1];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", l + i);
    }
    int suf = 0;
    for (int i = 0; i < n; ++ i) {
        int t;
        scanf("%d", &t);
        suf += t;
        d[l[i]].push_back(t);
    }
    int result = INT_MAX;
    int sum = 0;
    std::multiset <int> set;
    for (int l = 1; l <= 100000; ++ l) {
        for (int t : d[l]) {
            suf -= t;
        }
        if (!d[l].empty()) {
            int cost = sum + suf;
            int left = (int)d[l].size() - 1;
            for (int t : set) {
                if (left == 0) {
                    break;
                }
                cost += t;
                left --;
            }
            result = std::min(result, cost);
        }
        for (int t : d[l]) {
            sum += t;
            set.insert(-t);
        }
    }
    printf("%d\n", result);
    return 0;
}