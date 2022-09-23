#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 9;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        string s;
        cin >> s;
        for(int i = 1; i <= 5; i++){
                string t;
                cin >> t;
                if(s[0] == t[0] || s[1] == t[1]){
                        cout << "YES" << "\n";
                        return 0;
                }
        }
        cout << "NO" << "\n";
}