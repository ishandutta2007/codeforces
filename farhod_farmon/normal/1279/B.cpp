#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 1010;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                int n, s;
                cin >> n >> s;
                int res = 0, sum = 0;
                pair < int, int > p = {-1, -1};
                for(int i = 1; i <= n; i++){
                        int x;
                        cin >> x;
                        sum += x;
                        if(x > p.fi){
                                p = {x, i};
                        }
                        if(sum > s && !res){
                                res = p.se;
                        }
                }
                cout << res << "\n";
        }
}