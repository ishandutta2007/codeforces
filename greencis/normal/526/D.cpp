#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <deque>
#include <bitset>
using namespace std;
typedef long long ll;

ll BASE1 = 37ll, MOD1 = 1000000007ll, hash1[1001005], p1[1001005];
ll BASE2 = 53ll, MOD2 = 1000000009ll, hash2[1001005], p2[1001005];

int n,k,pi[1001005];
char s[1001005],ans[1001005];

void calc_hash() {
    p1[0] = p2[0] = 1ll;
    hash1[0] = hash2[0] = s[0] - 'a' + 1;
    for (int i = 1; i < n + 5; ++i) {
        p1[i] = (p1[i-1] * BASE1) % MOD1;
        p2[i] = (p2[i-1] * BASE2) % MOD2;
        hash1[i] = (hash1[i-1] * BASE1 + ll(s[i] - 'a' + 1)) % MOD1;
        hash2[i] = (hash2[i-1] * BASE2 + ll(s[i] - 'a' + 1)) % MOD2;
    }
}

ll get_hash1(int L, int R) {
    if (L == 0) return hash1[R];
    ll curans = (hash1[R] - hash1[L-1] * p1[R-L+1]) % MOD1;
    if (curans < 0ll) curans += MOD1;
    return curans;
}

ll get_hash2(int L, int R) {
    if (L == 0) return hash2[R];
    ll curans = (hash2[R] - hash2[L-1] * p2[R-L+1]) % MOD2;
    if (curans < 0ll) curans += MOD2;
    return curans;
}

vector< pair<int,int> > v;

int main()
{
    scanf("%d%d%s",&n,&k,s);
    for (int i = 0; i < n; ++i) ans[i] = '0';

    if (k == 1) {
        for (int i = 0; i < n; ++i) ans[i] = '1';
        printf("%s",ans);
        return 0;
    }

    calc_hash();

    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;

        int len = i + 1 - pi[i];
        if ((i + 1) % len == 0 && ((i + 1) / len) % k == 0) {
            int L = 0, R = min((i + 1) / k, n - i - 1);
            while (L < R) {
                int mid = (L + R + 1) >> 1;
                if (get_hash1(0, mid-1) != get_hash1(i + 1, i + mid) ||
                    get_hash2(0, mid-1) != get_hash2(i + 1, i + mid))
                    R = mid - 1;
                else L = mid;
            }
            v.push_back(make_pair(i, -1));
            v.push_back(make_pair(i+L+1, 1));
        }
    }

    sort(v.begin(), v.end());
    int curbalance = 0;
    int previdx = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (curbalance)
            for (int j = previdx; j < v[i].first; ++j)
                ans[j] = '1';
        curbalance -= v[i].second;
        previdx = v[i].first;
    }

    printf("%s",ans);

    return 0;
}