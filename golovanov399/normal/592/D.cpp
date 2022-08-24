#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
    int x;
    scanf("%d", &x);
    return x;
}

const int N = 133333;
vector<int> a[N];
pair<int, int> far[N], ans[N];
char used[N];
char attack[N];
char was[N];
int dst[N];
int level[N];

void dfs(int v){
    used[v] = 1;
    far[v] = {-N, -v};
    ans[v] = {-N, -v};
    if (attack[v]){
        far[v] = ans[v] = {0, -v};
    }
    pair<int, int> v1, v2;
    v1 = v2 = {-1, -1};
    for (auto x : a[v]){
        if (!used[x]){
            level[x] = level[v] + 1;
            dfs(x);
            if (far[x].first >= 0)
                dst[v] += 2 + dst[x];
            pair<int, int> farc = far[x];
            farc.first++;
            if (farc > far[v])
                far[v] = farc;
            if (ans[x] > ans[v])
                ans[v] = ans[x];
            if (farc > v2){
                if (farc > v1){
                    v2 = v1;
                    v1 = farc;
                } else {
                    v2 = farc;
                }
            }
        }
    }
    if (attack[v]){
        pair<int, int> cand = {0, -v};
        if (cand > v2){
            if (cand > v1){
                v2 = v1;
                v1 = cand;
            } else {
                v2 = cand;
            }
        }
    }
    pair<int, int> vcand = {v1.first + v2.first, max(v1.second, v2.second)};
    if (v2.first > -1 && vcand > ans[v]){
        ans[v] = vcand;
    }
    if (v2.first > -1 || attack[v])
        was[v] = 1;
}

int main(){

    int n = nxt(), m = nxt();
    for (int i = 0; i < n - 1; i++){
        int x = nxt() - 1, y = nxt() - 1;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 0; i < m; i++)
        attack[nxt() - 1] = 1;

    dfs(0);

    int minlevel = INT_MAX;
    for (int i = 0; i < n; i++){
        if (was[i])
            minlevel = min(minlevel, level[i]);
    }
    cout << 1 - ans[0].second << "\n" << dst[0] - 2 * minlevel - ans[0].first << "\n";

    return 0;
}