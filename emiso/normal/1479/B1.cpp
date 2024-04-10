#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, a[MN];
vector<int> row2;

inline int my_rand() {
    return ((rand()<< 16) ^ rand()) & 0x7fffffff;
}

/**
15
3 1 1 2 3 1 1 2 2 3 2 1 2 3 3

7
3 1 1 2 3 1 1
**/

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if(i && a[i] == a[i-1]) row2.push_back(a[i]);
    }

    ll l1 = -1, l2 = -1, ans = 0;
    for(int i = 0, j = 0; i < n; i++) {
        if(a[i] == l1) {
            if(a[i] != l2) ans++;
            l2 = a[i];
        } else {
            if(a[i] == l2 || j == row2.size()) {
                ans++;
                l1 = a[i];
            } else {
                ans++;
                if(l1 == row2[j]) l1 = a[i];
                else l2 = a[i];
            }
        }
        if(i + 1 < n && a[i] == a[i+1]) j++;
    }
    printf("%lld\n", ans);
    return 0;
}