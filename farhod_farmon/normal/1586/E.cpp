#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int n, m;
int dip[N];
int par[N];
bool used[N];
vector<int> v[N];
int a[N], b[N], c[N];

void dfs(int x)
{
        used[x] = true;
        for(int y : v[x]){
                if(used[y]){
                        continue;
                }
                dip[y] = dip[x] + 1;
                par[y] = x;
                dfs(y);
        }
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        dfs(1);
        int q;
        cin >> q;
        for(int i = 1; i <= q; i++){
                cin >> a[i] >> b[i];
                c[a[i]] ^= 1;
                c[b[i]] ^= 1;
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
                cnt += c[i];
        }
        if(cnt){
                cout << "NO\n";
                cout << cnt / 2 << "\n";
                return 0;
        }
        cout << "YES\n";
        for(int i = 1; i <= q; i++){
                vector<int> A, B;
                int x = a[i], y = b[i];
                while(x != y){
                        if(dip[x] > dip[y]){
                                A.push_back(x);
                                x = par[x];
                        } else{
                                B.push_back(y);
                                y = par[y];
                        }
                }
                cout << A.size() + B.size() + 1 << "\n";
                for(int z : A) cout << z << " ";
                cout << x << " ";
                reverse(B.begin(), B.end());
                for(int z : B) cout << z << " ";
                cout << "\n";
        }
}