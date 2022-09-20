#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 1000011;
const int mod = 998244353;

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        string res = "blue";
        for(int i = 0, op = 1; i < n; i++){
                string s;
                cin >> s;
                if(s == "unlock"){
                        op = 1;
                } else if(s == "lock"){
                        op = 0;
                } else if(op){
                        res = s;
                }
        }
        cout << res << "\n";
}