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
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for(int &a : v) cin >> a;
        if(x == n){
            int sum = 0;
            for(int a : v) sum += a;
            cout << (sum % 2 ? "Yes\n" : "No\n");
        }
        else{
            int odd = 0, even = 0;
            for(int a : v) (a % 2 ? odd : even) += 1;
            cout << ((odd and even) or (odd and (x & 1)) ? "Yes\n" : "No\n");
        }
    }
    return 0;
}