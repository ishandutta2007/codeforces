#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 550;
const int mod = 31607;

using namespace std;

int solve(string s)
{
        int bal = 0;
        for(int i = 0, A = 5, B = 5; i < 10; i++){
                if(i % 2 == 0){
                        bal += s[i] - '0';
                        A -= 1;
                } else{
                        bal -= s[i] - '0';
                        B -= 1;
                }
                if(bal - B > 0 || bal + A < 0){
                        return i + 1;
                }
        }
        return 10;
}

void solve()
{
        string s;
        cin >> s;
        string t = s;

        for(int i = 0; i < 10; i++){
                if(s[i] == '?'){
                        if(i % 2){
                                s[i] = '1';
                                t[i] = '0';
                        } else{
                                s[i] = '0';
                                t[i] = '1';
                        }
                }
        }

        cout << min(solve(s), solve(t)) << "\n";
}

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
                solve();
        }
}