#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100;
int x[maxn], y[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, k;
        cin >> n >> k;
        for(int i = 0; i < n; i += 1) cin >> x[i] >> y[i];
        int ok = -1;
        for(int i = 0; i < n and ok == -1; i += 1){
            int d = 0;
            for(int j = 0; j < n; j += 1) d = max(d, abs(x[i] - x[j]) + abs(y[i] - y[j]));
            if(d <= k) ok = 1;
        }
        cout << ok << "\n";
    }
    return 0;
}