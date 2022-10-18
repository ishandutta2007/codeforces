#include <iostream>
#include <fstream>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,k,a[9999],sum,mx;
int ans[999][999];
int ans_cnt[999][999];

void fail() {
    cout << "NO";
    exit(0);
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) sum += a[i], mx = max(mx, a[i]);

    for (int i = 0; i < 105; ++i) {
        int curcolor = i % k + 1;
        for (int j = 0; j < n; ++j) {
            if (i >= a[j]) continue;
            ans[j][i] = curcolor;
            ++ans_cnt[j][curcolor];
        }
    }

    for (int i = 0; i < 105; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int z = 0; z < n; ++z) {
                if (abs(ans_cnt[j][i] - ans_cnt[z][i]) >= 2) fail();
            }
        }
    }

    printf("YES\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a[i];++j)
            printf("%d ",ans[i][j]);
        printf("\n");
    }


    return 0;
}