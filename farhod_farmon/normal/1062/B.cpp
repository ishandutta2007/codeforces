#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 998244353;

using namespace std;

int n;

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        if(n == 1){
                cout << 1 << " " << 0 << "\n";
                return 0;
        }
        int ans = 1;
        int mx = 0, mn = 1e9;
        bool mul = false;
        for(int i = 2; i <= n; i++){
                int cnt = 0;
                while(n % i == 0){
                        cnt++;
                        n /= i;
                }
                if(cnt > 0){
                        ans *= i;
                        mx = max(mx, cnt);
                        mn = min(mn, cnt);
                }
        }
        if(mn < mx){
                mul = 1;
        }
        int l = 0;
        while(1 << l < mx){
                l++;
        }
        if(1 << l > mx){
                mul = 1;
        }
        cout << ans << " " << l + mul << "\n";
}