#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400200;

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
                int n, m;
                cin >> n >> m;
                vector<int> ban(n + 1, 0);
                for(int i = 1; i <= m; i++){
                        int x, y, z;
                        cin >> x >> y >> z;
                        ban[y] = true;
                }
                int root;
                for(int i = 1; i <= n; i++){
                        if(!ban[i]){
                                root = i;
                        }
                }
                for(int i = 1; i <= n; i++) if(i != root){
                        cout << root << " " << i << "\n";
                }
        }
}