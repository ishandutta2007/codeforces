#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 100100;
const int mod = 998244353;

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n, m;
                string s, t;
                cin >> n >> m >> s;
                m = min(m, n);
                for(int i = 0; i < m; i++){
                        t = s;
                        for(int j = 0; j < n; j++){
                                if(s[j] == '0' && (j == 0 ? '0' : s[j - 1]) + (j + 1 == n ? '0' : s[j + 1]) == '0' + '1'){
                                        t[j] = '1';
                                }
                        }
                        s = t;
                }
                cout << s << "\n";
        }
}