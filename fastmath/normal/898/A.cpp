#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 7;

signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cout.precision(40);
    int n;
    cin >> n;
    if (n % 10 <= 5){
        cout << n - (n % 10);
    }
    else{
        cout << n + 10 - (n % 10);
    }

    return 0;
}