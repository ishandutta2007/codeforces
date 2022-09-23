#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n;
                long long mx = 0, s = 0;
                cin >> n;
                for(int i = 1; i <= n; i++){
                        long long x;
                        cin >> x;
                        mx = max(mx, x);
                        s += x;
                }
                s -= mx;
                long long res = 0;
                if(mx * (n - 2) > s){
                        res += mx * (n - 2) - s;
                        s = mx * (n - 2);
                }
                s += mx;
                if(s % (n - 1)){
                        res += (n - 1) - s % (n - 1);
                }
                cout << res << "\n";
        }
}