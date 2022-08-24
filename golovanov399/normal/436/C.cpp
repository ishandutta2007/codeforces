#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <ctime>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define double long double
#define LL long long
#define itn int
#define mp make_pair
#define x first
#define y second

using namespace std;

int main(){

//  freopen("combo.in", "r", stdin);
//  freopen("combo.out", "w", stdout);

    int n, m, k, w;
    cin >> n >> m >> k >> w;
    vector<vector<string> > s(k, vector<string>(n));
    for (int i = 0; i < k; i++){
        for (int j = 0; j < n; j++) cin >> s[i][j];
    }
    vector<pair<int, pair<int, int> > > e;
    for (int i = 0; i < k; i++){
        for (int j = 0; j < i; j++){
            int x = 0;
            for (int i1 = 0; i1 < n && x * w < n * m; i1++){
                for (int j1 = 0; j1 < m && x * w < n * m; j1++){
                    if (s[i][i1][j1] != s[j][i1][j1]) x++;
                }
            }
            x = min(x * w, n * m);
            e.pb(mp(x, mp(i, j)));
        }
    }
    sort(e.begin(), e.end());
    vector<vector<pair<int, int> > > a(k);
    vector<int> clr(k);
    vector<vector<int> > cnt(k);
    for (int i = 0; i < k; i++){
        cnt[i].pb(i);
        clr[i] = i;
    }
    int ans = 0;
    for (int i = 0; i < e.size(); i++){
        if (clr[e[i].y.x] != clr[e[i].y.y]){
            ans += e[i].x;
            int x = e[i].y.x, y = e[i].y.y;
            a[x].pb(mp(y, e[i].x));
            a[y].pb(mp(x, e[i].x));
            if (cnt[clr[x]].size() < cnt[clr[y]].size()) swap(x, y);
            x = clr[x], y = clr[y];
            while (!cnt[y].empty()){
                cnt[x].pb(cnt[y].back());
                clr[cnt[y].back()] = x;
                cnt[y].pop_back();
            }
        }
    }
    vector<int> st;
    st.pb(0);
    vector<bool> used(k, false);
    used[0] = true;
    cout << ans + n * m << "\n1 0\n";
    while (!st.empty()){
        int x = st.back();
        st.pop_back();
        for (int i = 0; i < a[x].size(); i++){
            if (!used[a[x][i].x]){
                if (a[x][i].y == n * m) cout << a[x][i].x + 1 << " 0\n"; else cout << a[x][i].x + 1 << " " << x + 1 << "\n";
                used[a[x][i].x] = true;
                st.pb(a[x][i].x);
            }
        }
    }

    return 0;
    
}