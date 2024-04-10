#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL t, a, b, n, m;
    for(cin >> t; t; t -= 1){
        cin >> a >> b >> n >> m;
        cout << (a + b >= n + m and min(a, b) >= m ? "Yes\n" : "No\n");
    }
    return 0;
}

//n <= r 1
//n > r r