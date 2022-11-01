#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int n, t, a[MN], b[MN], ops, l, r;
vector<int> ans;

pair<int, int> get() {
    pair<int, int> ret;
    if(ops % 2 == 0) ret = {a[l], a[r]};
    else ret = {1-a[r], 1-a[l]};
    return ret;
}

void put() {
    ops++;
    if(ops % 2 == 0) r--;
    else l++;
}

int main() {
    scanf("%d", &t);
    st:
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%1d", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%1d", &b[i]);
    }

    ans.clear();
    ops = 0;
    l = 0, r = n-1;

    for(int i = n - 1; i >= 0; i--) {
        if(get().second == b[i]) {
            if(ops % 2 == 0) r--;
            else l++;
            continue;
        } else {
            if(get().first == b[i]) ans.push_back(0);
            ans.push_back(i);
            put();
        }
    }

    printf("%d", ans.size());
    for(int x : ans) printf(" %d", x + 1);
    puts("");

    if(--t) goto st;
    return 0;
}