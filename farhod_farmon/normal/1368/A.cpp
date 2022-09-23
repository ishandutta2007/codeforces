#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200100;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                long long a, b, c;
                cin >> a >> b >> c;
                int res = 0;
                while(max(a, b) <= c){
                        if(a > b){
                                b += a;
                        } else{
                                a += b;
                        }
                        res += 1;
                }
                cout << res << "\n";
        }
}