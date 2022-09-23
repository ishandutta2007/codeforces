#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 330;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                string s;
                cin >> s;
                sort(s.begin(), s.end());
                if(s[0] == s[s.size() - 1]){
                        cout << s << "\n";
                } else{
                        int n = 2 * s.size();
                        for(int i = 0; i < n; i++){
                                cout << (i & 1);
                        }
                        cout << "\n";
                }
        }
}