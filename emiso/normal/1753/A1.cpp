#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    int nonzero = 0;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        nonzero += (a[i] != 0);
    }

    if (nonzero % 2) {
        printf("-1\n");
    } else {
        vector<pair<int, int>> v;

        int r = 0;

        while (r < n) {
            if (a[r] == 0) {
                v.push_back({r, r});
                r++;
            } else {
                int j = r + 1;
                while (a[j] == 0) j++;
                
                int zeros = j - r - 1;
                if (zeros % 2 == 0) {
                    if (a[r] == a[j]) {
                        v.push_back({r, j});
                        r = j+1;
                    } else {
                        v.push_back({r, j-1});
                        v.push_back({j, j});
                        r = j+1;
                    }
                } else {
                    if (a[r] == a[j]) {
                        v.push_back({r, j-2});
                        v.push_back({j-1, j});
                        r = j+1;
                    } else {
                        v.push_back({r, j});
                        r = j+1;
                    }
                }
            }
        }

        printf("%d\n", (int)v.size());
        for (auto tt : v)
            printf("%d %d\n", tt.first + 1, tt.second + 1);
    }

    if(--t) goto st;
    return 0;
}