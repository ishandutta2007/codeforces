#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int Q = 1000100;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                string s;
                cin >> s;
                int res = 0;
                s = "##" + s;
                for(int i = 2; i < s.size(); i++){
                        bool bad = false;
                        if(s[i - 1] != '#' && s[i] == s[i - 1]){
                                bad = true;
                        }
                        if(s[i - 2] != '#' && s[i] == s[i - 2]){
                                bad = true;
                        }
                        if(bad){
                                res += 1;
                                s[i] = '#';
                        }
                }
                cout << res << "\n";
        }
}