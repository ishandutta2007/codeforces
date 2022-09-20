#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 998244353;

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
                if(s.size() % 2 || s[0] == ')' || s.back() == '('){
                        cout << "No" << "\n";
                } else{
                        cout << "Yes" << "\n";
                }
        }
}