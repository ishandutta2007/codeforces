#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, ans, a[MN], deg[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    fill(deg, deg + n + 1, 0);
    deg[0] = 1;
    for(int i = 2; i <= n; i++) {
        scanf("%lld", &a[i]);
        deg[a[i]]++;
    }

    sort(deg, deg + n + 1, greater<ll>());
    vector<int> vec;
    for (int i = 0; i <= n; i++) {
        if (deg[i]) {
            ans++;
            vec.push_back(deg[i]);
            for (int &x : vec) x--;
            
            vector<int> tmp;
            for (int x : vec) if(x) tmp.push_back(x);
            vec = tmp;
        }
    }

    int cur = 0;
    while(!vec.empty()) {
        ans++;
        int sum = 0;
        
        for (int &x : vec) x--;
        vector<int> tmp;
        for (int x : vec) if(x) {
            tmp.push_back(x);
            sum += x;
        }
        vec = tmp;
        cur++;

        if (cur >= sum) break;
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}