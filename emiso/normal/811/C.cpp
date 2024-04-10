#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a[5050], dp[5050], fst[5050], lst[5050];
//char s[MN]; string str;

int solve(int pos) {
    if(pos == n) return 0;
    if(dp[pos] != -1) return dp[pos];

    int x = solve(pos + 1);
    int cur = a[pos];

    if(fst[cur] >= pos) {
        int xo = 0, used[5050], bound = 0, flag = 1;
        memset(used, 0, sizeof used);

        for(int i=pos; i<n; i++) {
            if(used[a[i]] == 0) {
                used[a[i]] = 1;
                if(fst[a[i]] < i) flag = 0;

                xo ^= a[i];
                bound = max(bound, lst[a[i]]);
            }

            if(flag && i >= bound) {
                x = max(x, solve(i + 1) + xo);
            }

            if(!flag) break;
        }
    }

    return dp[pos] = x;
}

int main() {
    scanf("%d", &n);

    for(int i=0; i<5050; i++) {
        fst[i] = 10000;
        lst[i] = -1;
        dp[i] = -1;
    }

    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
        fst[a[i]] = min(fst[a[i]], i);
        lst[a[i]] = max(lst[a[i]], i);
    }

    printf("%d\n", solve(0));
    return 0;
}