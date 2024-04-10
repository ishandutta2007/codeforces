#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 31607;

using namespace std;

string s, t;

bool solve(string s, string t, int i)
{
        int j = 0;
        while(i < s.size() && j < t.size()){
                if(s[i] == t[j]){
                        j += 1;
                } else{
                        i += 1;
                }
                i += 1;
        }
        if(i > s.size() || j != t.size() || (s.size() - i) % 2){
                return false;
        }
        return true;
}

void solve()
{
        cin >> s >> t;

        if(solve(s, t, 0) || solve(s, t, 1)){
                cout << "yes\n";
        } else{
                cout << "no\n";
        }

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