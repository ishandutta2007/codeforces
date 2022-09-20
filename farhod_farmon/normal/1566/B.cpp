#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 7;

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
                int A = 0, B = 0;
                for(int i = 0; i < s.size(); i++){
                        if(s[i] == '0' && (i == 0 || s[i - 1] != '0')){
                                A += 1;
                        }
                }
                cout << min(A, 2) << "\n";
        }
}