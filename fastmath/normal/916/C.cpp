#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
#define int long long

const int MAXN = 2e5 + 7;
const int P = 1000003;
const int MOD = 1000 * 1000 * 1000;

struct Edge{
    int u, v, c;
};

Edge init(int u, int v, int c){
    Edge res;
    res.u = u;
    res.v = v;
    res.c = c;
    return res;
}

vector <Edge> ans;

signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n - 2; ++i){
        ans.push_back(init(i, i + 1, 1));
    }
    ans.push_back(init(n - 2, n - 1, P - (n - 2)));

    int ost = m - (n - 1);
    for (int i = 0; i < n; ++i){
        if (ost == 0) break;
        for (int j = i + 2; j < n; ++j){
            if (ost == 0) break;
            ans.push_back(init(i, j, MOD));
            --ost;
            if (ost == 0) break;   
        }
        if (ost == 0) break;
    }
    
    cout << P << ' ' << P << '\n';
    for (Edge e: ans){
        cout << e.u + 1 << ' ' << e.v + 1 << ' ' << e.c << '\n';
    }


    return 0;
}