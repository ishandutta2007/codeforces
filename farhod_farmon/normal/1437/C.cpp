#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < int > a(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                        a[i] -= 1;
                }
                sort(a.begin(), a.end());
                int inf = 1e9;
                vector < vector < int > > d(n, vector < int > (2 * n, inf));
                for(int i = 0; i < 2 * n; i++){
                        d[0][i] = abs(a[0] - i);
                        if(i > 0){
                                d[0][i] = min(d[0][i], d[0][i - 1]);
                        }
                }
                for(int i = 1; i < n; i++){
                        for(int j = i; j < 2 * n; j++){
                                d[i][j] = d[i - 1][j - 1] + abs(a[i] - j);
                                d[i][j] = min(d[i][j], d[i][j - 1]);
                        }
                }
                cout << d[n - 1][2 * n - 1] << "\n";
        }
}