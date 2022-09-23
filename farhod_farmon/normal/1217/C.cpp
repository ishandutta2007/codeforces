#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int T;
        cin >> T;
        while(T--){
                string s;
                cin >> s;
                vector < int > v((int)s.size() + 1);
                v[(int)v.size() - 1] = (int)s.size();
                for(int i = (int)s.size() - 1; i >= 0; i--){
                        v[i] = v[i + 1];
                        if(s[i] == '1'){
                                v[i] = i;
                        }
                }
                int res = 0;
                for(int i = 0; i < (int)s.size(); i++){
                        int cur = 0;
                        for(int j = v[i]; j < (int)s.size() && cur < (int)1e6; j++){
                                cur = cur * 2 + s[j] - '0';
                                if(cur == j - i + 1){
                                        res += 1;
                                }
                        }
                }
                cout << res << "\n";
        }
}