#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    ++n;

    if (n == 1) cout << "0\n";
    else if (n % 2 == 0) cout << n / 2 << '\n';
    else cout << n << '\n';
    
    return 0;
}