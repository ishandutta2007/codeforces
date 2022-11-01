#include <bits/stdc++.h>

#define MN 2002

using namespace std;
typedef long long ll;

ll n, ans, c[MN], p[MN], root;
vector<ll> adj[MN];
vector<pair<int, int>> a[MN];

void solve(int no) {
    if(adj[no].empty()) {
        if(c[no] == 0) a[no].emplace_back(no, 1);
        else {
            puts("NO");
            exit(0);
        }
    }
    else {
        int acum = 0, ab = 0;
        for(auto ch : adj[no]) {
            solve(ch);
            ab = acum;
            for(auto tt : a[ch]) {
                if(acum == c[no]) {
                    acum++;
                    ab++;
                    a[no].emplace_back(no, acum);
                }
                a[no].emplace_back(tt.first, tt.second + ab);
                acum++;
            }
            if(acum == c[no]) {
                acum++;
                ab++;
                a[no].emplace_back(no, acum);
            }
        }

        if(acum < c[no]) {
            puts("NO");
            exit(0);
        }
    }
}

int main() {
    scanf("%lld", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%lld %lld", &p[i], &c[i]);
        adj[p[i]].push_back(i);
        if(p[i] == 0) root = i;
    }

    solve(root);

    puts("YES");
    sort(a[root].begin(), a[root].end());
    for(auto tt : a[root]) printf("%d ", tt.second);
    return 0;
}

/*
10
0 9
1 0
1 1
1 3
2 0
2 0
3 0
3 0
4 0
4 0
*/