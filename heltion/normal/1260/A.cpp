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
        LL c, sum;
        cin >> c >> sum;
        LL a = sum / c;
        cout << a * a * (c - sum % c) + (a + 1) * (a + 1) * (sum % c) <<"\n";
    }
    return 0;
}