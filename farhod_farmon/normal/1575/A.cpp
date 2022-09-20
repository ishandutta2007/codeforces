#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

#define fi first
#define se second

const int N = 104;

using namespace std;

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);


        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        vector<string> a(n);
        for(int i = 0; i < n; i++){
                cin >> a[i];
                for(int j = 1; j < m; j += 2){
                        a[i][j] = 'A' + ('Z' - a[i][j]);
                }
                v[i] = i;
        }
        sort(v.begin(), v.end(), [&](int i, int j){
                return a[i] < a[j];
        });
        for(int i : v){
                cout << i + 1 << " ";
        }
}