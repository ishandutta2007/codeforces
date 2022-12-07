#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
vector<int> g[1000000];
int val[1000000];
vector<int> nums;
int sum = 0;

bool dfs(int v, int par) {
    bool flag = false;
    for (int to : g[v]) if (to != par) {
        if (dfs(to, v)) {
            flag = true;
        }
        val[v] += val[to];
    }
    if (par != -1) {
        if ((flag && val[v] == 2 * sum) || (!flag && val[v] == sum)) {
            flag = true;
            nums.pb(v);
            if (int(nums.size()) == 2) {
                cout << nums[0] + 1 << ' ' << nums[1] + 1 << endl;
                exit(0);
            }
        }
    }
    return flag;
}

int main() {
    scanf("%d", &n);
    int st = -1;
    forn(i, n) {
        int to;
        scanf("%d%d", &to, val + i), --to;
        if (to == -1) {
            st = i;
        } else {
            g[i].pb(to);
            g[to].pb(i);
        }
        sum += val[i];
    }
    if (sum % 3 != 0) {
        cout << -1 << endl;
        return 0;
    }
    sum /= 3;
    dfs(st, -1);
    cout << -1 << endl;
    return 0;
}