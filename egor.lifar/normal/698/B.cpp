#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>
 
 
using namespace std;
 
 
int n;
int a[200001];
bool used[200001];
vector<int> v[200001];
int ans = 0;


void dfs(int u, int p) {
    used[u] = 1;
    for (int i = 0; i < (int)v[u].size(); i++) {
        int h = v[u][i];
        if (h == u) {
            continue;
        }
        if (!used[h]) {
            dfs(h, u);
        } else {
            if (h != p) {
                ans = h + 1;
            }
        }
    }
}

 
int main() {
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == i + 1) {
            cnt++;
        }
    }
    int sum = 0;
    int c = 0;
    if (cnt != 0) {
        sum += cnt - 1;
        bool b = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == i + 1) {
                if (!b) {
                    c = i + 1;
                    b = 1;
                } else {
                    a[i] = c;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        v[a[i] - 1].push_back(i);
        v[i].push_back(a[i] - 1);
    }
    for (int j = 0; j < n; j++) {
        if (!used[j]) {
            ans = 0;
            dfs(j, -1);
            int f = ans;
            if (f) {
                sum++;
                f--;
                //cout << "opa" << endl;
                if (c == 0) {
                    c = f + 1;
                    a[f] = f + 1;
                } else {
                    a[f] = c;
                }
            }
        }
    }
    cout << sum << endl;
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}