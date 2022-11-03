#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 1e5 + 13;

/*
0 - end of bambuk
1 - vertex on bambuk
2 - vertex on path

5
1 2
2 3
3 4
4 5

6
1 2
1 3
1 4
1 5
1 6

10
1 2
2 3
2 4
3 5
4 6
1 7
7 8
7 9
9 10

24
1 2
2 3
2 4
3 5
4 6
1 11
11 12
12 13
13 7
7 8
7 9
9 10
11 14
11 15
11 16
11 17
17 18
18 19
17 20
11 21
21 22
21 23
22 24


13
1 2
2 3
2 4
2 5
1 6
6 7
6 8
6 9
1 10
10 11
10 12
10 13

31
1 2
1 3
2 4
2 5
3 6
3 7
4 8
4 9
5 10
5 11
6 12
6 13
7 14
7 15
8 16
8 17
9 18
9 19
10 20
10 21
11 22
11 23
12 24
12 25
13 26
13 27
14 28
14 29
15 30
15 31

24
1 2
2 3
3 4
4 5
5 6
1 7
1 8
1 9
2 10
2 11
2 12
3 13
3 14
3 15
4 16
4 17
4 18
5 19
5 20
5 21
6 22
6 23
6 24

10
1 2
1 3
1 4
2 5
2 6
3 7
3 8
4 9
4 10

12
1 2
3 2
2 4
4 5
5 6
6 7
6 8
4 9
9 10
10 11
10 12

*/

vector<int> g[N];
bool ans = true;

int dfs(int v, int par) {

    vector<int> res;
    vector<int> cnt(4, 0);
    for(int u : g[v]) {
        if(u == par)
            continue;

        res.push_back(dfs(u, v));
        cnt[res.back()]++;
    }

    if(res.size() == 1) {
        if(res[0] >= 1) {
            return 2;
        } else if(res[0] == 0) {
            return 0;
        }
    }

    if(cnt[2] > 1 + (par == v)) {
        ans = false;
        return 0;
    }

    if(res.size() > 2) {
        return 2;
    }

    if(cnt[1] || cnt[2]) {
        return 2;
    }

    if(cnt[0] > 1)
        return 1;

    return 0;
}

mt19937 rnd(time(0));

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    int mx = 0;
    for(int i = 1; i < n; i++)
        if(g[i].size() > g[mx].size())
            mx = i;

    if(g[mx].size() > 3) {
        dfs(mx, mx);
        cout << (ans ? "Yes" : "No") << endl;
    } else {
        vector<int> a;
        for(int i = 0; i < n; i++)
            if(g[i].size() == g[mx].size())
                a.push_back(i);

//        dfs(mx, mx);

        for(int i = 0; i < 10; i++) {
            int root = rnd() % a.size();
            dfs(root, root);
            if(ans) {
                cout << "Yes" << endl;
                return 0;
            }
            ans = true;
        }

        cout << "No" << endl;
    }


}