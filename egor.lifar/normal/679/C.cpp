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


int n, kk;
string s[501];
int c[501][501];
int uk = 1;
bool used[501][501];
int cnt[250001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int cntt = 0;
int sizev[250001];


void dfs(int i, int j) {
    used[i][j] = 1;
    c[i][j] = uk;
    cntt++;
    for (int k = 0; k < 4; k++) {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 < 0 || j1 < 0 || i1 >= n || j1 >= n) {
            continue;
        }
        if (!used[i1][j1] && s[i1][j1] == '.') {
            dfs(i1, j1);
        }
    }
}
 

int main() {
    cin >> n >> kk;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!used[i][j] && s[i][j] == '.') {
                cntt = 0;
                dfs(i, j);
                sizev[uk] = cntt;
                ans = max(ans, cntt);
                uk++;
            }
        }
    }
    for (int i = 0; i <= n - kk; i++) {
        for (int j = 1; j < uk; j++) {
            cnt[j] = 0;
        }
        for (int j = 0; j <= n - kk; j++) {
            if (j == 0) {
                for (int i1 = i; i1 < i + kk; i1++) {
                    for (int j1 = j; j1 < j + kk; j1++) {
                        cnt[c[i1][j1]]++;
                    }
                }
            } else {
                for (int k = i; k < i + kk; k++) {
                    cnt[c[k][j + kk - 1]]++;
                    cnt[c[k][j - 1]]--;
                } 
            }
            vector<int> v;
            for (int k = i; k < i + kk; k++) {
                if (k != n) {
                    if (j != 0) {
                        v.push_back(c[k][j - 1]);
                    }
                    if (j + kk != n) {
                        v.push_back(c[k][j + kk]);
                    }
                }      
            }
            for (int k = j; k < j + kk; k++) {
                if (k != n) {
                    if (i != 0) {
                        v.push_back(c[i - 1][k]);
                    }
                    if (i + kk != n) {
                        v.push_back(c[i + kk][k]);
                    }
                }
            }
            sort(v.begin(), v.end());
            v.resize(distance(v.begin(), unique(v.begin(), v.end())));
            int sum = kk * kk;
            for (int k = 0; k < (int)v.size(); k++) {
                if (v[k]) {
                    sum += sizev[v[k]];
                    sum -= cnt[v[k]];
                }
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;   
}