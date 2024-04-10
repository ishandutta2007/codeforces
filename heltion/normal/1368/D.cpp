#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
LL c[20];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(LL i = 0, a; i < n; i += 1){
        cin >> a;
        for(int j = 0; j < 20; j += 1)
            c[j] += (a >> j) & 1;
    }
    LL ans = 0;
    for(int i = 0; i < n; i += 1){
        LL a = 0;
        for(int j = 0; j < 20; j += 1) if(c[j]){
            c[j] -= 1;
            a |= 1 << j;
        }
        ans += a * a;
    }
    cout << ans;
    return 0;
}