#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int c[N];
vector<int> v[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                v[i].clear();
                c[i] = 0;
        }
        set<int> S;
        for(int i = 1; i <= n; i++){
                int k;
                cin >> k;
                for(int j = 0; j < k; j++){
                        int x;
                        cin >> x;
                        v[x].push_back(i);
                }
                c[i] = k;
                if(!c[i]){
                        S.insert(i);
                }
        }
        int cur = 0, res = 1;
        while(!S.empty()){
                auto x = S.lower_bound(cur);
                if(x == S.end()){
                        x = S.begin();
                        res += 1;
                }
                int shit = *x;
                cur = shit;
                for(int y: v[shit]){
                        c[y] -= 1;
                        if(!c[y]){
                                S.insert(y);
                        }
                }
                S.erase(shit);
        }
        for(int i = 1; i <= n; i++){
                if(c[i]){
                        res = -1;
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