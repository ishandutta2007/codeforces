#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n, p;
    cin >> n >> p;
    for(int i = 1; i <= 100000; i += 1){
        LL m = (n - i * p);
        if(m <= 0) break;
        if(m >= i and __builtin_popcountll(m) <= i){
            cout << i;
            return 0;
        }
    }
    cout << "-1";
    return 0;
}