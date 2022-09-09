#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int n, m, ok;
vector<int> aa;
int sum[1 << 15], mk[15];
int LG[15];
void DFS(int i, int d){
    if(i == n){
        ok = 1;
        for(int j = 0; j < n; j += 1) LG[j] = mk[j];
        LG[n - 1] |= d;
    }
    if(ok) return;
    if(aa[i] > aa[i - 1]){
        mk[i] = 0;
        DFS(i + 1, d);
        if(ok) return;
    }
    for(int k = d; k; k = d & (k - 1))
        if(aa[i] + sum[k] > aa[i - 1]){
            aa[i] += sum[k];
            mk[i] = k;
            DFS(i + 1, d ^ k);
            if(ok) return;
            aa[i] -= sum[k];
        }
}
bool check(vector<int> &a, vector<int>& d){
    aa.assign(a.begin(), a.end());
    n = a.size(), m = d.size();
    ok = 0;
    for(int i = 0; i < (1 << m); i += 1){
        sum[i] = 0;
        for(int j = 0; j < m; j += 1) if((i >> j) & 1) sum[i] += d[j];
    }
    DFS(1, (1 << m) - 1);
    return ok;
}
void f(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i += 1) cin >> a[i];
    for(int i = 0; i < n; i += 1)
        for(int j = 0; j < (1 << n); j += 1)
            if(__builtin_popcount(j) == i){
                vector<int> u[2], v[2];
                for(int k = 0; k < n; k += 1){
                    u[(j >> k) & 1].push_back(a[k]);
                    v[(j >> k) & 1].push_back(k + 1);
                }
                if(check(u[0], u[1])){
                    cout << i << "\n";
                    int ck = 0;
                    for(int x = 0; x < (int)v[0].size(); x += 1)
                        for(int y = 0; y < (int)v[1].size(); y += 1)
                            if((LG[x] >> y) & 1){
                                cout << v[1][y] << " " << v[0][x] << "\n";
                                ck += 1;
                                int p = v[1][y];
                                for(int &q : v[0]) if(q > p) q -= 1;
                                for(int &q : v[1]) if(q > p) q -= 1;
                            }
                    assert(ck == i);
                    return;
                }
            }
    assert(0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1) f();
    return 0;
}