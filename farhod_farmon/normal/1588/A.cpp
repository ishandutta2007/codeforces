#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector<int> a(n), b(n);
                for(int i = 0; i < n; i++) cin >> a[i];
                for(int i = 0; i < n; i++) cin >> b[i];
                sort(a.begin(), a.end());
                sort(b.begin(), b.end());
                int res = 1;
                for(int i = 0; i < n; i++){
                        res &= (a[i] <= b[i] && a[i] + 1 >= b[i]);
                }
                cout << (res ? "YES" : "NO") << "\n";
        }
}