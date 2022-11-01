#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int n, ans[MN];


int main() {
    vector<int> can{1, 2, 4, 5,
                    9, 10, 20, 21,
                    41, 42, 84, 85,
                    169, 170, 340, 341,
                    681, 682, 1364, 1365,
                    2729, 2730, 5460, 5461,
                    10921, 10922, 21844, 21845,
                    43689, 43690, 87380, 87381,
                    174761, 174762, 349524, 349525,
                    699049, 699050};
    for(int x : can) ans[x] = 1;

    scanf("%d", &n);
    printf("%d\n", ans[n]);
    return 0;
}