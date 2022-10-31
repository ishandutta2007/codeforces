#include <bits/stdc++.h>

using namespace std;

#define MN 200020

int n, degIn[MN], degOut[MN];
set<pair<int, int>> adj[MN];
char s[4]; string str[MN], ans;

#define pre(s) (s[0]*256 + s[1])
#define suf(s) (s[1]*256 + s[2])
#define rev(s) {char(s / 256), char(s % 256)}

void euler_cycle(int node, vector<int> &ret, vector<int> &cur) {
    if(adj[node].empty()) {
        ret.push_back(node);
        if(!cur.empty()) {
            node = cur.back();
            cur.pop_back();
            euler_cycle(node, ret, cur);
        }
    } else {
        cur.push_back(node);
        auto edge = *adj[node].begin();
        adj[node].erase(edge);
        adj[edge.first].erase({node, edge.second});
        euler_cycle(edge.first, ret, cur);
    }
}

vector<int> euler_cycle(int node) {
    vector<int> ret, cur;
    euler_cycle(node, ret, cur);
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    scanf("%d", &n);

    int start;
    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        str[i] = s;

        int u = pre(s), v = suf(s);
        degOut[u]++; degIn[v]++;
        adj[u].insert({v, i});
        start = u;
    }

    for(int i = 0; i < n; i++) {
        int u = pre(str[i]);
        if(degIn[u] == degOut[u] - 1)
            start = u;
    }

    vector<int> v = euler_cycle(start);
    ans = rev(start);
    for(int i = 1; i < v.size(); i++) {
        string s1 = rev(v[i-1]), s2 = rev(v[i]);
        if(s1[1] != s2[0]) break;
        ans += char(s2[1]);
    }

    if(ans.size() == n+2)
        printf("YES\n%s\n", ans.c_str());
    else
        puts("NO");
    return 0;
}