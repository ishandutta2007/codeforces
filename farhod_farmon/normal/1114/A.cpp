#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100010;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int a, b, c, x, y, z;
        cin >> x >> y >> z >> a >> b >> c;
        a -= x;
        z -= c;
        z = max(z, 0);
        if(a >= 0 && y + z <= a + b){
                cout << "YES" << "\n";
        }
        else{
                cout << "NO" << "\n";
        }
}