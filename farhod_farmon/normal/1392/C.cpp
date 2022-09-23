#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 3000010;
const long long mod = 1e9 + 7;

using namespace std;


int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < int > a(n);
                long long res = 0;
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                        if(i > 0 && a[i - 1] > a[i]){
                                res += a[i - 1] - a[i];
                        }
                }
                cout << res << "\n";
        }
}