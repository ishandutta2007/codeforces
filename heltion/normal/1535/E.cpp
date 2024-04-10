#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int q;
    cin >> q;
    vector<int> a(q + 1), c(q + 1);
    vector<vector<int>> f(20, vector<int>(q + 1));
    cin >> a[0] >> c[0];
    for(int i = 1, t; i <= q; i += 1){
        cin >> t;
        if(t == 1){
            cin >> f[0][i] >> a[i] >> c[i];
            for(int j = 1; j < 20; j += 1)
                f[j][i] = f[j - 1][f[j - 1][i]];
        }
        else{
            int v, w;
            cin >> v >> w;
            LL sa = 0, sc = 0;
            while(a[v] and w){
                int p = v;
                for(int j = 19; j >= 0; j -= 1) if(a[f[j][p]]) p = f[j][p];
                LL h = min(a[p], w);
                a[p] -= h;
                w -= h;
                sa += h;
                sc += h * c[p];
            }
            cout << sa << " " << sc << endl;
        }
    }
    return 0;
}