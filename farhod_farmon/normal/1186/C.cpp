#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 111;
const long long mod = 998244353;

using namespace std;

string s, t;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> s >> t;
        int res = 0, f = 0;
        for(int i = 0; i < t.size(); i++){
                f ^= t[i] - '0';
                f ^= s[i] - '0';
        }
        for(int i = 0; i <= (int)s.size() - t.size(); i++){
                res += f == 0;
                f ^= s[i] - '0';
                if(i + (int)t.size() < (int)s.size()){
                        f ^= s[i + t.size()] - '0';
                }
        }
        cout << res << "\n";
}