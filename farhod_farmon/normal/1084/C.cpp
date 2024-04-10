#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 50005;

using namespace std;

string s;

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> s;
        vector < int > a = {0};
        for(char c: s){
                if(c == 'b'){
                        a.push_back(0);
                } else if(c == 'a'){
                        a.back() += 1;
                }
        }

        int mod = 1e9 + 7;
        int res = 1;
        for(int x: a){
                res = 1ll * res * (x + 1) % mod;
        }

        cout << (res + mod - 1) % mod << "\n";
}