#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

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
                int n;
                string s;
                cin >> n >> s;
                int l = -1, r = -1;
                for(int i = 0; i + 1 < n; i++){
                        if(s[i] != s[i + 1]){
                                l = i + 1;
                                r = i + 2;
                        }
                }
                cout << l << " " << r << "\n";
        }
}