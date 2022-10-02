#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string.h>
#include <stdio.h>
#include <algorithm>


using namespace std;


const long long MOD = (int)1e9 + 7;
const int MAXN = 200002;
int n;
int a[MAXN];
int used[MAXN];
vector<int> cycles;


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }
    int other = n;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            int j = i;
            used[j] = i + 1;
            while (!used[a[j]]) {
                j = a[j];
                used[j] = i + 1;
            }
            if (used[a[j]] == i + 1) {
                int g = a[j];
                int cnt = 1;
                other--;
                while (g != j) {
                    cnt++;
                    other--;
                    g = a[g];
                }
                cycles.push_back(cnt);
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < other; i++) {
        ans = (2LL * ans) % MOD;
    }
    for (int i = 0; i < (int)cycles.size(); i++) {
        int ans1 = 1;
        for (int j = 0; j < cycles[i]; j++) {
            ans1 = (2LL * ans1) % MOD;
        }
        ans1 -= 2;
        if (ans1 < 0) {
            ans1 += MOD;
        }
        ans = (1LL * ans * ans1) % MOD;
    }
    cout << ans << endl;
    return 0;
}