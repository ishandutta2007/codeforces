#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

int main(){

    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int> > a(n);
    for (int i = 0; i < m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    vector<int> s(4), l(2);
    for (int i = 0; i < 2; i++){
        scanf("%d%d%d", &s[i + i], &s[i + i + 1], &l[i]);
    }
    for (int i = 0; i < 4; i++){
        s[i]--;
    }

    vector<vector<int> > dd(4, vector<int>(n, -1));
    for (int j = 0; j < 4; j++){
        dd[j][s[j]] = 0;
        vector<char> used(n, 0);
        while (true){
            int cur = -1;
            for (int i = 0; i < n; i++){
                if (!used[i] && dd[j][i] > -1 && (cur == -1 || dd[j][i] < dd[j][cur]))
                    cur = i;
            }
            if (cur == -1)
                break;
            used[cur] = 1;
            for (auto x : a[cur]){
                if (dd[j][x] == -1 || dd[j][x] > dd[j][cur] + 1)
                    dd[j][x] = dd[j][cur] + 1;
            }
        }
    }
    int ans;
    if (dd[0][s[1]] > l[0] || dd[2][s[3]] > l[1]){
        puts("-1");
        return 0;
    }
    else ans = dd[0][s[1]] + dd[2][s[3]];

    // for (int i = 0; i < 4; i++){
    //  for (int j = 0; j < n; j++){
    //      cerr << dd[i][j] << " ";
    //  }
    //  cerr << "\n";
    // }

    for (int i = 0; i < n; i++){
        queue<int> q;
        q.push(i);
        vector<int> dst(n, -1);
        dst[i] = 0;
        while (!q.empty()){
            int v = q.front();
            q.pop();
            for (auto x : a[v]){
                if (dst[x] == -1){
                    dst[x] = dst[v] + 1;
                    q.push(x);
                }
            }
        }
        for (int j = 0; j < n; j++){
            if (dd[0][i] + dst[j] + dd[1][j] <= l[0] && dd[2][i] + dst[j] + dd[3][j] <= l[1])
                ans = min(ans, dd[0][i] + dd[1][j] + dd[2][i] + dd[3][j] + dst[j]);
            if (dd[0][i] + dst[j] + dd[1][j] <= l[0] && dd[2][j] + dst[j] + dd[3][i] <= l[1])
                ans = min(ans, dd[0][i] + dd[1][j] + dd[2][j] + dd[3][i] + dst[j]);
        }
    }
    printf("%d\n", m - ans);

    return 0;
}