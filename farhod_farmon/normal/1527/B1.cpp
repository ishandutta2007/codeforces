#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 50000;
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
                int n;
                cin >> n;
                string s;
                cin >> s;
                string t = s;
                reverse(t.begin(), t.end());
                int cnt = 0;
                for(int i = 0; i < t.size(); i++){
                        cnt += (s[i] == '0');
                }
                if(s == t){
                        if(cnt % 2 == 0 || cnt == 1){
                                cout << "BOB" << "\n";
                        } else{
                                cout << "ALICE" << "\n";
                        }
                }
        }
}