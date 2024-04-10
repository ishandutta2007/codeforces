#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000000 + 1;
LL k[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    LL pre = 0, kpre = 0, sum = 0;
    for(int i = 1; i <= n; i += 1){
        cin >> k[i];
        sum += k[i];
    }
    for(LL i = 1; i <= n; i += 1){
        kpre += k[i];
        LL MIN = (sum - pre - (n - i + 1) * (n - i) / 2 + n - i) / (n - i + 1);
        cout << (k[i] = max(MIN, kpre - pre)) << " ";
        pre += k[i];
    }
    return 0;
}