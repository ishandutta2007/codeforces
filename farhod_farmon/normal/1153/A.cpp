#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int n;
int t;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> t;
        vector < pair < int, int > > res;
        for(int i = 1; i <= n; i++){
                int x, y;
                cin >> x >> y;
                while(x < t){
                        x += y;
                }
                res.push_back({x, i});
        }
        sort(res.begin(), res.end());
        cout << res[0].se << "\n";
}