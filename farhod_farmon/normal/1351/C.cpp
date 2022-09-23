#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

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
                int x = 0, y = 0;
                int res = s.size();
                set < pair < pair < int, int >, pair < int, int > > > S;
                for(char c: s){
                        int dx = 0, dy = 0;
                        if(c == 'N') dx = -1;
                        if(c == 'E') dy = 1;
                        if(c == 'S') dx = 1;
                        if(c == 'W') dy = -1;

                        if(S.find({{x, y}, {dx, dy}}) == S.end()){
                                res += 4;
                        }
                        int nx = x + dx;
                        int ny = y + dy;
                        S.insert({{x, y}, {dx, dy}});
                        S.insert({{nx, ny}, {-dx, -dy}});
                        x = nx;
                        y = ny;
                }
                cout << res << "\n";
        }
}