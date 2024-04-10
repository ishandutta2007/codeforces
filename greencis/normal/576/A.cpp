#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long double ld;
typedef long long ll;

int n;
vector<int> ans;

int main()
{
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        bool pr = true;
        for (int j = 2; j * j <= i; ++j)
            if (i % j == 0) { pr = false; break; }
        if (!pr) continue;
        int qqq = i;
        while (qqq <= n) ans.push_back(qqq), qqq *= i;
    }

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]);

    return 0;
}