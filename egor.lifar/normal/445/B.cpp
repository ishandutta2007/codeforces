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
#include <stack>


using namespace std;


int n, m;
bool used[100];
vector<int> v[100];
int k = 0;
long long ans = 1;


void dfs(int i) {
    used[i] = true;
    k++;
    for (int j = 0; j < v[i].size(); j++) {
        int x = v[i][j];
        if (!used[x]) {
            dfs(x);
        }
    }
}



int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x - 1].push_back(y - 1);
        v[y - 1].push_back(x - 1);
    }
    for (int i = 0; i < n; i++) {
        k = 0;
        if (!used[i]) {
            dfs(i);
            for (int j = 0; j < k - 1; j++) {
                ans *= 2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}