#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 7;

signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cout.precision(40);
    int counter1 = 0, counter2 = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        if (x < 0){
            counter1++;
        }
        else{
            counter2++;
        }
    }

    if (counter1 <= 1 || counter2 <= 1){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }

    return 0;
}