#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 65010;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(false);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < int > a(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                }
                sort(a.begin(), a.end());
                int res = 0;
                for(int i = 0; i < n; i++){
                        if(a[i] <= i + 1){
                                res = i + 1;
                        }
                }
                cout << res + 1 << "\n";
        }
}