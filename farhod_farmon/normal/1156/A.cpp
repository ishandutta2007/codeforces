#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 5050;
const long long mod = 998244353;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int d[4][4];

        d[1][1] = d[2][2] = d[3][3] = 1e5;

        d[2][1] = 3;
        d[2][3] = 1e5;
        d[1][2] = 3;
        d[1][3] = 4;
        d[3][1] = 4;
        d[3][2] = 1e5;

        int n;
        cin >> n;
        vector < int > a(n);

        int res = 0;
        for(int i = 0; i < n; i++){
                cin >> a[i];
                if(i > 0){
                        res += d[a[i - 1]][a[i]];
                }
                if(i > 1){
                        res -= (a[i - 2] == 3 && a[i - 1] == 1 && a[i] == 2);
                }
        }

        if(res > 1e4){
                cout << "Infinite" << "\n";
        } else{
                cout << "Finite" << "\n";
                cout << res << "\n";
        }
}