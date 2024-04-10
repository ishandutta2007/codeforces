#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000 + 1;
int a[maxn], v[maxn], m[maxn];
int mex(int n){
    for(int i = 0; i <= n; i += 1) v[i] = 0;
    for(int i = 1; i <= n; i += 1) v[a[i]] = 1;
    int k = 0;
    while(v[k]) k += 1;
    return k;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, n;
    for(cin >> t; t; t -= 1){
        cin >> n;
        vector<int> x;
        for(int i = 1; i <= n; i += 1) cin >> a[i];
        while(true){
            int k = mex(n), f = k;
            if(not f) for(int j = 1; j <= n; j += 1) if(a[j] != j) f = j;
            if(not f) break;
            a[f] = k;
            x.push_back(f);
        }
        assert(x.size() <= 2 * n);
        cout << x.size() << "\n";
        for(int k : x) cout << k << " ";
        cout << "\n";
    }
    return 0;
}