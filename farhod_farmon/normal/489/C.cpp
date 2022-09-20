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

        int m, s;
        cin >> m >> s;

        if(s == 0){
                if(m == 1){
                        cout << 0 << " " << 0 << "\n";
                } else{
                        cout << -1 << " " << -1 << "\n";
                }
                return 0;
        }
        // [1, 9 * m]
        if(s > 9 * m){
                cout << -1 << " " << -1 << "\n";
                return 0;
        }

        vector < int > A(m, 0), B(m, 0);

        A[0] = 1;
        int s_ = s - 1;
        for(int i = m - 1; i >= 0; i--){
                A[i] += min(9, s_);
                s_ -= min(9, s_);
        }

        s_ = s;
        for(int i = 0; i < m; i++){
                B[i] += min(9, s_);
                s_ -= min(9, s_);
        }

        for(int x: A) cout << x;
        cout << " ";
        for(int x: B) cout << x;
        cout << "\n";
}