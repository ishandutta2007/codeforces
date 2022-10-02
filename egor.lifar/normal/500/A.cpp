#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>


using namespace std;


int n, t;
int a[3000000];
vector<int> v[3000000];
bool used[100000];


void dfs(int u) {
    used[u] = true;
    for (int j = 0; j < (int)v[u].size(); j++) {
        int g = v[u][j];
        if (!used[g]) {
            dfs(g);
        }
    }
}


int main() {
    cin >> n >> t;
    t--;
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
        v[i].push_back(i + a[i]);
    }
    dfs(0);
    if (used[t]) {
        cout << "YES" << endl; 
    } else {
        cout << "NO" << endl;
    }
    return 0;
}