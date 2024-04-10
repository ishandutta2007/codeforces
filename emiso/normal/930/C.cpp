#include <bits/stdc++.h>

#define MN 1001000
#define debug(args...) for(auto x : {args}) cerr << x << " "; cerr << endl;
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, m, l, r, ans, a[MN], lis_up[MN], lis_down[MN];

bool cmp(int x ,int y) {
    return (a[x] < a[y]);
}

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &l, &r);
        a[l]++;
        a[r+1]--;
    }

    for(int i = 1; i <= m; i++) {
        a[i] += a[i-1];
    }

    vector <int> b;
    vector<int>::iterator it;

    for(int i = 1; i <=m; i++) {
        it = upper_bound(b.begin(), b.end(), i, cmp);

        if(it == b.end()) {
            b.push_back(i);
            it = --b.end();
        }
        else {
            *it = i;
        }

        lis_up[i] = it - b.begin() + 1;
    }

    b.clear();
    reverse(a + 1, a + m + 1);

    for(int i = 1; i <= m; i++) {
        it = upper_bound(b.begin(), b.end(), i, cmp);

        if(it == b.end()) {
            b.push_back(i);
            it = --b.end();
        }
        else {
            *it = i;
        }

        lis_down[m-i+1] = it - b.begin() + 1;
    }

    for(int i = 1; i <= m; i++) {
        ans = max(ans, lis_up[i] + lis_down[i] - 1);
    }

    printf("%d\n", ans);
    return 0;
}