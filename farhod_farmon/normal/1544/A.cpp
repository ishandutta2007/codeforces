#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 2020;
const int Q = 1000011;

using namespace std;

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
                string s;
                cin >> s;
                int res = 0;
                for(char c : s){
                        res = max(res, c - '0');
                }
                cout << res << "\n";
        }
}