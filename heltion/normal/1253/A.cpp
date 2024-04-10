#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int& x : a) cin >> x;
        for(int& x : b) cin >> x;
        int ok = 1, L = 0, R = n - 1;
        while(L < n and a[L] == b[L]) L += 1;
        while(~R and a[R] == b[R]) R -= 1;
        if(L <= R) for(int i = L; i <= R; i += 1){
            if(a[i] > b[i]) ok = 0;
            if(b[i] - a[i] != b[L] - a[L]) ok = 0;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}