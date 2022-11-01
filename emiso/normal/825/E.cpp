#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, m, a, b, grau[MN], order[MN], X = 1, c = 1, comp[MN];
vector<int> adj[MN], adj2[MN], cmp[MN];
//char s[MN]; string str;

void topsort() {
    priority_queue<int> pfila;
    for(int i=1; i<=n; i++) {
        if(grau[i] == 0) pfila.push(i);
    }

    while(!pfila.empty()) {
        int pfront = pfila.top();
        pfila.pop();
        order[pfront] = X--;

        for(int i = 0; i <adj[pfront].size(); i++) {
            int v = adj[pfront][i];
            grau[v]--;
            if(grau[v] == 0) pfila.push(v);
        }
    }
}


int main() {
    scanf("%d %d", &n, &m);
    X = n;

    for(int i=0; i<m; i++) {
        scanf("%d %d",&a, &b);
        adj[b].push_back(a);
        grau[a]++;
    }

    topsort();

    for(int i=1; i<=n; i++) {
        printf("%d ", order[i]);
    }
    return 0;
}