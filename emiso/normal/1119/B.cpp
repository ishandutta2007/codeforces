#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], h;
vector<int> v;

int main() {
    scanf("%lld %lld", &n, &h);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    for(int k = 0; k < n; k++) {
        v.push_back(a[k]);
        sort(v.begin(), v.end());

        int cur = 0;
        for(int i = k; i >= 0; i -= 2) {
            cur += v[i];
            if(cur > h) {
                printf("%d\n", k);
                return 0;
            }
        }
    }

    printf("%lld\n", n);
    return 0;
}