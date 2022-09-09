#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
int p[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        int ans = n + 1;
        for(int i = 1; i <= n; i += 1) p[i] = 0;
        for(int i = 1, a; i <= n; i += 1){
            cin >> a;
            if(p[a]) ans = min(ans, i - p[a] + 1);
            p[a] = i;
        }
        cout << (ans <= n ? ans : -1) << "\n";
    }
    return 0;
}