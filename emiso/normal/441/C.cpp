#include <bits/stdc++.h>

using namespace std;

int n, m, k, nm, x, y;

vector<pair<int, int> > ans[100101];

void nxt() {
    x = x + ((y & 1) ? -1 : 1);
    if(x == n || x == -1) {
        y++;
        if(x == -1) x = 0;
        else x = n-1;
    }
    nm--;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    nm = n*m;

    for(int i = 0; i + 1 < k; i++) {
        ans[i].emplace_back(x, y);
        nxt();
        ans[i].emplace_back(x, y);
        nxt();
    }
    while(nm) {
        ans[k-1].emplace_back(x, y);
        nxt();
    }

    for(int i = 0; i < k; i++) {
        printf("%d", ans[i].size());
        for(auto p : ans[i]) printf(" %d %d", p.first + 1, p.second + 1);
        puts("");
    }
    return 0;
}