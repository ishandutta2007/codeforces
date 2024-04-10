#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if(n == 2) cout << "1\n1";
    else{
        LL ans = 1;
        vector<int> v;
        for(int i = 1; i <= n; i += 1)
            if(gcd(n, i) == 1){
                v.push_back(i);
                ans = ans * i % n;
            }
        if(ans == n - 1) v.pop_back();
        cout << v.size() << "\n";
        for(int x : v) cout << x << " ";
    }
    return 0;
}