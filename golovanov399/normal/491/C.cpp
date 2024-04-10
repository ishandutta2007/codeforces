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
#define float long double
#define LL long long
#define itn int
#define mp make_pair
#define x first
#define y second

using namespace std;

int f(char c){
    if (c >= 'a' && c <= 'z')
        return c - 'a';
    else
        return c - 'A' + 26;
}

int main(){

    // freopen("aplusb.in", "r", stdin);
    // freopen("aplusb.out", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    vector<vector<int> > a(k, vector<int>(k, 0));
    for (int i = 0; i < n; i++){
        a[f(s[i])][f(t[i])]--;
    }
    
    vector<int> u (k+1), v (k+1), p (k+1), way (k+1);
    for (int i=1; i<=k; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<int> minv (k+1, n + n);
        vector<char> used (k+1, false);
        do {
            used[j0] = true;
            int i0 = p[j0],  delta = n + n,  j1;
            for (int j=1; j<=k; ++j)
                if (!used[j]) {
                    int cur = a[i0 - 1][j - 1]-u[i0]-v[j];
                    if (cur < minv[j])
                        minv[j] = cur,  way[j] = j0;
                    if (minv[j] < delta)
                        delta = minv[j],  j1 = j;
                }
            for (int j=0; j<=k; ++j)
                if (used[j])
                    u[p[j]] += delta,  v[j] -= delta;
                else
                    minv[j] -= delta;
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    vector<int> ans(k);
    for (int i = 0; i < k; i++)
        ans[p[i + 1] - 1] = i;
    int res = 0;
    for (int i = 0; i < k; i++){
        res -= a[i][ans[i]];
    }
    cout << res << "\n";
    for (int i = 0; i < k; i++)
        putchar((ans[i] < 26) ? 'a' + ans[i] : 'A' + ans[i] - 26);
    cout << "\n";

    return 0;
}