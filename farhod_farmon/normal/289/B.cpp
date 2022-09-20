#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n, m, d;
        cin >> n >> m >> d;
        vector < int > a(n * m);

        for(int i = 0; i < n * m; i++){
                cin >> a[i];
        }

        int md = a[0] % d;

        for(int i = 0; i < n * m; i++){
                if(a[i] % d != md){
                        cout << -1 << "\n";
                        return 0;
                }

                a[i] /= d;
        }

        int res = 1e9;
        for(int x = 1; x <= 10000; x++){
                int cnt = 0;
                for(int y: a){
                        cnt += abs(x - y);
                }
                res = min(res, cnt);
        }

        cout << res << "\n";
}