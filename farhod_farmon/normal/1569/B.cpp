#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;


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
                int n;
                string s;
                cin >> n >> s;
                vector<vector<char>> res(n, vector<char> (n, '='));
                int rem = n;
                for(int i = 0; i < n; i++){
                        res[i][i] = 'X';
                        if(s[i] == '1'){
                                rem -= 1;
                        }
                }
                if(rem == 1 || rem == 2){
                        cout << "NO\n";
                        continue;
                }
                cout << "YES\n";
                for(int i = 0; i < n; i++){
                        if(s[i] == '2'){
                                int j = (i + 1) % n;
                                while(s[j] != '2'){
                                        j = (j + 1) % n;
                                }
                                res[i][j] = '+';
                                res[j][i] = '-';
                        }
                }
                for(int i = 0; i < n; i++){
                        for(int j = 0; j < n; j++){
                                cout << res[i][j];
                        }
                        cout << "\n";
                }
        }
}