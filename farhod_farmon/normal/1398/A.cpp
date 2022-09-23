#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int Q = N * 50;

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
                for(int i = 0; i < n; i++) cin >> a[i];
                if(a[0] + a[1] <= a[n - 1]){
                        cout << "1 2 " << n << "\n";
                } else{
                        cout << -1 << "\n";
                }
        }
}