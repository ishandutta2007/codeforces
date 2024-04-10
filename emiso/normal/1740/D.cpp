#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, m, k, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld %lld", &n, &m, &k);

    set<int> ja;
    
    for(int i = 0; i < k; i++) {
        scanf("%lld", &a[i]);
    }

    ans = 1;
    int j = 0;
    for (int i = k; ans && i >= 1; i--) {
        while (!ja.count(i)) {
            ja.insert(a[j++]);
        }
        if (ja.size() > n * m - 3) ans = 0;
        ja.erase(i);
    }

    puts(ans ? "YA" : "TIDAK");
    if(--t) goto st;
    return 0;
}