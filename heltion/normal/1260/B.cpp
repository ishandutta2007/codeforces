#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1){
        LL a, b;
        cin >> a >> b;
        //2 * x + y == a, 2 * y + x == b
        LL xplusy = (a + b) / 3;
        if((a + b) % 3 or a < xplusy or b < xplusy) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}