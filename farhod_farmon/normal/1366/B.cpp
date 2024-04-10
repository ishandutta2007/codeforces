#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const int mod = 1e9 + 7;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n, x, m;
                cin >> n >> x >> m;
                int l = x, r = x;
                for(int i = 1; i <= m; i++){
                        int a, b;
                        cin >> a >> b;
                        if(max(l, a) <= min(b, r)){
                                l = min(l, a);
                                r = max(r, b);
                        }
                }
                cout << r - l + 1 << "\n";
        }
}