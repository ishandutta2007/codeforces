#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;



int n;
int x, y;
int m[11][11];
int s[101];
vector<int> v[200001];
bool used[200001];
int sumi = 0;


int dfs(int u) {
    used[u] = 1;
    int l = 0;
    for (int i = 0; i < (int)v[u].size(); i++) {
        int h = v[u][i];
        if (!used[h]) {
            int r = dfs(h);
            if (r == 1) {
                l++;
            } else {
                sumi++;
            }
        }
    }
    sumi += max(0, l - 2);
    return l <= 1;
}


int main() {
    cin >> n >> x >> y;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (n <= 10) {
            m[a][b] = 1;
            m[b][a] = 1;
        }
        v[a].push_back(b);
        v[b].push_back(a);
    }
    long long ans = 0;
    bool bb = 1;
    for (int i = 0; i < n; i++) {
        if ((int)v[i].size() == n - 1) {
            ans = 1LL * y * (n - 2) + x;
            bb = 0;
            break;
        }
    }
    if (bb) {
        ans = 1LL * y * (n - 1);
    }
    if (x >= y) {
        cout << ans << endl;
        return 0;
    } 
    dfs(0);
   // cout << sumi << endl;
    ans =  1LL * sumi * y + 1LL * x * (n - 1 - sumi);
    cout << ans << endl;
    return 0;
}