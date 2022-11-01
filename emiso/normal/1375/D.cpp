#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, t, a[MN], tmp[MN];

int mex() {
    for(int i = 0; i < n; i++) {
        tmp[a[i]] = 1;
    }

    int ans = 0;
    while(tmp[ans]) ans++;

    for(int i = 0; i < n; i++) {
        tmp[a[i]] = 0;
    }
    return ans;
}

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    vector<int> op;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    while(!is_sorted(a, a + n)) {
        int m = mex();

        if(m == n) {
            int pos = 0;
            while(a[pos] == pos) pos++;
            op.push_back(pos);
            a[pos] = m;
        } else {
            op.push_back(m);
            a[m] = m;
        }
    }

    printf("%lld\n", (ll)op.size());
    for(int x : op) printf("%d ", x + 1);
    puts("");

    if(--t) goto st;
    return 0;
}