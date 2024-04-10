#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <unordered_map>


using namespace std;


int n, q;
vector<int> v[300001];
int centroid[300001];
int size[300001];
int pr[300001];


void dfs(int u) {
    if ((int)v[u].size() == 0) {
        centroid[u] = u;
        size[u] = 1;
        return;
    }
    size[u] = 1;
    for (int i = 0; i < (int)v[u].size(); i++) {
        int h = v[u][i];
        dfs(h);
        size[u] += size[h];
    }
    int bad = 0;
    for (int i = 0; i < (int)v[u].size(); i++) {
        int h = v[u][i];
        if (size[h] > size[u] / 2) {
            bad = h + 1;
            break;
        }
    }
    if (!bad) {
        centroid[u] = u;
        return; 
    }
    //cout << u + 1 << endl;
    int vertex = centroid[bad - 1];
    while (size[u] - size[vertex] > size[u] / 2) {
        vertex = pr[vertex];
    }   
    centroid[u] = vertex;
}


int main() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int p;  
        scanf("%d", &p);
        p--;
        pr[i] = p;
        v[p].push_back(i);
    }
    dfs(0);
    for (int i = 0; i < q; i++) {
        int a;
        scanf("%d", &a);
        a--;
        printf("%d\n", centroid[a] + 1);
    }
    return 0;
}