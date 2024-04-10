#include <bits/stdc++.h>

#define MN 201000

using namespace std;
typedef long long ll;

int n, q, a[MN], fst[MN], lst[MN], ans[MN], lst0;
vector<int> add[MN], rem[MN];
set<int> cur;

int main() {
    scanf("%d %d", &n, &q);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if(!a[i]) {
            lst0 = i;
            continue;
        }

        if(fst[a[i]] == 0) fst[a[i]] = i;
        lst[a[i]] = i;
    }
    fst[1] = 1;
    lst[1] = n+1;
    if(fst[q] == 0) {
        if(lst0 == 0) {
            puts("NO");
            return 0;
        } else {
            fst[q] = lst[q] = lst0;
        }
    }

    for(int i = 1; i <= q; i++) {
        add[fst[i]].push_back(i);
        rem[lst[i]+1].push_back(i);
    }

    for(int i = 1; i <= n; i++) {
        for(int x : rem[i]) cur.erase(x);
        for(int x : add[i]) cur.insert(x);
        assert(!cur.empty());
        int maxi = *(cur.rbegin());
        ans[i] = maxi;
    }

    for(int i = 1; i <= n; i++) {
        if(a[i] && a[i] != ans[i]) {
            puts("NO");
            return 0;
        }
    }

    puts("YES");
    for(int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    puts("");
    return 0;
}