#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 200200;
const int block = 444;

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
                sort(s.begin(), s.end());
                if(s[0] == s[s.size() - 1]){
                        cout << -1 << "\n";
                }
                else{
                        cout << s << "\n";
                }
        }
}