#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, m;
vector<int> dv;
set<int> adj[MN];

int main() {
    scanf("%lld %lld", &n, &m);

    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        int la = b - a;
        if(la < 0) la = n + la;

        int lb = a - b;
        if(lb < 0) lb = n + lb;

        if(la < lb) adj[a].insert(la);
        else if(lb < la) adj[b].insert(lb);
        else {
            adj[a].insert(la);
            adj[b].insert(la);
        }
    }

    dv.push_back(1);
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            dv.push_back(i);
            if(i * i < n) dv.push_back(n / i);
        }
    }

    for(int d : dv) {
        int flag = 1;
        for(int i = 1; flag && i <= n; i++)
            if(adj[i] != adj[(i+d > n) ? i+d-n : i+d])
                flag = 0;

        if(flag) {
            puts("Yes");
            return 0;
        }
    }

    puts("No");
    return 0;
}