#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 303;
const int mod = 1e9 + 7;

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
                vector < int > res;
                for(int i = 0; i + 2 < s.size(); i++){
                        if(i + 4 < s.size() && s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o' && s[i + 3] == 'n' && s[i + 4] == 'e'){
                                res.push_back(i + 3);
                                s[i + 2] = '#';
                        } else if(s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e'){
                                res.push_back(i + 2);
                        } else if(s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o'){
                                res.push_back(i + 2);
                                s[i + 2] = '#';
                        }
                }
                cout << res.size() << "\n";
                for(int x: res){
                        cout << x << " ";
                }
                cout << "\n";
        }
}