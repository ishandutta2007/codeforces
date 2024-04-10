#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 110;

using namespace std;

int n;
char c[N];
string need = "ACTG";

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> c[i];
        }
        int res = 1e9;
        for(int i = 1; i + 3 <= n; i++){
                int cnt = 0;
                for(int j = 0; j < 4; j++){
                        int x = c[i + j] - need[j];
                        int y = need[j] - c[i + j];
                        if(x < 0){
                                x += 26;
                        }
                        if(y < 0){
                                y += 26;
                        }
                        cnt += min(x, y);
                }
                res = min(res, cnt);
        }
        cout << res << "\n";
}