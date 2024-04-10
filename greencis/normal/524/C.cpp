#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,k,a[10005];
int q,x;
map<int,int> mp;

int main()
{
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; ++i) scanf("%d",&a[i]);
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= k; ++j) {
            int cursum = j * a[i];
            if (mp[cursum] == 0) mp[cursum] = j;
            else mp[cursum] = min(mp[cursum], j);
        }
    }
    scanf("%d",&q);
    while (q--) {
        scanf("%d",&x);
        int ans = 2e9;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                int cursum = j * a[i];
                if (cursum == x) ans = min(ans, j);
                else if (cursum > x) continue;
                else {
                    if (mp[x - cursum]) {
                        int moves = j + mp[x - cursum];
                        if (moves <= k) ans = min(ans, moves);
                    }
                }
            }
        }
        if (ans > k) printf("-1\n");
        else printf("%d\n",ans);
    }

    return 0;
}