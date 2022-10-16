#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int n, a, b;

vector<int> adj[100000];
long long tam[100000];

void dfs1(int v, int p) {
    //printf("%d %d\n", v,p);
    tam[v] = 1;

    for (int i = 0; i< adj[v].size(); i++) {
        if (adj[v][i] != p) {
            dfs1(adj[v][i], v);
            tam[v] += tam[adj[v][i]];
        } 
    }
}

long long dfs2(int v, int p) {
    long long a = (tam[v])*(tam[v]-1)/2 * (n-tam[v])*(n-tam[v]-1);

    long long sum = 0;

    for (int i = 0; i < adj[v].size(); i++) {
        if (adj[v][i] != p) {
            //printf("HEY\n" );
            a -= (tam[adj[v][i]])*(tam[adj[v][i]]-1)/2 * (n-tam[v])*(n-tam[v]-1);
            //cout << "from " << v << " into " << adj[v][i] << " take " << (tam[adj[v][i]])*(tam[adj[v][i]]-1)*(n-tam[v])*(n-tam[v]-1)/2 << endl;
            a += dfs2(adj[v][i], v);

            sum += (tam[adj[v][i]])*(tam[adj[v][i]]-1);
        } 
    }

    long long ts = 0;
    for (int i = 0; i < adj[v].size(); i++) {
        if (adj[v][i] != p) {
            ts += (tam[adj[v][i]])*(tam[adj[v][i]]-1);
            a -= (tam[adj[v][i]])*(tam[adj[v][i]]-1)/2 * (sum - ts);
        }
    }

    return a;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n-1; i++) {
        scanf("%d %d", &a, &b); 
        a--; b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(0, -1);
    cout << dfs2(0, -1) << endl;
}