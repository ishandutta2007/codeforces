#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                string s, t;
                cin >> s >> t;
                int l = s.size() * t.size() / __gcd((int)s.size(), (int)t.size());
                string x = "", y = "";
                for(int i = 0; i < l / (int)s.size(); i++){
                        x += s;
                }
                for(int i = 0; i < l / (int)t.size(); i++){
                        y += t;
                }
                if(x == y){
                        cout << x << "\n";
                } else{
                        cout << -1 << "\n";
                }
        }
}