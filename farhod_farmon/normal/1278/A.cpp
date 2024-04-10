#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const int mod = 1e9 + 7;

using namespace std;

int c[200];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                string s, t;
                cin >> s >> t;
                bool res = false;
                for(int i = 0; i + s.size() - 1 < t.size(); i++){
                        for(int j = 'a'; j <= 'z'; j++){
                                c[j] = 0;
                        }
                        for(int j = 0; j < s.size(); j++){
                                c[t[i + j]] += 1;
                        }
                        bool good = true;
                        for(char x: s){
                                if(c[x] == 0){
                                        good = false;
                                        break;
                                }
                                c[x] -= 1;
                        }
                        if(good){
                                res = true;
                        }
                }
                cout << (res ? "YES" : "NO") << "\n";
        }
}