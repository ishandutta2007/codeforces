#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000;
int a[maxn], b[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 0; i < n; i += 1) cin >> a[i];
        for(int i = 0; i < n; i += 1) cin >> b[i];
        bool ok = true;
        for(int i = 0, x = 0, y = 0; i < n; i += 1){
            if(b[i] > a[i] and not x) ok = false;
            if(b[i] < a[i] and not y) ok = false;
            if(a[i] == 1) x = 1;
            if(a[i] == -1) y = 1;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}