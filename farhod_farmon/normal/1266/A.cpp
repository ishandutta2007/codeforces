#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400400;
const int mod = 1e9 + 7;

using namespace std;


int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                string s;
                cin >> s;
                int res = 0, gg = 0, cnt = 0;
                for(char c: s){
                        if(c == '0'){
                                gg = 1;
                        }
                        res = (res + c - '0') % 3;
                        cnt += ((c - '0') % 2 == 0);
                }
                if(res == 0 && gg && cnt > 1){
                        cout << "red" << "\n";
                } else{
                        cout << "cyan" << "\n";
                }
        }
}