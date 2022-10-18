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
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int k,cnt[1005];
const ll MOD = 1000000007ll;
ll C[2005][2005];

int main()
{
    scanf("%d",&k);
    for (int i = 0; i < k; ++i)
        scanf("%d",&cnt[i]);

    C[0][0] = 1;
    for (int i = 1; i <= 2004; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j <= i-1; ++j)
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
    }

    ll ans = 1;
    int placed = cnt[0];
    for (int i = 1; i < k; ++i) {
        ans = (ans * C[placed + cnt[i] - 1][cnt[i] - 1]) % MOD;
        placed += cnt[i];
    }
    cout << ans;

    return 0;
}