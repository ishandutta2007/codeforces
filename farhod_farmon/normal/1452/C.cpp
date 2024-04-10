#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

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
                int res = 0, a = 0, b = 0;
                for(char c: s){
                        if(c == '('){
                                a += 1;
                        } else if(c == '['){
                                b += 1;
                        } else if(c == ')'){
                                if(a > 0){
                                        a -= 1;
                                        res += 1;
                                }
                        } else{
                                if(b > 0){
                                        b -= 1;
                                        res += 1;
                                }
                        }
                }
                cout << res << "\n";
        }
}