#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 150;

using namespace std;

int a[N][N];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                for(int i = 0; i < 26; i++){
                        for(int j = 0; j < 26; j++){
                                a[i][j] = 0;
                        }
                }
                int n;
                cin >> n;
                string s, t;
                cin >> s >> t;
                int res = 0;
                for(int i = 0; i < n; i++){
                        int x = s[i] - 'a';
                        int y = t[i] - 'a';
                        if(x > y){
                                res = -1;
                        } else if(x < y){
                                a[x][y] = 1;
                        }
                }
                if(res == -1){
                        cout << -1 << "\n";
                        continue;
                }
                for(int i = 0; i < 26; i++){
                        int h = 0;
                        while(h < 26 && !a[i][h]) h += 1;
                        if(h == 26) continue;
                        res += 1;
                        a[i][h] = 0;
                        for(int j = 0; j < 26; j++){
                                a[h][j] |= a[i][j];
                        }
                }
                cout << res << "\n";
        }
}