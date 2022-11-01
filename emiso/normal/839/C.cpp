#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a, b;
vector<int> adj[MN];

double solve(int no, int parent = -1) {
    double prob = 0;
    int nc = adj[no].size() - (parent != -1);
    if(nc == 0) return 0;

    for(int i=0; i<adj[no].size(); i++) {
        if(adj[no][i] != parent) {
            prob += (solve(adj[no][i], no) + 1.0) / nc;
        }
    }

    return prob;
}

int main() {
    scanf("%d", &n);

    for(int i=1; i<n; i++) {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    printf("%.9f\n", solve(1));
    return 0;
}