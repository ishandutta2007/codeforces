#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;


int n, k;
int t[100001];
bool good[100001];
vector<int> v[100001];


int main() {
    cin >> n >> k;
    int ans = 0;
    int g = 0;
    for (int i = 0; i < k; i++) {
        int m;
        scanf("%d", &m);
        ans += m - 1;
        for (int j = 0; j < m; j++) {
            int a;
            scanf("%d", &a);
            v[i].push_back(a);
            t[a] = i;
        }
        int g1 = 0;
        for (int j = 0; j < m; j++) {
            if (v[i][j] != j + 1) {
                break;
            }
            g1++;
        }
        g = max(g, g1);
    }
    ans += n - 1;
    ans -= (g > 1 ? g - 1 + g - 1: 0);
    cout << ans << endl;
    return 0;
}