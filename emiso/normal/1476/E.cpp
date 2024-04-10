#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, m, k, a[MN], req[MN], h[MN];
char s[MN]; string str[MN], pat[MN];

int g(string& s) {
    int ret = 0;
    for(int j = k-1; j >= 0; j--) {
        ret = 27*ret + ((s[j] == '_') ? 26 : (s[j] - 'a'));
    }
    return ret;
}

int rev[MN], deg[MN];
vector<int> adj[MN];

int main() {
    scanf("%lld %lld %lld", &n, &m, &k);

    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        pat[i] = s;
        h[i] = g(pat[i]);
        rev[h[i]] = i+1;
    }
    for(int i = 0; i < m; i++) {
        scanf("%s %lld", s, &req[i]);
        str[i] = s;

        set<int> pp;
        for(int j = 0; j < (1 << k); j++) {
            string tmp = str[i];
            for(int b = 0; b < k; b++)
                if(j & (1 << b))
                    tmp[b] = '_';
            pp.insert(g(tmp));
        }

        if(pp.count(h[req[i]-1])) {
            for(int x : pp) {
                if(x != h[req[i]-1]) {
                    adj[h[req[i]-1]].push_back(x);
                    deg[x]++;
                }
            }
        } else {
            puts("NO");
            exit(0);
        }
    }

    queue<int> fila;
    for(int i = 0; i < MN; i++)
        if(rev[i] && deg[i] == 0)
            fila.push(i);

    vector<int> ans;
    while(!fila.empty()) {
        int u = fila.front();
        fila.pop();
        ans.push_back(rev[u]);
        for(int v : adj[u]) {
            deg[v]--;
            if(rev[v] && deg[v] == 0)
                fila.push(v);
        }
    }

    if(ans.size() != n) {
        puts("NO");
    } else {
        puts("YES");
        for(int x : ans) printf("%d ", x);
    }
    return 0;
}