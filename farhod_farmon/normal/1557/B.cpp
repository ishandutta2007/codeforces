#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 110;
const int mod = 1e9 + 7;

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
                int n, k;
                cin >> n >> k;
                vector<int> a(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                }
                auto b = a;
                sort(b.begin(), b.end());
                set<pair<int, int>> s;
                for(int i = 1; i < n; i++){
                        s.insert({b[i - 1], b[i]});
                }
                int res = 1;
                for(int i = 1; i < n; i++){
                        res += (s.find({a[i - 1], a[i]}) == s.end());
                }
                cout << (res <= k ? "YES" : "NO") << "\n";
        }
}