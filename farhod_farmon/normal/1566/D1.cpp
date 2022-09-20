#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 303;

using namespace std;

int n;
int m;
int a[N];
int b[N];

void solve()
{
        cin >> n >> m;
        vector<int> v;
        for(int i = 1; i <= m; i++){
                cin >> a[i];
                v.push_back(i);
        }
        sort(v.begin(), v.end(), [&](int i, int j){
                if(a[i] != a[j]){
                        return a[i] < a[j];
                }
                return i > j;
             });
        int res = 0;
        for(int i = 0; i < m; i++){
                for(int j = i + 1; j < m; j++){
                        res += (v[i] < v[j]);
                }
        }
        cout << res << "\n";
}

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
                solve();
        }
}