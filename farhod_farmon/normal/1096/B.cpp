#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 998244353;

using namespace std;

int n;
char c[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> c[i];
        }
        int s = 0;
        int p = 0;
        while(s < n && c[n - s] == c[n]){
                s += 1;
        }
        while(p < n && c[p + 1] == c[1]){
                p += 1;
        }
        int res = s + 1;
        for(int i = 2; i <= n; i++){
                if(c[i - 1] != c[n]){
                        break;
                }
                res += min(s, n - i) + 1;
                if(res >= mod){
                        res -= mod;
                }
        }
        if(c[1] != c[n]){
                res += p;
        }
        cout << res << "\n";
}