#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int q;
    for(cin >> q; q; q -= 1){
        int a, b, n, S;
        cin >> a >> b >> n >> S;
        cout << (S - min(S / n, a) * n <= b ? "YES\n" : "NO\n"); 
    }
    return 0;
}