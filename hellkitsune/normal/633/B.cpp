#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

vector<int> ans;

int main() {
    int x;
    scanf("%d", &x);
    int cnt2 = 0, cnt5 = 0;
    for (int i = 2; i <= 500000; ++i) {
        for (int j = i; j % 2 == 0; j /= 2) ++cnt2;
        for (int j = i; j % 5 == 0; j /= 5) ++cnt5;
        if (min(cnt2, cnt5) == x) ans.pb(i);
    }
    printf("%d\n", (int)ans.size());
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}