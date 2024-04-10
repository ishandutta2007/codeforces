#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    for(cin >> T; T; T -= 1){
        int a, b, n, i;
        cin >> a >> b >> n;
        for(i = 1; i; i += 1){
            if(a > b) swap(a, b);
            a += b;
            if(a > n) break;
        }
        cout << i << "\n";
    }
    return 0;
}