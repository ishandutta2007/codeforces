#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 110;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int q;
        cin >> q;
        while(q--){
                int n;
                cin >> n;
                vector < int > v(3, 0);
                for(int i = 1; i <= n; i++){
                        int x;
                        cin >> x;
                        v[x % 3] += 1;
                }
                int g = min(v[1], v[2]);
                int res = v[0] + g;
                res += (v[1] - g) / 3;
                res += (v[2] - g) / 3;
                cout << res << "\n";
        }
}