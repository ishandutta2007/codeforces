#include "bits/stdc++.h"

#define fi first
#define se second

const int N = 100100;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> c(101, 0);
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            c[abs(x)] += 1;
        }
        int res = (c[0] > 0);
        for(int i = 1; i <= 100; i++){
            res += min(c[i], 2);
        }
        cout << res << "\n";
    }
}