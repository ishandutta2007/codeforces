#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;

using namespace std;


int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n, m;
                cin >> n >> m;
                vector < vector < int > > a(n, vector < int > (m));
                for(int i = 0; i < n; i++){
                        for(int j = 0; j < m; j++){
                                cin >> a[i][j];
                        }
                }
                long long res = 0;
                for(int i = 0; i < (n + 1) / 2; i++){
                        for(int j = 0; j < (m + 1) / 2; j++){
                                vector < int > cur, X, Y;
                                X.push_back(i);
                                Y.push_back(j);
                                if(i < n - i - 1){
                                        X.push_back(n - i - 1);
                                }
                                if(j < m - j - 1){
                                        Y.push_back(m - j - 1);
                                }
                                for(int x: X){
                                        for(int y: Y){
                                                cur.push_back(a[x][y]);
                                        }
                                }

                                sort(cur.begin(), cur.end());
                                int need = cur.size() / 2;
                                for(int x: cur){
                                        res += abs(cur[need] - x);
                                }
                        }
                }
                cout << res << "\n";
        }
}