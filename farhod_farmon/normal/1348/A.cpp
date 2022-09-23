#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const int mod = 1e9 + 7;

using namespace std;


int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                long long res = (1 << n);
                for(int i = 1; i < n; i++){
                        if(i < n / 2){
                                res += (1 << i);
                        } else{
                                res -= (1 << i);
                        }
                }
                cout << res << "\n";
        }
}