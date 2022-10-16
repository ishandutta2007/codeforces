#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

long long n;
int m;

struct edge {
    int a, b;
};

vector<int> adj[1000000];
vector<int> sets[1000000];
int incident[1000000];
int id[1000000];
bool mark[1000000];

int compara(int a, int b) {
    return incident[a] < incident[b];
}

int uni(int a, int b) {
    int i = 0, j = 0;
    int resp = 0;
    while (i < sets[a].size() && j < sets[b].size()) {
        if (sets[a][i] == sets[b][j]) {
            resp++;
            i++;
            j++;
        }
        else if (sets[a][i] < sets[b][j]) i++;
        else j++;
    }
    return resp;
}

int main() {
    cin >> n >> m;

    long long tria = n*(n-1)*(n-2)/6;
    long long alice = 0;
    long long rem = 0;

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;

        incident[a]++; incident[b]++;

        adj[a].push_back(b);
        adj[b].push_back(a);

        rem += n-2;
    }

    sort(id, id+n, compara);

    for (int i = 0; i < n; i++) {
        int v = id[i];
        mark[v] = 1;

        for (int e = 0; e < adj[v].size(); e++) {
            if (mark[adj[v][e]]) {
                alice += uni(v,adj[v][e]);
            }
            else sets[adj[v][e]].push_back(i);
        }
        adj[v].clear();

        rem -= ((long long)incident[i])*(incident[i]-1)/2;
    } 

    cout << alice - rem + tria << endl;
}