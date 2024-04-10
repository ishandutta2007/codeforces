#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000100;
const long long mod = 998244353;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                int n;
                cin >> n;
                vector < int > a(n);
                int x = -1, y;
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                        if(i > 0 && abs(a[i] - a[i - 1]) > 1){
                                x = i;
                                y = i + 1;
                        }
                }
                if(x == -1){
                        cout << "NO" << "\n";
                } else{
                        cout << "YES" << "\n";
                        cout << x << " " << y << "\n";
                }
        }
}