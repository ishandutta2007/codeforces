#include<bits/stdc++.h>
using namespace std;
using namespace std;
constexpr int maxn = 100000 + 1;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, u, v;
        cin >> n >> u >> v;
        for(int i = 1; i <= n; i += 1) cin >> a[i];
        int ok = 0;
        for(int i = 1; i < n; i += 1) if(abs(a[i] - a[i + 1]) >= 2) ok = 1;
        if(ok){
            cout << "0\n";
            continue;
        }
        int same = 1;
        for(int i = 1; i < n; i += 1) same = same and a[i] == a[i + 1];
        if(same) cout << v + min(u, v) << "\n";
        else cout << min(u, v) << "\n";
    }
    return 0;
}