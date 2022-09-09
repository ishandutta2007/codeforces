#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        if((a + b + c + n) % 3) cout << "NO\n";
        else{
            int x = (a + b + c + n) / 3;
            if(a > x or b > x or c > x) cout << "NO\n";
            else cout << "YES\n";
        }
    }
    return 0;
}