#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;


int main() {
    int t;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        int d = abs(x - y);
        int i = 0;
        while(1LL * i * (i + 1) / 2 < d) ++i;
        LL dd = 1LL * i * (i + 1) / 2;
        if((dd - d) & 1) cout << i + 1 + (i & 1) << endl;
        else cout<<i<<endl;
    }

    return 0;
}