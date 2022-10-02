#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <unordered_map>
#include <cassert>


using namespace std;


int n;
vector<int> v[100001];
int size[100001];
double ans[100001];


void dfs1(int u) {
    size[u] = 1;
    for (int i = 0; i < (int)v[u].size(); i++) {
        int h = v[u][i];
        dfs1(h);
        size[u] += size[h];
    }
}


void dfs2(int u, double sum) {
    ans[u] = 1 + sum;
    for (int i = 0; i < (int)v[u].size(); i++) {
        int h = v[u][i];
        sum += (double)size[h] / 2.0;
    }
    sum++;
    for (int i = 0; i < (int)v[u].size(); i++) {
        int h = v[u][i];
        dfs2(h, sum - (double)size[h] / 2.0);
    }
}


int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int p;
        scanf("%d", &p);
        v[p - 1].push_back(i);
    }
    dfs1(0);
    dfs2(0, 0.0);
    for (int i = 0; i < n; i++) {
        printf("%.10lf ", ans[i]);
    }
    printf("\n");
    return 0;
}