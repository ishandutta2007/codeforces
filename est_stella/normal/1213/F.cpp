#include<bits/stdc++.h>
using namespace std;

int n, k;
int p[200010];
int q[200010];
int in[200010];
int scc[200010];
bool chk[200010];
char output[200010];
vector<int> e[200010];
vector<int> re[200010];
vector<int> g[200010];
stack<int> st;
queue<int> Q;


int dfs(int x) {
    chk[x] = true;
    for(int i=0; i<e[x].size(); i++) {
        if(chk[e[x][i]]) continue;
        dfs(e[x][i]);
    }
    st.push(x);
}

int rdfs(int x, int t) {
    chk[x] = true;
    for(int i=0; i<re[x].size(); i++) {
        if(chk[re[x][i]]) continue;
        rdfs(re[x][i], t);
    }
    scc[x] = t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i=0; i<n; i++) {
        cin >> p[i];
        if(i > 0) e[p[i-1]].push_back(p[i]), re[p[i]].push_back(p[i-1]);
    }

    for(int i=0; i<n; i++) {
        cin >> q[i];
        if(i > 0) e[q[i-1]].push_back(q[i]), re[q[i]].push_back(q[i-1]);
    }

    for(int i=1; i<=n; i++) {
        if(chk[i]) continue;

        dfs(i);
    }

    memset(chk, 0, sizeof(chk));

    int cnt = 0;
    while(st.size()) {
        int x = st.top();
        st.pop();

        if(chk[x]) continue;

        rdfs(x, cnt);
        cnt++;
    }

    for(int i=1; i<n; i++) {
        if(scc[p[i-1]] != scc[p[i]]) g[scc[p[i-1]]].push_back(scc[p[i]]), in[scc[p[i]]]++;
        if(scc[q[i-1]] != scc[q[i]]) g[scc[q[i-1]]].push_back(scc[q[i]]), in[scc[q[i]]]++;
    }

    for(int i=0; i<cnt; i++) {
        if(in[i] == 0) Q.push(i);
    }

    int ans = 0;
    while(Q.size()) {
        int x = Q.front();
        Q.pop();
        output[x] = min(ans, k-1) + 'a';
        ans++;
        cnt--;

        for(int i=0; i<g[x].size(); i++) {
            in[g[x][i]]--;
            if(in[g[x][i]]) Q.push(g[x][i]);
        }
    }

    if(cnt!=0 || ans < k) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    for(int i=1; i<=n; i++) {
        cout << output[scc[i]];
    }
}