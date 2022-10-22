#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <random>
#include <time.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;
#define int long long

const int MAXN = 2007;
vector <int> g[MAXN];

bool good[MAXN];

void dfs(int u, int parent){
    int counter = 0;
    int good_cnt = 0;
    for (int v: g[u]){
        if (v == parent) continue;
        dfs(v, u);
        ++counter;
        good_cnt += good[v];
    }

    if (counter == 0){
        good[u] = true;
    }
    else if (good_cnt < 3){
        cout << "No\n";
        exit(0);
    }
}

signed main(){  
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i){
        int v;
        cin >> v;
        g[i].push_back(v - 1);
        g[v - 1].push_back(i);
    }

    dfs(0, -1);

    cout << "Yes\n";
    return 0;
}