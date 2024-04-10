#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const long long mod = 998244353;

using namespace std;

int n;
char c[N];
char f[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> c[i];
        }
        for(int i = '1'; i <= '9'; i++){
                cin >> f[i];
        }
        int op = 0;
        for(int i = 1; i <= n; i++){
                if(f[c[i]] > c[i]){
                        op = 1;
                        c[i] = f[c[i]];
                } else if(f[c[i]] < c[i]){
                        if(op == 1){
                                break;
                        }
                }
        }

        for(int i = 1; i <= n; i++){
                cout << c[i];
        }
        cout << "\n";
}