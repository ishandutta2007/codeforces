#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400400;
const int mod = 1e9 + 7;

using namespace std;


int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int n, m, G = 0;
        cin >> n >> m;
        vector < int > a(n), b(m);
        if(n < m){
                for(int &x: a){
                        x = (++G);
                }
                for(int &x: b){
                        x = (++G);
                }
        } else{
                for(int &x: b){
                        x = (++G);
                }
                for(int &x: a){
                        x = (++G);
                }
        }
        if(n == 1 && m == 1){
                cout << 0 << "\n";
                return 0;
        }
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        cout << a[i] * b[j] << " \n"[j == m - 1];
                }
        }
}