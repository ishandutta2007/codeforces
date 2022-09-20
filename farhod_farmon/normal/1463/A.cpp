#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int a, b, c;
                cin >> a >> b >> c;
                int need = a + b + c - 3;
                int l = 0, r = need;
                while(l < r){
                        int m = (l + r) / 2;
                        if(m + (m / 7) * 2 < need){
                                l = m + 1;
                        } else{
                                r = m;
                        }
                }
                if(l + (l / 7) * 2 == need && l % 7 == 6 && l / 7 < min(a, min(b, c))){
                        cout << "YES" << "\n";
                } else{
                        cout << "NO" << "\n";
                }
        }
}