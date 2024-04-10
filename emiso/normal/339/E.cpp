#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> cfg;

int n, a[1010];
map<cfg, cfg> dist;

queue<cfg> fila;
int nxt(int l, int r, cfg& tmp, cfg& u) {
    cfg v;
    for(auto tt : tmp) {
        if(!v.empty()&& abs(tt.first - v.back().second) == 1) {
            v.back().second = tt.second;
        }
        else v.push_back(tt);
    }
    if(!dist.count(v)) {
        dist[v] = dist[u];
        dist[v].emplace_back(l + 1, r);
        fila.push(v);
    }
    if(v == cfg({{1, n}})) return true;
    return false;
}

void bfs(cfg ini) {
    dist[ini];
    fila.push(ini);

    while(!fila.empty()) {
        cfg u = fila.front();
        fila.pop();

        for(int i = 0, l = 0; i < u.size(); l += abs(u[i].first - u[i].second) + 1, i++) {
            for(int j = i, r=l+abs(u[i].first-u[i].second)+1; j < u.size(); j++, r+=((j == u.size()) ? 0 : abs(u[j].first-u[j].second))+1) {
                cfg tmp = u, v;
                reverse(tmp.begin() + i, tmp.begin() + j + 1);
                for(int k = i; k <= j; k++) tmp[k] = {tmp[k].second, tmp[k].first};
                if(nxt(l, r, tmp, u)) return;

                if(abs(u[i].first - u[i].second) == 1) {
                    tmp = u;
                    tmp.insert(tmp.begin() + i, tmp[i]);
                    tmp[i].second = tmp[i].first;
                    tmp[i+1].first = tmp[i+1].second;

                    reverse(tmp.begin() + i + 1, tmp.begin() + j + 2);
                    for(int k = i + 1; k <= j + 1; k++) tmp[k] = {tmp[k].second, tmp[k].first};
                    if(nxt(l + 1, r, tmp, u)) return;
                } else if(j > i && abs(u[j].first - u[j].second) == 1) {
                    tmp = u;
                    tmp.insert(tmp.begin() + j, tmp[j]);
                    tmp[j].second = tmp[j].first;
                    tmp[j+1].first = tmp[j+1].second;

                    reverse(tmp.begin() + i, tmp.begin() + j + 1);
                    for(int k = i; k <= j; k++) tmp[k] = {tmp[k].second, tmp[k].first};
                    if(nxt(l, r - 1, tmp, u)) return;
                }

            }
        }
    }
}

int main() {
    scanf("%d", &n);

    cfg c;
    int last = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(i && abs(a[i] - a[i-1]) > 1) {
            c.emplace_back(a[last], a[i-1]);
            last = i;
        }
    }
    c.emplace_back(a[last], a[n-1]);
    bfs(c);

    cfg ans = dist[{{1, n}}];
    reverse(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for(auto tt : ans) printf("%d %d\n", tt.first, tt.second);
    return 0;
}