#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, a[MN], f[40], ja[MN];
vector<int> occ[40], ans;

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        for(int b = 0; b <= 30; b++) {
            if((1 << b) & a[i]) {
                f[b]++;
                occ[b].push_back(i);
            }
        }
    }

    for(int b = 30; b >= 0; b--) {
        if(f[b] == 1 && !ja[occ[b][0]]) {
            ans.push_back(a[occ[b][0]]);
            ja[occ[b][0]] = 1;
        }
    }

    for(int i = 0; i < n; i++) {
        if(!ja[i]) ans.push_back(a[i]);
    }

    for(int x : ans) printf("%d ", x);
    return 0;
}